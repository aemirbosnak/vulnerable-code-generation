//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/time.h>

#define PORT 80
#define IP "127.0.0.1"

typedef struct{
    char * hostname;
    char * ip_address;
} host_entry;


int DNS_lookup(char * hostname, char * ip_address)
{
    struct addrinfo hints, *result;
    struct sockaddr_in *saddr;
    int error;

    memset(&hints, 0, sizeof(hints)); //Zero out hints
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM; //TCP stream sockets
    hints.ai_flags |= AI_CANONNAME; //Return canon name

    error = getaddrinfo(hostname,NULL,&hints,&result);

    if(error == 0)
    {
        saddr = (struct sockaddr_in *)result->ai_addr;
        memcpy(ip_address, inet_ntoa(saddr -> sin_addr), INET_ADDRSTRLEN);

        freeaddrinfo(result);

        return 0;
    }

    return -1;
}

int main()
{
    struct timeval start, end;
    double diff;

    host_entry hosts[5];

    hosts[0].hostname = "www.google.com";
    hosts[1].hostname = "www.yahoo.com";
    hosts[2].hostname = "www.amazon.com";
    hosts[3].hostname = "www.microsoft.com";
    hosts[4].hostname = "www.facebook.com";

    int i;

    for(i = 0; i < 5; i++)
    {
        char * ip_address = (char *)malloc(INET_ADDRSTRLEN * sizeof(char));

        gettimeofday(&start, 0);

        if(DNS_lookup(hosts[i].hostname, ip_address) == 0)
        {
            hosts[i].ip_address = ip_address;
        }
        else
        {
            printf("DNS lookup failed for host: %s\n", hosts[i].hostname);
        }

        gettimeofday(&end, 0);

        diff = (double)(end.tv_usec - start.tv_usec) / 1000000.0 + (double)(end.tv_sec - start.tv_sec);

        printf("Time taken to resolve %s: %f second(s)\n", hosts[i].hostname, diff);
    }

    int sockfd, send_ret;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        printf("Error occurred while creating socket.\n");
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, IP, &serv_addr.sin_addr) <= 0)
    {
        printf("Invalid Address/ Address not supported.\n");
        return -1;
    }

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Connection Failed.\n");
        return -1;
    }

    for(i = 0; i < 5; i++)
    {
        send_ret = send(sockfd , hosts[i].ip_address , strlen(hosts[i].ip_address) , 0 );

        if(send_ret < 0)
        {
            printf("Failed to send data to server.\n");
            return -1;
        }

        printf("IP Address of %s sent.\n", hosts[i].hostname);
    }

    close(sockfd);

    return 0;
}