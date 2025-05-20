//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_fd, port_no, n;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Get the necessary information about the server
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }
    port_no = atoi(argv[2]);

    // Create a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Initialize the server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_no);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Read the welcome message from the server
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sock_fd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send the username to the server
    memset(buffer, 0, BUFFER_SIZE);
    printf("Username: ");
    fgets(buffer, BUFFER_SIZE - 1, stdin);
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to server");
        exit(1);
    }

    // Read the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sock_fd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send the password to the server
    memset(buffer, 0, BUFFER_SIZE);
    printf("Password: ");
    fgets(buffer, BUFFER_SIZE - 1, stdin);
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to server");
        exit(1);
    }

    // Read the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sock_fd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from server");
        exit(1);
    }
    printf("%s", buffer);

    // Send the LIST command to the server
    n = write(sock_fd, "LIST\n", 5);
    if (n < 0) {
        perror("Error writing to server");
        exit(1);
    }

    // Read the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sock_fd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from server");
        exit(1);
    }
    printf("%s", buffer);

    // Close the connection
    close(sock_fd);
    return 0;
}