//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT_NUMBER 25

int main(int argc, char *argv[]) {

    int client_socket, error_check;
    struct sockaddr_in server_address;
    struct hostent *host;
    char message[1024], server_reply[2000];

    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get host details
    if ((host = gethostbyname(argv[1])) == NULL) {
        perror("Error in gethostbyname()");
        exit(EXIT_FAILURE);
    }

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error in creating socket");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT_NUMBER);
    server_address.sin_addr = *((struct in_addr *) host->h_addr);
    bzero(&(server_address.sin_zero), 8);

    // Connect to SMTP server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(struct sockaddr)) == -1) {
        perror("Error in connecting to SMTP server");
        exit(EXIT_FAILURE);
    }

    // Receive server greeting
    if ((error_check = recv(client_socket, server_reply, 2000, 0)) == -1) {
        perror("Error in receiving message from server");
        exit(EXIT_FAILURE);
    }

    server_reply[error_check] = '\0';
    printf("%s", server_reply);

    // Send HELO command
    strcpy(message, "HELO me\r\n");
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("Error in sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive response to HELO command
    if ((error_check = recv(client_socket, server_reply, 2000, 0)) == -1) {
        perror("Error in receiving message from server");
        exit(EXIT_FAILURE);
    }

    server_reply[error_check] = '\0';
    printf("%s", server_reply);

    // Send MAIL FROM command
    strcpy(message, "MAIL FROM:<example@domain.com>\r\n");
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("Error in sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive response to MAIL FROM command
    if ((error_check = recv(client_socket, server_reply, 2000, 0)) == -1) {
        perror("Error in receiving message from server");
        exit(EXIT_FAILURE);
    }

    server_reply[error_check] = '\0';
    printf("%s", server_reply);

    // Send RCPT TO command
    strcpy(message, "RCPT TO:<recipient@domain.com>\r\n");
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("Error in sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive response to RCPT TO command
    if ((error_check = recv(client_socket, server_reply, 2000, 0)) == -1) {
        perror("Error in receiving message from server");
        exit(EXIT_FAILURE);
    }

    server_reply[error_check] = '\0';
    printf("%s", server_reply);

    // Send DATA command
    strcpy(message, "DATA\r\n");
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("Error in sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive response to DATA command
    if ((error_check = recv(client_socket, server_reply, 2000, 0)) == -1) {
        perror("Error in receiving message from server");
        exit(EXIT_FAILURE);
    }

    server_reply[error_check] = '\0';
    printf("%s", server_reply);

    // Send message body
    strcpy(message, "From: Example <example@domain.com>\r\nTo: Recipient <recipient@domain.com>\r\nSubject: Test email\r\n\r\nThis is the message body.\r\n.\r\n");
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("Error in sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive response to message body
    if ((error_check = recv(client_socket, server_reply, 2000, 0)) == -1) {
        perror("Error in receiving message from server");
        exit(EXIT_FAILURE);
    }

    server_reply[error_check] = '\0';
    printf("%s", server_reply);

    // Send QUIT command
    strcpy(message, "QUIT\r\n");
    if (send(client_socket, message, strlen(message), 0) == -1) {
        perror("Error in sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive response to QUIT command
    if ((error_check = recv(client_socket, server_reply, 2000, 0)) == -1) {
        perror("Error in receiving message from server");
        exit(EXIT_FAILURE);
    }

    server_reply[error_check] = '\0';
    printf("%s", server_reply);

    close(client_socket);

    return 0;
}