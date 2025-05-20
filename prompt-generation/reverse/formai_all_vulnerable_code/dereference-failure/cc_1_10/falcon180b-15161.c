//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024 // buffer size for data transfer

// function prototypes
int connect_to_server(char *server_name, int port);
void send_command(int sock, char *command);
void receive_response(int sock, char *response);
int main(int argc, char *argv[]) {
    char *server_name = argv[1];
    int port = atoi(argv[2]);
    int sock = 0;
    char buffer[BUFFER_SIZE];

    // connect to the server
    sock = connect_to_server(server_name, port);
    if (sock == -1) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    // login to the server
    send_command(sock, "USER anonymous\r\n");
    receive_response(sock, buffer);

    send_command(sock, "PASS anonymous@example.com\r\n");
    receive_response(sock, buffer);

    // change to the desired directory
    send_command(sock, "CWD /\r\n");
    receive_response(sock, buffer);

    // retrieve the list of files in the current directory
    send_command(sock, "LIST\r\n");
    receive_response(sock, buffer);

    close(sock);
    return 0;
}

// function to connect to the server
int connect_to_server(char *server_name, int port) {
    struct addrinfo hints, *servinfo;
    int sock = -1;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(server_name, NULL, &hints, &servinfo)!= 0) {
        fprintf(stderr, "Error resolving hostname\n");
        exit(1);
    }

    for (servinfo = servinfo; servinfo!= NULL; servinfo = servinfo->ai_next) {
        sock = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
        if (sock == -1) {
            fprintf(stderr, "Error creating socket\n");
            continue;
        }

        if (connect(sock, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
            fprintf(stderr, "Error connecting to server\n");
            close(sock);
            sock = -1;
            continue;
        }

        break;
    }

    if (sock == -1) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    return sock;
}

// function to send a command to the server
void send_command(int sock, char *command) {
    send(sock, command, strlen(command), 0);
}

// function to receive a response from the server
void receive_response(int sock, char *buffer) {
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        fprintf(stderr, "Error receiving response\n");
        exit(1);
    }
}