//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER 4096
#define SERVER_PORT 110

int main(int argc, char *argv[]) {
    char username[100], password[100];
    printf("Enter your email username: ");
    scanf("%s", username);
    printf("Enter your email password: ");
    scanf("%s", password);

    char buffer[MAX_BUFFER];
    memset(buffer, 0, MAX_BUFFER);

    struct hostent *he = gethostbyname("pop3.your-email-provider.com");
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    server.sin_addr = *((struct in_addr *)he->h_addr); 

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Failed to create socket.\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error: Failed to connect to server.\n");
        return 1;
    }

    int bytes_received = recv(sockfd, buffer, MAX_BUFFER, 0);
    if (bytes_received < 0) {
        printf("Error: Failed to receive data from server.\n");
        return 1;
    }

    printf("Server: %s\n", buffer);

    char user[MAX_BUFFER];
    snprintf(user, sizeof(user), "USER %s\r\n", username);
    send(sockfd, user, strlen(user), 0);
    bytes_received = recv(sockfd, buffer, MAX_BUFFER, 0);
    if (bytes_received < 0) {
        printf("Error: Failed to receive data from server.\n");
        return 1;
    }
    printf("Server: %s\n", buffer);

    char pass[MAX_BUFFER];
    snprintf(pass, sizeof(pass), "PASS %s\r\n", password);
    send(sockfd, pass, strlen(pass), 0);
    bytes_received = recv(sockfd, buffer, MAX_BUFFER, 0);
    if (bytes_received < 0) {
        printf("Error: Failed to receive data from server.\n");
        return 1;
    }
    printf("Server: %s\n", buffer);

    char list[] = "LIST\r\n";
    send(sockfd, list, strlen(list), 0);
    bytes_received = recv(sockfd, buffer, MAX_BUFFER, 0);
    if (bytes_received < 0) {
        printf("Error: Failed to receive data from server.\n");
        return 1;
    }
    printf("Server: %s\n", buffer);

    char quit[] = "QUIT\r\n";
    send(sockfd, quit, strlen(quit), 0);
    bytes_received = recv(sockfd, buffer, MAX_BUFFER, 0);
    if (bytes_received < 0) {
        printf("Error: Failed to receive data from server.\n");
        return 1;
    }
    printf("Server: %s\n", buffer);

    close(sockfd);
    return 0;
}