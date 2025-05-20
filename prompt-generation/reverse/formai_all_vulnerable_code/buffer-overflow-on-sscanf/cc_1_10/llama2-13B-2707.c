//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define MAX_BUFFER_SIZE 1024

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main() {
    int sock, client_sock;
    struct email email;
    char buffer[MAX_BUFFER_SIZE];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(SMTP_PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Read the email from the client
    printf("Enter email details: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    sscanf(buffer, "%s %s %s %s", &email.from, &email.to, &email.subject, &email.message);

    // Send the email to the server
    send(sock, buffer, strlen(buffer), 0);

    // Receive the response from the server
    recv(sock, buffer, MAX_BUFFER_SIZE, 0);

    // Print the response
    printf("%s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}