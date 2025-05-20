//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }
    
    printf("Connected to %s:%d\n", inet_ntoa(serv_addr.sin_addr), portno);
    
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);
    
    printf("Username: ");
    fgets(username, BUFFER_SIZE - 1, stdin);
    username[strcspn(username, "\r\n")] = 0;
    
    printf("Password: ");
    fgets(password, BUFFER_SIZE - 1, stdin);
    password[strcspn(password, "\r\n")] = 0;
    
    sprintf(buffer, "USER %s\r\n", username);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);
    
    sprintf(buffer, "PASS %s\r\n", password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);
    
    sprintf(buffer, "LIST\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);
    
    int message_count;
    if (sscanf(buffer, "+OK %d messages", &message_count) != 1) {
        error("ERROR parsing message count");
    }
    
    for (int i = 1; i <= message_count; i++) {
        sprintf(buffer, "RETR %d\r\n", i);
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to socket");
        }
        
        n = read(sockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        printf("%s\n", buffer);
        
        while (1) {
            n = read(sockfd, buffer, BUFFER_SIZE - 1);
            if (n < 0) {
                error("ERROR reading from socket");
            }
            if (n == 3 && strncmp(buffer, ".\r\n", 3) == 0) {
                break;
            }
            buffer[n] = '\0';
            printf("%s", buffer);
        }
    }
    
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }
    
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s\n", buffer);
    
    close(sockfd);
    return 0;
}