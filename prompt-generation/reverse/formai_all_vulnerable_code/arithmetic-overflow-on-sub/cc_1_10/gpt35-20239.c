//FormAI DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<sys/time.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>

#define PACKET_SIZE  4096

struct packet{
    struct timeval tv;
    char msg[PACKET_SIZE];
};

int main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage: %s <hostname/IP>\n", argv[0]);
        return 0;
    }
    struct sockaddr_in addr;
    int i, sockfd, cnt=0;
    char ip[INET_ADDRSTRLEN], name[INET_ADDRSTRLEN];
    struct addrinfo hints, *res;
    struct timeval start, end;
    float rtt, total=0;
    int sent, rcvd, lost;
    socklen_t len=sizeof(addr);
    struct packet pkt;
    char buf[PACKET_SIZE];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family=AF_INET;
    hints.ai_protocol=IPPROTO_TCP;
    hints.ai_socktype=SOCK_STREAM;

    if(getaddrinfo(argv[1], NULL, &hints, &res)!=0){
        printf("getaddrinfo() failed\n");
        return 0;
    }
    
    printf("Pinging %s [%s] with %d bytes of data:\n", argv[1], inet_ntop(AF_INET, &((struct sockaddr_in *)res->ai_addr)->sin_addr, ip, INET_ADDRSTRLEN), PACKET_SIZE);

    if((sockfd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))==-1){
        printf("socket() failed\n");
        return 0;
    }

    memcpy(&addr, res->ai_addr, res->ai_addrlen);
    inet_ntop(AF_INET, &addr.sin_addr, name, INET_ADDRSTRLEN);

    while(cnt++<10){
        gettimeofday(&start, NULL);

        if(sendto(sockfd, &pkt, sizeof(pkt), 0, (const struct sockaddr *)&addr, len)==-1){
            printf("sendto() failed\n");
            return 0;
        }

        sent++;rcvd=0;
        if(recvfrom(sockfd, buf, PACKET_SIZE, 0, (struct sockaddr *)&addr, &len)==-1){
            printf("recvfrom() failed\n");
            continue;;
        }

        gettimeofday(&end, NULL);
        rtt=((end.tv_sec-start.tv_sec)*1000.0)+((end.tv_usec-start.tv_usec)/1000.0);
        total+=rtt;rcvd++;lost=sent-rcvd;

        printf("Reply from %s: bytes=%d time=%.2fms TTL=%d\n", name, PACKET_SIZE, rtt, 64);
     }

    printf("Ping statistics for %s:\n"
           "\tPackets: Sent = %d, Received = %d, Lost = %d (%.2f%% lost),\n"
           "Approximate round trip times in milli-seconds:\n"
           "\tMinimum = %.2fms, Maximum = %.2fms, Average = %.2fms\n",
           name, sent, rcvd, lost, (float)lost/sent*100, total/sent, total/rcvd, (float)total/sent);

    close(sockfd);
    return 0;
}