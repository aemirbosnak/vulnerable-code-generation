//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>

#define PORT 110
#define MAX_LINE 1024
#define MAX_USER 32
#define MAX_PASS 32
#define MAX_STAT 512

int main(int argc, char *argv[]) {
    char hostname[MAX_LINE];
    char username[MAX_USER];
    char password[MAX_PASS];
    char status[MAX_STAT];
    int port = PORT;
    int sockfd;
    struct sockaddr_in servaddr;
    int n;
    FILE *fp;
    
    if (argc < 5) {
        printf("Usage: %s <hostname> <username> <password> <port>\n", argv[0]);
        exit(1);
    }
    
    strcpy(hostname, argv[1]);
    strcpy(username, argv[2]);
    strcpy(password, argv[3]);
    port = atoi(argv[4]);
    
    printf("Connecting to %s on port %d...\n", hostname, port);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(hostname);
    
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }
    
    printf("Connected to %s on port %d\n", hostname, port);
    
    fp = fopen("commands.txt", "r");
    
    if (fp == NULL) {
        printf("Error opening commands file\n");
        exit(1);
    }
    
    while (fgets(status, MAX_STAT, fp)!= NULL) {
        n = strlen(status);
        
        if (status[n-1] == '\n') {
            status[n-1] = '\0';
        }
        
        write(sockfd, status, strlen(status));
        
        if (status[0] == 'L') {
            strcpy(status, "PASS ");
            strcat(status, password);
            write(sockfd, status, strlen(status));
        }
        
        if (status[0] == 'R') {
            strcpy(status, "RETR ");
            strcat(status, status+5);
            write(sockfd, status, strlen(status));
        }
        
        if (status[0] == 'D') {
            strcpy(status, "DELE ");
            strcat(status, status+5);
            write(sockfd, status, strlen(status));
        }
        
        if (status[0] == 'Q') {
            strcpy(status, "QUIT\r\n");
            write(sockfd, status, strlen(status));
            break;
        }
    }
    
    fclose(fp);
    
    close(sockfd);
    
    printf("Disconnected from %s on port %d\n", hostname, port);
    
    return 0;
}