//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int sockfd, num_bytes;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    struct hostent *he;
    struct sockaddr_in server;

    if ((he = gethostbyname(argv[1])) == NULL) {  
        perror("gethostbyname failed");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(server.sin_zero), '\0', 8);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1) {
        perror("connect failed");
        exit(1);
    }

    fd_set read_fds, write_fds;
    FD_ZERO(&read_fds);
    FD_ZERO(&write_fds);
    FD_SET(sockfd, &read_fds);

    while (1) {
        int num_fds = select(sockfd + 1, &read_fds, &write_fds, NULL, NULL);

        if (num_fds == -1) {
            perror("select failed");
            exit(1);
        }

        if (FD_ISSET(sockfd, &read_fds)) {
            if ((num_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0)) == -1) {
                perror("recv failed");
                exit(1);
            }

            if (num_bytes == 0) {
                printf("Connection closed by server.\n");
                break;
            }

            buffer[num_bytes] = '\0';

            printf("%s", buffer);
        }

        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            if ((num_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE)) == -1) {
                perror("read failed");
                exit(1);
            }

            if (num_bytes == 0) {
                printf("Connection closed by client.\n");
                break;
            }

            buffer[num_bytes] = '\0';

            if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
                perror("send failed");
                exit(1);
            }
        }

        FD_SET(sockfd, &read_fds);
        FD_SET(STDIN_FILENO, &read_fds);
    }

    close(sockfd);

    return 0;
}