//Code Llama-13B DATASET v1.0 Category: Website Uptime Monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_URL_LENGTH 256
#define MAX_RESPONSE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    int url_len = strlen(url);

    if (url_len > MAX_URL_LENGTH) {
        printf("URL too long\n");
        return 1;
    }

    char response[MAX_RESPONSE_LENGTH];
    int response_len = 0;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Could not create socket\n");
        return 1;
    }

    struct hostent *host = gethostbyname(url);
    if (host == NULL) {
        printf("Could not resolve hostname\n");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("Could not connect to server\n");
        return 1;
    }

    char *request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char *request_buf = malloc(url_len + strlen(request) + 1);
    sprintf(request_buf, request, url);

    int request_len = strlen(request_buf);
    int sent = send(sock, request_buf, request_len, 0);
    if (sent < 0) {
        printf("Could not send request\n");
        return 1;
    }

    free(request_buf);

    int received = 0;
    while ((received = recv(sock, response, MAX_RESPONSE_LENGTH, 0)) > 0) {
        response_len += received;
    }

    if (response_len > 0) {
        printf("Response: %s\n", response);
    } else {
        printf("No response\n");
    }

    close(sock);

    return 0;
}