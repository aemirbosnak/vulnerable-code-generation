//FormAI DATASET v1.0 Category: Networking ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<netdb.h>
#include<errno.h>

#define PORT "8888"
#define MAX_BUFF_SIZE 1024

int main(){
    int error, n;
    struct addrinfo hints, *results, *rp;
    int sockfd = 0;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    error = getaddrinfo(NULL, PORT, &hints, &results);
    if (error != 0){
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(error));
        exit(EXIT_FAILURE);
    }

    for (rp = results; rp != NULL; rp = rp->ai_next){
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1)
            continue;

        if (fcntl(sockfd, F_SETFL, O_NONBLOCK) == -1){
            perror("fcntl");
            exit(EXIT_FAILURE);
        }

        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1){
            break;
        }

        if (errno != EINPROGRESS){
            close(sockfd);
            continue;
        }
        
        fd_set write_fds;
        FD_ZERO(&write_fds);
        FD_SET(sockfd, &write_fds);

        struct timeval timeout;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        int ready = select(sockfd + 1, NULL, &write_fds, NULL, &timeout);
        if (ready == -1){
            perror("select");
            exit(EXIT_FAILURE);
        }
        if (ready == 0){
            fprintf(stderr, "Connection timeout\n");
            exit(EXIT_FAILURE);
        }
        if (FD_ISSET(sockfd, &write_fds)){
            int err;
            socklen_t len = sizeof(err);
            if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &err, &len) == -1){
                perror("getsockopt");
                exit(EXIT_FAILURE);
            }
            if (err == 0){
                break;
            }
            else{
                close(sockfd);
            }
        }
    }

    freeaddrinfo(results);

    if (rp == NULL){
        fprintf(stderr, "Failed to connect\n");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFF_SIZE];
    memset(&buffer, 0, sizeof(buffer));
    sprintf(buffer, "Test message from client!");

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0){
        perror("Error writing to socket.");
        exit(EXIT_FAILURE);
    }

    printf("Message sent successfully!\n");
    close(sockfd);
    return 0;
}