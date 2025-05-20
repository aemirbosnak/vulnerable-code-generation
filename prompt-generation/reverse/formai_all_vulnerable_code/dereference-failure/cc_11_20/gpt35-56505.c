//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket;
    char buffer[BUFFER_SIZE];

    struct hostent *server;
    struct sockaddr_in server_address;

    // check for command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    // create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // get server details
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    // set server address details
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(atoi(argv[2]));

    // connect to the server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // receive welcome message
    bzero(buffer, BUFFER_SIZE);
    if (recv(client_socket, buffer, BUFFER_SIZE-1, 0) < 0) {
        perror("ERROR receiving welcome message");
        exit(1);
    }
    printf("%s\n", buffer);

    // send login credentials
    char username[] = "Username";
    char password[] = "Password";
    char login_command[BUFFER_SIZE];
    sprintf(login_command, "LOGIN %s %s\n", username, password);
    if (send(client_socket, login_command, strlen(login_command), 0) < 0) {
        perror("ERROR sending login credentials");
        exit(1);
    }

    // receive login response
    bzero(buffer, BUFFER_SIZE);
    if (recv(client_socket, buffer, BUFFER_SIZE-1, 0) < 0) {
        perror("ERROR receiving login response");
        exit(1);
    }
    printf("%s\n", buffer);

    // send SELECT command to select inbox
    char select_command[] = "SELECT INBOX\n";
    if (send(client_socket, select_command, strlen(select_command), 0) < 0) {
        perror("ERROR sending SELECT command");
        exit(1);
    }

    // receive SELECT response
    bzero(buffer, BUFFER_SIZE);
    if (recv(client_socket, buffer, BUFFER_SIZE-1, 0) < 0) {
        perror("ERROR receiving SELECT response");
        exit(1);
    }
    printf("%s\n", buffer);

    // send LOGOUT command to disconnect
    char logout_command[] = "LOGOUT\n";
    if (send(client_socket, logout_command, strlen(logout_command), 0) < 0) {
        perror("ERROR sending LOGOUT command");
        exit(1);
    }

    // receive LOGOUT response
    bzero(buffer, BUFFER_SIZE);
    if (recv(client_socket, buffer, BUFFER_SIZE-1, 0) < 0) {
        perror("ERROR receiving LOGOUT response");
        exit(1);
    }
    printf("%s\n", buffer);

    // close the socket
    close(client_socket);

    return 0;
}