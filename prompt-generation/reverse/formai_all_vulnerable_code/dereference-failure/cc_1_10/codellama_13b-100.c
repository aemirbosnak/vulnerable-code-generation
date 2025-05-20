//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: portable
/*
 * Building a FTP Client example program in a portable style
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Check the arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the FTP server
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", argv[1]);
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    server_addr.sin_addr = *((struct in_addr *) server->h_addr);
    memset(server_addr.sin_zero, 0, sizeof(server_addr.sin_zero));

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the user name and password to the FTP server
    char buf[BUF_SIZE];
    sprintf(buf, "USER %s\r\n", getenv("USER"));
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    sprintf(buf, "PASS %s\r\n", getenv("PASS"));
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the response from the FTP server
    if (recv(sock, buf, BUF_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    printf("%s\n", buf);

    // Close the socket
    close(sock);

    return 0;
}