//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

void recursive_echo(int sockfd, struct sockaddr_in serveraddr, int len){
    char buffer[MAXLINE];
    char *hello = "Echoing...";

    printf("\nEnter your message: ");
    fgets(buffer, MAXLINE, stdin);

    if(buffer[0]=='\n'){
        printf("Bye!\n");
        close(sockfd);
        exit(0);
    }

    sendto(sockfd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *) &serveraddr, len);
    printf("Message sent.\n");

    int n = recvfrom(sockfd, (char *)buffer, MAXLINE,MSG_WAITALL, (struct sockaddr *) &serveraddr, &len);
    buffer[n] = '\0';

    printf("Server : %s", buffer);
    recursive_echo(sockfd, serveraddr, len);
}

int main() {
    int sockfd;
    char buffer[MAXLINE];
    char *hello = "Hello from client";
    struct sockaddr_in serveraddr;

    memset(&serveraddr, 0, sizeof(serveraddr));

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sockfd < 0) {
        perror("Socket Creation Failed");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(PORT);

    recursive_echo(sockfd, serveraddr, sizeof(serveraddr));

    return 0;
}