//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    int sockfd, portnum, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024];

    printf("Enter POP3 server hostname: ");
    scanf("%s", buffer);

    server = gethostbyname(buffer);

    if (server == NULL) {
        printf("Error: no such host\n");
        return -1;
    }

    // clear serv_addr variable
    bzero(&serv_addr, sizeof(serv_addr));

    printf("Enter POP3 server port: ");
    scanf("%d", &portnum);

    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portnum);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) { 
        printf("Error: cannot open socket\n"); 
        return -1; 
    }

    printf("Connecting to POP3 server...\n");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: cannot connect to server\n");
        return -1;
    }

    printf("Connected to POP3 server!\n");

    // Login credentials
    char *user = "romeo@montague.com";
    char *pass = "juliet1234";

    // Send login command
    char login[1024];
    sprintf(login, "USER %s\r\n", user);
    printf(">> %s", login);
    send(sockfd, login, strlen(login), 0);

    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("<< %s", buffer);

    // Send password command
    sprintf(login, "PASS %s\r\n", pass);
    printf(">> %s", login);
    send(sockfd, login, strlen(login), 0);

    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("<< %s", buffer);

    // List messages command
    char *list = "LIST\r\n";
    printf(">> %s", list);
    send(sockfd, list, strlen(list), 0);

    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("<< %s", buffer);

    // Quit command
    char *quit = "QUIT\r\n";
    printf(">> %s", quit);
    send(sockfd, quit, strlen(quit), 0);

    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("<< %s", buffer);

    close(sockfd);

    return 0;
}