//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    // Get the URL from the command line
    char *url = argv[1];

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    struct hostent *server = gethostbyname(url);
    if (server == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        exit(1);
    }
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80); // Default port for HTTP
    serv_addr.sin_addr.s_addr = *((unsigned long *)server->h_addr);
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send the request
    char request[100];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", url);
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Read the response
    char response[4096];
    int n = recv(sock, response, sizeof(response), 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }
    response[n] = '\0';

    // Print the response
    printf("Response: %s\n", response);

    // Close the socket
    close(sock);

    return 0;
}