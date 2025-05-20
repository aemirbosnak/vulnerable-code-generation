//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, bytes_received;
    char buffer[BUFFER_SIZE];
    struct hostent *server;
    struct sockaddr_in serv_addr;

    if (argc != 3) {
        fprintf(stderr, "Usage: ./ftp_client hostname portnumber\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: no such host: %s\n", argv[1]);
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR: socket() failed: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR: connect() failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to FTP server on %s:%d\n", argv[1], atoi(argv[2]));

    bzero(buffer, BUFFER_SIZE);
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        fprintf(stderr, "ERROR: recv() failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("%s", buffer);

    char user_cmd[BUFFER_SIZE], response[BUFFER_SIZE];
    bzero(user_cmd, BUFFER_SIZE);
    bzero(response, BUFFER_SIZE);

    while (1) {
        printf(">> ");
        fgets(user_cmd, BUFFER_SIZE - 1, stdin);
        user_cmd[strcspn(user_cmd, "\n")] = '\0';
        
        if (strlen(user_cmd) > 0) {
            if (send(sockfd, user_cmd, strlen(user_cmd), 0) < 0) {
                fprintf(stderr, "ERROR: send() failed: %s\n", strerror(errno));
                exit(1);
            }

            bzero(buffer, BUFFER_SIZE);
            bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
            if (bytes_received < 0) {
                fprintf(stderr, "ERROR: recv() failed: %s\n", strerror(errno));
                exit(1);
            }

            if (strcmp(user_cmd, "QUIT") == 0) {
                printf("%s", buffer);
                break;
            }

            printf("%s\n", buffer);
        }
    }

    close(sockfd);
    return 0;
}