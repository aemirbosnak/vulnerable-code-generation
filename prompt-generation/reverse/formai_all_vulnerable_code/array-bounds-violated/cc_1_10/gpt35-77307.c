//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 1024
#define IMAP_SERVER_PORT 143

int main(int argc, char *argv[]) {

    int sock_fd, read_size;
    struct sockaddr_in imap_server;
    char buf[BUFSIZE], user[50], password[50];

    if (argc != 2) {
        fprintf(stderr, "Usage: ./imap_client <IMAP server IP or domain name>\n");
        exit(EXIT_FAILURE);
    }

    // create a socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // set up the server address and port
    imap_server.sin_family = AF_INET;
    imap_server.sin_port = htons(IMAP_SERVER_PORT);
    sprintf(buf, "%s", argv[1]);
    if (inet_pton(AF_INET, buf, &imap_server.sin_addr) <= 0) {
        perror("Invalid server IP address");
        exit(EXIT_FAILURE);
    }

    // connect to the server
    if (connect(sock_fd, (struct sockaddr *) &imap_server, sizeof(imap_server)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // read the server's greeting
    read_size = recv(sock_fd, buf, BUFSIZE, 0);
    if (read_size == -1) {
        perror("Greeting receive failed");
        exit(EXIT_FAILURE);
    }

    // display the greeting
    buf[read_size] = '\0';
    printf("Server says: %s\n", buf);

    // login to the server
    printf("Enter username: ");
    fgets(user, sizeof(user), stdin);
    user[strlen(user) - 1] = '\0';

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strlen(password) - 1] = '\0';

    sprintf(buf, "login %s %s\n", user, password);
    if (send(sock_fd, buf, strlen(buf), 0) == -1) {
        perror("Login failed");
        exit(EXIT_FAILURE);
    }

    // read the server's response to the login command
    read_size = recv(sock_fd, buf, BUFSIZE, 0);
    if (read_size == -1) {
        perror("Login response receive failed");
        exit(EXIT_FAILURE);
    }

    // display the response
    buf[read_size] = '\0';
    printf("Server says: %s\n", buf);

    // quit
    sprintf(buf, "quit\n");

    if (send(sock_fd, buf, strlen(buf), 0) == -1) {
        perror("Quit failed");
        exit(EXIT_FAILURE);
    }

    // read the server's response to the quit command
    read_size = recv(sock_fd, buf, BUFSIZE, 0);
    if (read_size == -1) {
        perror("Quit response receive failed");
        exit(EXIT_FAILURE);
    }

    // display the response
    buf[read_size] = '\0';
    printf("Server says: %s\n", buf);

    // close the connection
    close(sock_fd);

    return 0;
}