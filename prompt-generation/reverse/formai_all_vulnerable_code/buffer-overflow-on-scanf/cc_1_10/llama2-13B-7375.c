//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_MESSAGE_LENGTH 512

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    struct email email;
    printf("Enter sender's email: ");
    scanf("%s", email.from);
    printf("Enter recipient's email: ");
    scanf("%s", email.to);
    printf("Enter subject: ");
    scanf("%s", email.subject);
    printf("Enter message: ");
    fgets(email.message, MAX_MESSAGE_LENGTH, stdin);

    // Create the email message
    char message[1024];
    sprintf(message, "FROM: %s\r\nTO: %s\r\nSUBJECT: %s\r\n%s", email.from, email.to, email.subject, email.message);

    // Send the email using the socket
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    // Receive the response from the server
    char response[1024];
    recv(sock, response, 1024, 0);

    // Print the response
    printf("Server response: %s\n", response);

    close(sock);
    return 0;
}