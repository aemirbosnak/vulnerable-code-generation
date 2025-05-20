//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: surprised
// Building a SMTP Client example program in a surprised style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    struct hostent *host;
    char *hostaddr;
    char *portnum;
    char *msg;
    char buf[BUFSIZE];

    // Check for correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <hostname> <portnum> <message>\n", argv[0]);
        exit(1);
    }

    // Set host and port number
    host = gethostbyname(argv[1]);
    hostaddr = inet_ntoa(*(struct in_addr *)host->h_addr);
    portnum = argv[2];
    msg = argv[3];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Set up server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(hostaddr);
    server.sin_port = htons(atoi(portnum));

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send message
    printf("Sending message to %s:%s...\n", hostaddr, portnum);
    if (send(sock, msg, strlen(msg), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Close socket
    close(sock);

    return 0;
}