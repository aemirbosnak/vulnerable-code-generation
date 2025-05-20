//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: careful
/* FTP Client Example */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define FTP_PORT 21

int main(int argc, char *argv[]) {
    int sockfd, port;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char *hostname, *username, *password, *command, *response;

    if (argc < 4) {
        fprintf(stderr, "Usage: %s hostname username password\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    username = argv[2];
    password = argv[3];

    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname\n");
        return 1;
    }

    port = FTP_PORT;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: could not create socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *) host->h_addr);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error: could not connect to server");
        return 1;
    }

    response = malloc(1024);
    if (response == NULL) {
        perror("Error: could not allocate memory for response");
        return 1;
    }

    if (recv(sockfd, response, 1023, 0) < 0) {
        perror("Error: could not receive response from server");
        return 1;
    }

    printf("%s", response);

    command = "USER ";
    command = strcat(command, username);
    command = strcat(command, "\r\n");

    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Error: could not send username to server");
        return 1;
    }

    if (recv(sockfd, response, 1023, 0) < 0) {
        perror("Error: could not receive response from server");
        return 1;
    }

    printf("%s", response);

    command = "PASS ";
    command = strcat(command, password);
    command = strcat(command, "\r\n");

    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Error: could not send password to server");
        return 1;
    }

    if (recv(sockfd, response, 1023, 0) < 0) {
        perror("Error: could not receive response from server");
        return 1;
    }

    printf("%s", response);

    while (1) {
        printf("ftp> ");
        fgets(command, 1024, stdin);

        if (send(sockfd, command, strlen(command), 0) < 0) {
            perror("Error: could not send command to server");
            return 1;
        }

        if (recv(sockfd, response, 1023, 0) < 0) {
            perror("Error: could not receive response from server");
            return 1;
        }

        printf("%s", response);
    }

    close(sockfd);
    free(response);

    return 0;
}