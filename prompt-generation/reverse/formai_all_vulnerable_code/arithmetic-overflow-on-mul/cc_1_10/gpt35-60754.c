//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

#define MAXLINE 4096    /* max text line length */
#define MAXFLOW 10      /* max number of traffic flows */
#define SERV_PORT 60000 /* port */

/* Data structure to store flow information */
typedef struct 
{
    int flowID;
    int srcIP, dstIP;
    int srcPort, dstPort;
    int flowSize;   
    double startTime, endTime;
} FlowInfo;

/* Function to generate random IP address */
unsigned int getRandomIP()
{
   unsigned int ip;
   ip = rand() % 256;
   ip = (ip << 8) | (rand() % 256);
   ip = (ip << 8) | (rand() % 256);
   ip = (ip << 8) | (rand() % 256);
   return ip;
}

/* Function to generate random traffic flow */
void generateTraffic(FlowInfo* flows)
{
    int i;
    for (i = 0; i < MAXFLOW; i++)
    {
        flows[i].flowID = i + 1;
        flows[i].srcIP = getRandomIP();
        flows[i].dstIP = getRandomIP();
        flows[i].srcPort = rand() % 65536;
        flows[i].dstPort = rand() % 65536;
        flows[i].flowSize = rand() % 1000 + 1;   
        flows[i].startTime = (double) (rand() % 1000 + 1) / 1000;
    }
}

/* Function to send and receive data */
void sendData(char* host, int port, FlowInfo* flow)
{
    int sockfd, n, err;
    double rtt;
    socklen_t len;
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    struct timeval start, end;

    /* create socket */
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) 
    {
        printf("socket error: %s\n", strerror(errno));
        exit(1);
    }

    /* set timeout for receive operation */
    struct timeval tv;
    tv.tv_sec = 3;
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv,sizeof(tv)) < 0)
    {
        printf("setsockopt error: %s\n", strerror(errno));
        exit(1);
    }

    /* set server address */
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0)
    {
        printf("inet_pton error for %s\n", host);
        exit(1);
    }  

    /* encode flow information into packet */
    bzero(buf, MAXLINE);
    memcpy(buf, flow, sizeof(FlowInfo));

    /* measure round-trip time */
    if (gettimeofday(&start, NULL) < 0)
    {
        printf("gettimeofday error: %s\n", strerror(errno));
        exit(1);
    }

    /* send packet to server */
    if ( (n = sendto(sockfd, buf, sizeof(FlowInfo), 0, (struct sockaddr *) &servaddr, sizeof(servaddr))) < 0) 
    {
        printf("sendto error: %s\n", strerror(errno));
        exit(1);
    }

    /* receive response from server */
    bzero(&buf, MAXLINE);
    len = sizeof(servaddr);
    if ( (n = recvfrom(sockfd, buf, MAXLINE, 0, (struct sockaddr *) &servaddr, &len)) < 0) 
    {
        if (errno == EWOULDBLOCK)
        {
            printf("No response from server for flow: %d\n", flow->flowID);       
            return;
        }
        else
        {
            printf("recvfrom error: %s\n", strerror(errno));
            exit(1);
        }
    }

    /* measure round-trip time */
    if (gettimeofday(&end, NULL) < 0)
    {
        printf("gettimeofday error: %s\n", strerror(errno));
        exit(1);
    }
    rtt = (double) (end.tv_sec - start.tv_sec) * 1000 + (double) (end.tv_usec - start.tv_usec) / 1000;

    /* decode response packet */
    FlowInfo* res = (FlowInfo*) buf;
    flow->endTime = res->endTime;

    /* output result */
    printf("FlowID: %d, Src IP: %d, Dst IP: %d, Src Port: %d, Dst Port: %d, Flow Size: %d bytes, Start Time: %f ms, End Time: %f ms, RTT: %f ms\n", 
           flow->flowID, flow->srcIP, flow->dstIP, flow->srcPort, flow->dstPort, flow->flowSize, flow->startTime, flow->endTime, rtt);

    /* close socket */
    close(sockfd);
}

/* Signal handler for child process */
void sig_chld(int signo)
{
    pid_t pid;
    int stat;

    /* wait for all child processes to terminate */
    while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0)
        printf("child %d terminated\n", pid);
    return;
}

/* Main program */
int main(int argc, char **argv)
{
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;
    char buf[MAXLINE];
    int i, n;
    FlowInfo flows[MAXFLOW];

    /* initialize random seed */
    srand((unsigned int)time(NULL));

    /* generate traffic flows */
    generateTraffic(flows);

    /* create socket */
    listenfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(listenfd < 0) 
    {
        printf("socket error: %s\n", strerror(errno));
        exit(1);
    }

    /* bind server address */
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) 
    {
        printf("bind error: %s\n", strerror(errno));
        exit(1);
    } 

    /* register signal handler for child process */
    signal(SIGCHLD, sig_chld);

    /* continuously receive packets from clients */
    while (1) 
    {
        clilen = sizeof(cliaddr);
        if ( (n = recvfrom(listenfd, buf, MAXLINE, 0, (struct sockaddr *) &cliaddr, &clilen)) < 0) 
        {
            printf("recvfrom error: %s\n", strerror(errno));
            exit(1);
        }

        /* create child process to handle each request */
        if ( (childpid = fork()) == 0) 
        {
            close(listenfd);

            /* decode flow information */
            FlowInfo* flow = (FlowInfo*) buf;
            flow->endTime = flow->startTime + (double) (flow->flowSize * 8) / (double) 1000000000;

            /* simulate network delay */
            sleep(rand() % 5);

            /* encode response packet */
            bzero(&buf, MAXLINE);
            memcpy(buf, flow, sizeof(FlowInfo));

            /* send response packet to client */
            if (sendto(listenfd, buf, sizeof(FlowInfo), 0, (struct sockaddr *) &cliaddr, clilen) < 0) 
            {
                printf("sendto error: %s\n", strerror(errno));
                exit(1);
            }

            close(listenfd);
            exit(0);
        }

        close(connfd);
    }
    return 0;
}