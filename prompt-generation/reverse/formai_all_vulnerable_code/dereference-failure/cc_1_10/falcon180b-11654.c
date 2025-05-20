//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, recv_bytes;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    time_t start_time, end_time;
    double elapsed_time;
    int i;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");

    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        recv_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (recv_bytes <= 0) {
            break;
        }

        printf("Received data: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}