//Code Llama-13B DATASET v1.0 Category: Simple HTTP Proxy ; Style: interoperable
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>

    int main(int argc, char *argv[]) {
        int sockfd, newsockfd, portno, clilen;
        char buffer[256];
        struct sockaddr_in serv_addr, cli_addr;
        int n;

        if (argc < 2) {
            fprintf(stderr, "usage %s port\n", argv[0]);
            exit(1);
        }

        portno = atoi(argv[1]);

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }

        memset((char *) &serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);

        if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR on binding");
            exit(1);
        }

        listen(sockfd, 5);

        clilen = sizeof(cli_addr);

        while (1) {
            newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
            if (newsockfd < 0) {
                perror("ERROR on accept");
                exit(1);
            }

            printf("New connection from %s port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

            while (1) {
                memset(buffer, 0, 256);
                n = read(newsockfd, buffer, 255);
                if (n < 0) {
                    perror("ERROR reading from socket");
                    exit(1);
                }

                if (n == 0) {
                    printf("Client disconnected\n");
                    break;
                }

                printf("Received message: %s\n", buffer);

                n = write(newsockfd, buffer, strlen(buffer));
                if (n < 0) {
                    perror("ERROR writing to socket");
                    exit(1);
                }
            }

            close(newsockfd);
        }

        close(sockfd);

        return 0;
    }