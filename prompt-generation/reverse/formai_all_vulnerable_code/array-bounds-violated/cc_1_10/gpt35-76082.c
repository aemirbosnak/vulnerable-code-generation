//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

// Function to create a client socket
int create_client_socket(char *hostname, int port) {
    struct hostent *he;
    struct sockaddr_in server_addr;
    int client_socket;

    if ((he = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname() error");
        exit(1);
    }

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket() error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *) he->h_addr);
    memset(&(server_addr.sin_zero), 0, sizeof(server_addr.sin_zero));
    
    if (connect(client_socket, (struct sockaddr *) &server_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect() error");
        exit(1);
    }

    return client_socket;
}

// Function to send an email
void send_email(int client_socket, char *from, char *to, char *subject, char *body) {
    char buffer[MAX_BUFFER];
    int recv_size;

    // Send HELLO command
    snprintf(buffer, MAX_BUFFER, "HELO %s\r\n", "localhost");
    send(client_socket, buffer, strlen(buffer), 0);

    recv_size = recv(client_socket, buffer, MAX_BUFFER - 1, 0);
    buffer[recv_size] = '\0';
    printf("%s", buffer);

    // Send MAIL FROM command
    snprintf(buffer, MAX_BUFFER, "MAIL FROM: <%s>\r\n", from);
    send(client_socket, buffer, strlen(buffer), 0);

    recv_size = recv(client_socket, buffer, MAX_BUFFER - 1, 0);
    buffer[recv_size] = '\0';
    printf("%s", buffer);

    // Send RCPT TO command
    snprintf(buffer, MAX_BUFFER, "RCPT TO: <%s>\r\n", to);
    send(client_socket, buffer, strlen(buffer), 0);

    recv_size = recv(client_socket, buffer, MAX_BUFFER - 1, 0);
    buffer[recv_size] = '\0';
    printf("%s", buffer);

    // Send DATA command
    snprintf(buffer, MAX_BUFFER, "DATA\r\n");
    send(client_socket, buffer, strlen(buffer), 0);

    recv_size = recv(client_socket, buffer, MAX_BUFFER - 1, 0);
    buffer[recv_size] = '\0';
    printf("%s", buffer);

    // Send email body
    snprintf(buffer, MAX_BUFFER, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, subject, body);
    send(client_socket, buffer, strlen(buffer), 0);

    recv_size = recv(client_socket, buffer, MAX_BUFFER - 1, 0);
    buffer[recv_size] = '\0';
    printf("%s", buffer);

    // Send QUIT command
    snprintf(buffer, MAX_BUFFER, "QUIT\r\n");
    send(client_socket, buffer, strlen(buffer), 0);

    recv_size = recv(client_socket, buffer, MAX_BUFFER - 1, 0);
    buffer[recv_size] = '\0';
    printf("%s", buffer);
}

// Main function
int main(int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: %s <hostname> <port> <from> <to>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *from = argv[3];
    char *to = argv[4];
    char *subject = "Test Email";
    char *body = "This is a test email.";

    int client_socket = create_client_socket(hostname, port);
    send_email(client_socket, from, to, subject, body);
    close(client_socket);

    return 0;
}