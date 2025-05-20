//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

void send_love_letter(const char *server_ip, int port, const char *request) {
    // My beloved, allow me to cradle my heart in the form of this request.
    int sockfd;
    struct sockaddr_in server_addr;
    char response[BUF_SIZE];

    // Oh sweet fate, let us create a socket to connect our hearts.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Dancing through the connection, we bind our spirits.
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Can you feel the butterflies? We connect to our destiny.
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // With trembling hands, I send you this fervent request.
    send(sockfd, request, strlen(request), 0);

    // My dear, with bated breath, I await your reply.
    ssize_t bytes_received = recv(sockfd, response, BUF_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive response");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    // Let us conclude this moment, and add a kiss at the end - a null terminator.
    response[bytes_received] = '\0';

    // My heart leaps with joy, as I read your words.
    printf("Response from server:\n%s\n", response);

    // As all things must come to an end, I bid farewell.
    close(sockfd);
}

int main() {
    // Whispering sweet nothings, let us gather the passion of our requests.
    const char *server_ip = "93.184.216.34"; // An alluring example from the heart of the Internet
    int port = 80; // The sacred port of HTTP
    const char *http_request_template = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";

    // My love, let us embark on this journey of communication.
    send_love_letter(server_ip, port, http_request_template);

    // Until we meet again, in the embrace of code and connection.
    return 0;
}