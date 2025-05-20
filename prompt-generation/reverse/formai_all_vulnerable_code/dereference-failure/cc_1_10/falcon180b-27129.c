//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int main(int argc, char **argv)
{
    int sockfd, n;
    struct hostent *he;
    struct sockaddr_in serv_addr;
    char send_data[MAX_DATA], recv_data[MAX_DATA];
    int data_len;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <data_size>\n", argv[0]);
        exit(1);
    }

    strncpy(send_data, argv[2], MAX_DATA);
    data_len = strlen(send_data);

    if ((he = gethostbyname(argv[1])) == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr, he->h_addr, he->h_length);
    serv_addr.sin_port = htons(1234);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    send(sockfd, send_data, data_len, 0);

    while ((n = recv(sockfd, recv_data, MAX_DATA, 0)) > 0) {
        recv_data[n] = '\0';
        printf("Received data: %s\n", recv_data);
    }

    close(sockfd);
    return 0;
}