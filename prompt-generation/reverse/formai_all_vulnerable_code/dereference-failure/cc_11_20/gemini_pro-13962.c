//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_SEND_BUFFER_SIZE 512
#define MAX_RECV_BUFFER_SIZE 1024

static char *host = "localhost";
static int port = 25;

static void send_smtp(const char *to, const char *from, const char *message) {
    int client_fd;
    struct sockaddr_in server_addr;
    char send_buffer[MAX_SEND_BUFFER_SIZE];
    char recv_buffer[MAX_RECV_BUFFER_SIZE];
    int nbytes;

    // Create socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    // Connect to server
    if (connect(client_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    // Send HELO command
    snprintf(send_buffer, MAX_SEND_BUFFER_SIZE, "HELO %s\r\n", host);
    nbytes = send(client_fd, send_buffer, strlen(send_buffer), 0);
    if (nbytes < 0) {
        fprintf(stderr, "Error sending HELO command: %s\n", strerror(errno));
        exit(1);
    }

    // Receive server response
    nbytes = recv(client_fd, recv_buffer, MAX_RECV_BUFFER_SIZE, 0);
    if (nbytes < 0) {
        fprintf(stderr, "Error receiving server response: %s\n", strerror(errno));
        exit(1);
    }

    // Check server response
    if (strncmp(recv_buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: server did not respond with 250: %s\n", recv_buffer);
        exit(1);
    }

    // Send MAIL FROM command
    snprintf(send_buffer, MAX_SEND_BUFFER_SIZE, "MAIL FROM: %s\r\n", from);
    nbytes = send(client_fd, send_buffer, strlen(send_buffer), 0);
    if (nbytes < 0) {
        fprintf(stderr, "Error sending MAIL FROM command: %s\n", strerror(errno));
        exit(1);
    }

    // Receive server response
    nbytes = recv(client_fd, recv_buffer, MAX_RECV_BUFFER_SIZE, 0);
    if (nbytes < 0) {
        fprintf(stderr, "Error receiving server response: %s\n", strerror(errno));
        exit(1);
    }

    // Check server response
    if (strncmp(recv_buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: server did not respond with 250: %s\n", recv_buffer);
        exit(1);
    }

    // Send RCPT TO command
    snprintf(send_buffer, MAX_SEND_BUFFER_SIZE, "RCPT TO: %s\r\n", to);
    nbytes = send(client_fd, send_buffer, strlen(send_buffer), 0);
    if (nbytes < 0) {
        fprintf(stderr, "Error sending RCPT TO command: %s\n", strerror(errno));
        exit(1);
    }

    // Receive server response
    nbytes = recv(client_fd, recv_buffer, MAX_RECV_BUFFER_SIZE, 0);
    if (nbytes < 0) {
        fprintf(stderr, "Error receiving server response: %s\n", strerror(errno));
        exit(1);
    }

    // Check server response
    if (strncmp(recv_buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: server did not respond with 250: %s\n", recv_buffer);
        exit(1);
    }

    // Send DATA command
    snprintf(send_buffer, MAX_SEND_BUFFER_SIZE, "DATA\r\n");
    nbytes = send(client_fd, send_buffer, strlen(send_buffer), 0);
    if (nbytes < 0) {
        fprintf(stderr, "Error sending DATA command: %s\n", strerror(errno));
        exit(1);
    }

    // Receive server response
    nbytes = recv(client_fd, recv_buffer, MAX_RECV_BUFFER_SIZE, 0);
    if (nbytes < 0) {
        fprintf(stderr, "Error receiving server response: %s\n", strerror(errno));
        exit(1);
    }

    // Check server response
    if (strncmp(recv_buffer, "354", 3) != 0) {
        fprintf(stderr, "Error: server did not respond with 354: %s\n", recv_buffer);
        exit(1);
    }

    // Send message body
    snprintf(send_buffer, MAX_SEND_BUFFER_SIZE, "%s\r\n.\r\n", message);
    nbytes = send(client_fd, send_buffer, strlen(send_buffer), 0);
    if (nbytes < 0) {
        fprintf(stderr, "Error sending message body: %s\n", strerror(errno));
        exit(1);
    }

    // Receive server response
    nbytes = recv(client_fd, recv_buffer, MAX_RECV_BUFFER_SIZE, 0);
    if (nbytes < 0) {
        fprintf(stderr, "Error receiving server response: %s\n", strerror(errno));
        exit(1);
    }

    // Check server response
    if (strncmp(recv_buffer, "250", 3) != 0) {
        fprintf(stderr, "Error: server did not respond with 250: %s\n", recv_buffer);
        exit(1);
    }

    // Send QUIT command
    snprintf(send_buffer, MAX_SEND_BUFFER_SIZE, "QUIT\r\n");
    nbytes = send(client_fd, send_buffer, strlen(send_buffer), 0);
    if (nbytes < 0) {
        fprintf(stderr, "Error sending QUIT command: %s\n", strerror(errno));
        exit(1);
    }

    // Receive server response
    nbytes = recv(client_fd, recv_buffer, MAX_RECV_BUFFER_SIZE, 0);
    if (nbytes < 0) {
        fprintf(stderr, "Error receiving server response: %s\n", strerror(errno));
        exit(1);
    }

    // Check server response
    if (strncmp(recv_buffer, "221", 3) != 0) {
        fprintf(stderr, "Error: server did not respond with 221: %s\n", recv_buffer);
        exit(1);
    }

    // Close socket
    close(client_fd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <to> <from> <message>\n", argv[0]);
        exit(1);
    }

    send_smtp(argv[1], argv[2], argv[3]);

    return 0;
}