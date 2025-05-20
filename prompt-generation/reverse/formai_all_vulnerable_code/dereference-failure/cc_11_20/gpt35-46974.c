//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    char username[BUFFER_SIZE];
    char password[BUFFER_SIZE];
    char hostname[BUFFER_SIZE];
    int port;
    int sock_fd;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    ssize_t n;

    // Prompt user for username, password, hostname, and port
    printf("Enter username: ");
    fgets(username, BUFFER_SIZE, stdin);
    printf("Enter password: ");
    fgets(password, BUFFER_SIZE, stdin);
    printf("Enter hostname: ");
    fgets(hostname, BUFFER_SIZE, stdin);
    printf("Enter port: ");
    scanf("%d", &port);

    // Remove newline characters from input strings
    username[strcspn(username, "\n")] = 0;
    password[strcspn(password, "\n")] = 0;
    hostname[strcspn(hostname, "\n")] = 0;

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Get host information
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "No such host: %s\n", hostname);
        exit(1);
    }

    // Set server address struct
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Write username to server
    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read response from server
    n = read(sock_fd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Write password to server
    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read response from server
    n = read(sock_fd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Retrieve message count from server
    snprintf(buffer, BUFFER_SIZE, "STAT\r\n");
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read response from server
    n = read(sock_fd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Quit server connection
    snprintf(buffer, BUFFER_SIZE, "QUIT\r\n");
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        exit(1);
    }
    close(sock_fd);

    return 0;
}