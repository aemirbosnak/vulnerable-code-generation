//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    char buf[BUF_SIZE];
    char *user = "myemail@gmail.com";
    char *pass = "mypassword";
    char *host = "pop.gmail.com";
    int port = 995;
    struct sockaddr_in server_addr;
    struct hostent *he;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Get host by name
    he = gethostbyname(host);
    if (he == NULL) {
        perror("Failed to get host by name");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *) he->h_addr);
    server_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) != 0) {
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }

    // Receive greeting
    memset(buf, 0, BUF_SIZE);
    if (recv(sock, buf, BUF_SIZE, 0) <= 0) {
        perror("Failed to receive greeting");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send user
    sprintf(buf, "USER %s\r\n", user);
    if (send(sock, buf, strlen(buf), 0) != strlen(buf)) {
        perror("Failed to send user");
        exit(EXIT_FAILURE);
    }

    // Receive user response
    memset(buf, 0, BUF_SIZE);
    if (recv(sock, buf, BUF_SIZE, 0) <= 0 || strncmp(buf, "+OK", 3) != 0) {
        perror("Failed to receive user response");
        exit(EXIT_FAILURE);
    }

    // Send pass
    sprintf(buf, "PASS %s\r\n", pass);
    if (send(sock, buf, strlen(buf), 0) != strlen(buf)) {
        perror("Failed to send pass");
        exit(EXIT_FAILURE);
    }

    // Receive pass response
    memset(buf, 0, BUF_SIZE);
    if (recv(sock, buf, BUF_SIZE, 0) <= 0 || strncmp(buf, "+OK", 3) != 0) {
        perror("Failed to receive pass response");
        exit(EXIT_FAILURE);
    }

    // Send stat
    sprintf(buf, "STAT\r\n");
    if (send(sock, buf, strlen(buf), 0) != strlen(buf)) {
        perror("Failed to send stat");
        exit(EXIT_FAILURE);
    }

    // Receive stat response
    memset(buf, 0, BUF_SIZE);
    if (recv(sock, buf, BUF_SIZE, 0) <= 0 || strncmp(buf, "+OK", 3) != 0) {
        perror("Failed to receive stat response");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Close socket
    close(sock);

    return 0;
}