//FormAI DATASET v1.0 Category: Chat server ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clientlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];
    char *reply = "I got your message";
    pid_t pid;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) {
                 printf("Error on binding\n");
                 exit(1);
             }

    listen(sockfd,5);
    clientlen = sizeof(cli_addr);

    while(1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clientlen);
        if (newsockfd < 0) {
            printf("Error on accept\n");
            exit(1);
        }

        pid = fork();
        if (pid < 0) {
            printf("Error on fork\n");
            exit(1);
        }

        if (pid == 0) {
            close(sockfd);
            while(1) {
                bzero(buffer,256);
                n = read(newsockfd,buffer,255);

                if (n < 0) {
                    printf("Error reading from socket\n");
                    exit(1);
                }

                printf("Client: %s\n",buffer);

                n = write(newsockfd, reply, strlen(reply));

                if (n < 0) {
                    printf("Error writing to socket\n");
                    exit(1);
                }

                if (strncmp(buffer, "exit", 4) == 0) {
                    break;
                }
            }
            close(newsockfd);
            exit(0);
        } else {
            close(newsockfd);
        }
    } 

    return 0;
}