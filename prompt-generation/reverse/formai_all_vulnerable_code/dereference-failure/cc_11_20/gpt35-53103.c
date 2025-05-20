//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    
    int sockfd, newsockfd, portno, n;
    char buffer[256];

    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen = sizeof(cli_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error on accepting");
            continue;
        }

        int pid = fork();
        if (pid == 0) { // child process
            close(sockfd);
            while (1) {
                bzero(buffer, 256);
                n = read(newsockfd, buffer, 255);
                if (n < 0) {
                    perror("Error reading from socket");
                    exit(1);
                }
                printf("Message from client: %s\n", buffer);

                n = write(newsockfd, buffer, strlen(buffer));
                if (n < 0) {
                    perror("Error writing to socket");
                    exit(1);
                }
            }
            exit(0);
        }
        else if (pid < 0) {
            perror("Error on fork");
            exit(1);
        }
        else {
            close(newsockfd);
        }
    }

    return 0;
}