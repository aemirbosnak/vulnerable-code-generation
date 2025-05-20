//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define PORT 993
#define TIMEOUT 30

int main(int argc, char **argv) {
    int sockfd, retval, n;
    struct sockaddr_in serveraddr;
    char buffer[1024];
    struct hostent *host;
    char *hostName = "imap.example.com";
    char *userName = "example";
    char *password = "password";
    int auth = 0;
    char *auth_type = "PLAIN";

    if (argc!= 4) {
        printf("Usage: %s <host> <user> <password>\n", argv[0]);
        return 1;
    }

    host = gethostbyname(hostName);
    if (host == NULL) {
        fprintf(stderr, "Error: Unknown host\n");
        return 1;
    }

    serveraddr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&serveraddr.sin_addr.s_addr, host->h_length);
    serveraddr.sin_port = htons(PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket");
        return 1;
    }

    retval = connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if (retval < 0) {
        perror("Connect");
        return 1;
    }

    printf("Connected to %s\n", inet_ntoa(serveraddr.sin_addr));

    snprintf(buffer, sizeof(buffer), "LOGIN %s %s\r\n", userName, password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Write");
        return 1;
    }

    retval = read(sockfd, buffer, sizeof(buffer));
    if (retval < 0) {
        perror("Read");
        return 1;
    }

    if (buffer[0] == '*') {
        printf("Login successful\n");
        auth = 1;
    } else {
        printf("Login failed\n");
        return 1;
    }

    snprintf(buffer, sizeof(buffer), "SELECT INBOX\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Write");
        return 1;
    }

    retval = read(sockfd, buffer, sizeof(buffer));
    if (retval < 0) {
        perror("Read");
        return 1;
    }

    if (buffer[0] == '*') {
        printf("Successfully selected INBOX\n");
    } else {
        printf("Failed to select INBOX\n");
        return 1;
    }

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        retval = read(sockfd, buffer, sizeof(buffer));
        if (retval < 0) {
            perror("Read");
            return 1;
        }

        if (strstr(buffer, "NOOP")!= NULL) {
            printf("NOOP\n");
            continue;
        } else if (strstr(buffer, "FETCH")!= NULL) {
            printf("FETCH %s %s\n", buffer, buffer + strlen(buffer));
            continue;
        } else if (strstr(buffer, "LOGOUT")!= NULL) {
            printf("LOGOUT\n");
            break;
        } else {
            printf("Unknown command: %s\n", buffer);
            break;
        }
    }

    if (auth) {
        printf("Logging out...\n");
        snprintf(buffer, sizeof(buffer), "LOGOUT\r\n");
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("Write");
            return 1;
        }

        retval = read(sockfd, buffer, sizeof(buffer));
        if (retval < 0) {
            perror("Read");
            return 1;
        }

        printf("Logout successful\n");
    }

    close(sockfd);
    return 0;
}