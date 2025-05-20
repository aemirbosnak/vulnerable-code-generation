//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_HOST_NAME 1024
#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[MAX_DATA_SIZE];
    char *host;
    int host_len;
    int opt = 1;
    int addrlen = sizeof(cli_addr);

    if (argc < 3) {
        printf("Usage:./client <IP Address> <Port Number>\n");
        exit(0);
    }

    host = argv[1];
    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Unable to create socket\n");
        exit(0);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Set up server address structure
    server = gethostbyname(host);
    if (server == NULL) {
        printf("Error: No such host\n");
        exit(0);
    }

    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Unable to connect\n");
        exit(0);
    }

    while (1) {
        // Receive data from server
        memset(buffer, 0, MAX_DATA_SIZE);
        if (recv(sockfd, buffer, MAX_DATA_SIZE, 0) <= 0) {
            printf("Error: Unable to receive data\n");
            exit(0);
        }

        // Send data to server
        send(sockfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);
    return 0;
}