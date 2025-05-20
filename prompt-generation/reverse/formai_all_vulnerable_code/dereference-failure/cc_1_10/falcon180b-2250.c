//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_HOSTNAME_LEN 100
#define MAX_DATA_LEN 1024
#define TIME_OUT 2 //seconds

int main(int argc, char **argv)
{
    if(argc!= 2)
    {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_LEN];
    strncpy(hostname, argv[1], MAX_HOSTNAME_LEN-1);
    hostname[MAX_HOSTNAME_LEN-1] = '\0';

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        printf("Error: Could not create socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    if(inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0)
    {
        printf("Error: Invalid hostname\n");
        close(sockfd);
        return 1;
    }

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error: Could not connect to server\n");
        close(sockfd);
        return 1;
    }

    char send_data[MAX_DATA_LEN];
    strncpy(send_data, "GET / HTTP/1.1\r\nHost: ", MAX_DATA_LEN-1);
    strncat(send_data, hostname, MAX_DATA_LEN-strlen(send_data)-1);
    strncat(send_data, "\r\n", MAX_DATA_LEN-strlen(send_data)-1);
    send(sockfd, send_data, strlen(send_data), 0);

    char recv_data[MAX_DATA_LEN];
    int bytes_recv = 0;
    struct timeval timeout;
    timeout.tv_sec = TIME_OUT;
    timeout.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    while(1)
    {
        int ret = recv(sockfd, recv_data+bytes_recv, MAX_DATA_LEN-bytes_recv, 0);
        if(ret <= 0)
        {
            if(ret == 0)
            {
                printf("Error: Connection closed by server\n");
            }
            else if(errno == ETIMEDOUT)
            {
                printf("Error: Connection timed out\n");
            }
            else
            {
                printf("Error: %s\n", strerror(errno));
            }
            break;
        }
        bytes_recv += ret;
        recv_data[bytes_recv] = '\0';
        if(strstr(recv_data, "200 OK")!= NULL)
        {
            printf("Server is reachable\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}