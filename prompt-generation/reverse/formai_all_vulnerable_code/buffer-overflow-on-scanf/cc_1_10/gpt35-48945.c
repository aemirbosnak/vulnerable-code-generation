//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 21
#define MAX_BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[MAX_BUFF_SIZE];
    struct sockaddr_in serv_addr;

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: failed to create socket");
        exit(1);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("ERROR: invalid address");
        exit(1);
    }

    // Connect to FTP server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: connection failed");
        exit(1);
    }

    // Login with user and password
    char user[MAX_BUFF_SIZE];
    char pass[MAX_BUFF_SIZE];
    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);

    sprintf(buffer, "USER %s\r\n", user);
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, MAX_BUFF_SIZE - 1);
    buffer[n] = '\0';

    sprintf(buffer, "PASS %s\r\n", pass);
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, MAX_BUFF_SIZE - 1);
    buffer[n] = '\0';

    if (strstr(buffer, "230") == NULL) {
        printf("ERROR: incorrect username or password\n");
        exit(1);
    }

    printf("Logged in successfully!\n");

    while (1) {
        printf("FTP> ");
        // Read user command
        fgets(buffer, MAX_BUFF_SIZE - 1, stdin);
        buffer[strcspn(buffer, "\r\n")] = '\0'; // Removing new line character
        printf("Command entered: %s\n", buffer);

        // Send command to server
        write(sockfd, buffer, strlen(buffer));
        memset(buffer, 0, MAX_BUFF_SIZE);

        // Read response from server
        n = read(sockfd, buffer, MAX_BUFF_SIZE - 1);
        buffer[n] = '\0';
        printf("%s", buffer);

        // Quit FTP client
        if (strncmp(buffer, "221", 3) == 0) {
            printf("Exiting FTP client.\n");
            exit(0);
        }
    }

    return 0;
}