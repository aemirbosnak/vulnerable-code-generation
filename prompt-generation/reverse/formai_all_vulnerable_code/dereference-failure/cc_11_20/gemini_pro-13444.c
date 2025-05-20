//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024
#define MAX_EVENTS 10

struct event {
    int fd;
    int type;
};

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    int nfds, max_fd;
    fd_set read_fds;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        return 1;
    }

    listen(sockfd, 5);

    nfds = 0;
    max_fd = sockfd;
    FD_ZERO(&read_fds);

    while (1) {
        FD_SET(sockfd, &read_fds);

        nfds = select(max_fd+1, &read_fds, NULL, NULL, NULL);

        if (nfds < 0) {
            perror("select");
            return 1;
        }

        if (FD_ISSET(sockfd, &read_fds)) {
            clilen = sizeof(cli_addr);
            newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

            if (newsockfd < 0) {
                perror("accept");
                return 1;
            }

            printf("New connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

            // Check if the new socket is in the read_fds set
            if (!FD_ISSET(newsockfd, &read_fds)) {
                FD_SET(newsockfd, &read_fds);

                if (newsockfd > max_fd) {
                    max_fd = newsockfd;
                }
            }
        }

        for (int i = 0; i <= max_fd; i++) {
            if (FD_ISSET(i, &read_fds)) {
                char buf[MAX_BUF_SIZE];

                n = read(i, buf, MAX_BUF_SIZE);

                if (n == 0) {
                    // Connection closed
                    close(i);
                    FD_CLR(i, &read_fds);
                } else if (n < 0) {
                    perror("read");
                    return 1;
                } else {
                    printf("Received data from %d: %s\n", i, buf);

                    // Check if the data is an attack
                    if (strstr(buf, "attack") != NULL) {
                        printf("Attack detected from %d\n", i);

                        // Close the connection
                        close(i);
                        FD_CLR(i, &read_fds);
                    }
                }
            }
        }
    }

    close(sockfd);

    return 0;
}