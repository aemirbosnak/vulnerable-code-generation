//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 25

int main(int argc, char *argv[]) {
    if(argc!= 4) {
        printf("Usage:./smtp_client <server_ip> <username> <password>\n");
        return 1;
    }

    char *server_ip = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    host = gethostbyname(server_ip);
    if(host == NULL) {
        printf("Error resolving hostname\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = *(unsigned long *)host->h_addr;

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    sprintf(buffer, "HELO %s\r\n", server_ip);
    send(sockfd, buffer, strlen(buffer), 0);

    char *response;
    response = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if(response == NULL) {
        printf("Error receiving response\n");
        return 1;
    }

    printf("Server response: %s", buffer);

    sprintf(buffer, "AUTH LOGIN\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    response = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if(response == NULL) {
        printf("Error receiving response\n");
        return 1;
    }

    printf("Server response: %s", buffer);

    sprintf(buffer, "%s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    response = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if(response == NULL) {
        printf("Error receiving response\n");
        return 1;
    }

    printf("Server response: %s", buffer);

    sprintf(buffer, "%s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    response = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if(response == NULL) {
        printf("Error receiving response\n");
        return 1;
    }

    printf("Server response: %s", buffer);

    close(sockfd);
    return 0;
}