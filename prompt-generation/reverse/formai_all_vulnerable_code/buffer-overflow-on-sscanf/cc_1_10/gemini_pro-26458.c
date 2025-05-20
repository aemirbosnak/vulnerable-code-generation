//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>
#include <signal.h>
#include <errno.h>

static int running = 1;

static void sig_handler(int sig) {
    if (sig == SIGINT) {
        running = 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *res;
    int err;

    char hostname[1024];
    int port;

    char *url = argv[1];

    // Parse the URL
    if (sscanf(url, "http://%[^:]:%d", hostname, &port) != 2) {
        fprintf(stderr, "Invalid URL: %s\n", url);
        return 1;
    }

    // Set up the hints structure
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    // Get the address info
    if ((err = getaddrinfo(hostname, NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        return 1;
    }

    // Create the socket
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        return 1;
    }

    freeaddrinfo(res);

    // Set up the signal handler
    struct sigaction sa;
    sa.sa_handler = sig_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    // Send the request
    char request[] = "GET / HTTP/1.1\r\nHost: test.example.com\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response
    char response[1024];
    int n = recv(sockfd, response, sizeof(response), 0);
    if (n == -1) {
        perror("recv");
        return 1;
    }

    // Check the response
    if (strstr(response, "200 OK") == NULL) {
        fprintf(stderr, "Server returned an error: %s\n", response);
        return 1;
    }

    // Print the time
    time_t now = time(NULL);
    printf("%s: %ld\n", url, now);

    // Close the socket
    if (close(sockfd) == -1) {
        perror("close");
        return 1;
    }

    // Wait for Ctrl-C
    while (running) {
        sleep(1);
    }

    return 0;
}