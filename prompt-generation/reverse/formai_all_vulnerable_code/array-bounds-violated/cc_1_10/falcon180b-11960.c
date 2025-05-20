//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void die(const char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    char* user = "username";
    char* pass = "password";

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        die("socket failed");
    }

    // Connect to server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    inet_pton(AF_INET, "pop3.example.com", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        die("connect failed");
    }

    // Send USER command
    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", user);
    bytes_received = send(sock, buffer, strlen(buffer), 0);
    if (bytes_received == -1) {
        die("send failed");
    }

    // Send PASS command
    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", pass);
    bytes_received = send(sock, buffer, strlen(buffer), 0);
    if (bytes_received == -1) {
        die("send failed");
    }

    // Receive response from server
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        die("recv failed");
    }
    buffer[bytes_received] = '\0';
    printf("Server response: %s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}