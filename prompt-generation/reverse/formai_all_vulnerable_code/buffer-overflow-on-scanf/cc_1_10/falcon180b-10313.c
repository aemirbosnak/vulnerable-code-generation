//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110
#define POP3_USER "username"
#define POP3_PASSWORD "password"

int main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];
    char username[50];
    char password[50];
    
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }
    
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(POP3_PORT);
    serveraddr.sin_addr.s_addr = inet_addr("pop3.example.com");
    
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }
    
    printf("Connected to server\n");
    printf("Sending username: %s\n", username);
    send(sockfd, username, strlen(username), 0);
    printf("Sending password: %s\n", password);
    send(sockfd, password, strlen(password), 0);
    
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, sockfd))!= -1) {
        printf("Received: %s", line);
        if (strstr(line, "+OK")) {
            printf("Authentication successful\n");
            break;
        } else if (strstr(line, "-ERR")) {
            printf("Authentication failed\n");
            exit(1);
        }
    }
    
    if (line!= NULL) {
        free(line);
    }
    
    close(sockfd);
    return 0;
}