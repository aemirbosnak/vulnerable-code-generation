//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 21
#define MAX 1000

char *host;
int port;
int sockfd;
struct sockaddr_in server;
int main(int argc, char *argv[])
{
    printf("Enter the hostname or IP address: ");
    scanf("%s", host);
    printf("Enter the port number: ");
    scanf("%d", &port);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error: Failed to create socket\n");
        exit(0);
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(host);
    server.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("Error: Failed to connect to server\n");
        exit(0);
    }
    printf("Connected to server\n");
    char *username = "anonymous";
    char *password = "";
    char buffer[MAX];
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX, 0);
    printf("Response from server: %s", buffer);
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX, 0);
    printf("Response from server: %s", buffer);
    char *command = "LIST\r\n";
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, buffer, MAX, 0);
    printf("Response from server: %s", buffer);
    close(sockfd);
    return 0;
}