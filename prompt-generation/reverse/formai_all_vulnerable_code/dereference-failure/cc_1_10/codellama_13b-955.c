//Code Llama-13B DATASET v1.0 Category: Website Uptime Monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 80
#define BUFSIZE 1024
#define MAX_URLS 100

typedef struct {
    char *url;
    int status_code;
    char *status_message;
} website_status;

website_status check_website(char *url) {
    website_status status;
    status.status_code = 0;
    status.status_message = "";

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    // Look up the server address
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    int err = getaddrinfo(url, "80", &hints, &res);
    if (err != 0) {
        perror("getaddrinfo");
        exit(1);
    }

    // Connect to the server
    err = connect(sock, res->ai_addr, res->ai_addrlen);
    if (err == -1) {
        perror("connect");
        exit(1);
    }

    // Send a GET request
    char request[BUFSIZE];
    snprintf(request, BUFSIZE, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", url);
    send(sock, request, strlen(request), 0);

    // Receive the response
    char response[BUFSIZE];
    recv(sock, response, BUFSIZE, 0);

    // Parse the response
    char *status_code_str = strtok(response, " ");
    status.status_code = atoi(status_code_str);
    char *status_message_str = strtok(NULL, "\r\n");
    status.status_message = strdup(status_message_str);

    // Clean up
    close(sock);
    freeaddrinfo(res);

    return status;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return 1;
    }

    int num_urls = argc - 1;
    website_status *statuses = malloc(sizeof(website_status) * num_urls);
    for (int i = 0; i < num_urls; i++) {
        statuses[i] = check_website(argv[i + 1]);
    }

    for (int i = 0; i < num_urls; i++) {
        printf("URL: %s\nStatus Code: %d\nStatus Message: %s\n\n", argv[i + 1], statuses[i].status_code, statuses[i].status_message);
    }

    return 0;
}