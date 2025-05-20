//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    int n;
    char user[50];
    char password[50];

    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: Could not resolve hostname.\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not open socket.\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Could not connect to server.\n");
        exit(1);
    }

    printf("Connected to %s.\n", argv[1]);

    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        printf("Error: Could not read from server.\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    printf("Username: ");
    fgets(user, sizeof(user), stdin);
    printf("Password: ");
    fgets(password, sizeof(password), stdin);

    sprintf(buffer, "USER %s", user);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error: Could not write to server.\n");
        exit(1);
    }

    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        printf("Error: Could not read from server.\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    sprintf(buffer, "PASS %s", password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error: Could not write to server.\n");
        exit(1);
    }

    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        printf("Error: Could not read from server.\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    sprintf(buffer, "LIST");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error: Could not write to server.\n");
        exit(1);
    }

    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        printf("Error: Could not read from server.\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    sprintf(buffer, "QUIT");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error: Could not write to server.\n");
        exit(1);
    }

    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        printf("Error: Could not read from server.\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    close(sockfd);
    return 0;
}