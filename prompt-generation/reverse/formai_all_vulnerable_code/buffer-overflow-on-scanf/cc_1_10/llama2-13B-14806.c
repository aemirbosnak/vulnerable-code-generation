//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 25

struct email {
    char from[50];
    char to[50];
    char subject[100];
    char message[200];
};

int main() {
    int sock, client_sock;
    struct email email;
    char buffer[256];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    // Bind the socket to a port
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Waiting for incoming connections...\n");

    // Accept an incoming connection
    client_sock = accept(sock, NULL, NULL);
    if (client_sock < 0) {
        perror("accept failed");
        exit(1);
    }

    printf("Connection accepted. Waiting for email...\n");

    // Receive the email from the client
    recv(client_sock, buffer, 256, 0);
    printf("Received email: %s\n", buffer);

    // Send a response email to the client
    email.from[0] = '\0';
    email.to[0] = '\0';
    email.subject[0] = '\0';
    email.message[0] = '\0';
    scanf("%s %s %s %s", email.from, email.to, email.subject, email.message);
    send(client_sock, buffer, strlen(email.message), 0);

    // Close the sockets
    close(sock);
    close(client_sock);

    return 0;
}