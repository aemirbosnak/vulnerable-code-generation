//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    char send_buffer[BUFFER_SIZE];
    bzero(send_buffer, BUFFER_SIZE);
    sprintf(send_buffer, "USER %s\n", argv[3]);
    n = write(sockfd, send_buffer, strlen(send_buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    bzero(send_buffer, BUFFER_SIZE);
    sprintf(send_buffer, "PASS %s\n", argv[4]);
    n = write(sockfd, send_buffer, strlen(send_buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    bzero(send_buffer, BUFFER_SIZE);
    sprintf(send_buffer, "STAT\n");
    n = write(sockfd, send_buffer, strlen(send_buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    int num_messages, total_size;
    sscanf(buffer, "+OK %d %d", &num_messages, &total_size);

    for (int i = 1; i <= num_messages; ++i) {
        bzero(send_buffer, BUFFER_SIZE);
        sprintf(send_buffer, "RETR %d\n", i);
        n = write(sockfd, send_buffer, strlen(send_buffer));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        bzero(buffer, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        printf("%s", buffer);

        do {
            bzero(buffer, BUFFER_SIZE);
            n = read(sockfd, buffer, BUFFER_SIZE - 1);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }

            printf("%s", buffer);
        } while (strncmp(buffer, "\r\n.\r\n", 5) != 0);
    }

    bzero(send_buffer, BUFFER_SIZE);
    sprintf(send_buffer, "QUIT\n");
    n = write(sockfd, send_buffer, strlen(send_buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    return 0;
}