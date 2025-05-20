//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER 1024
#define POP3_PORT 110

int main(int argc, char* argv[]) {
    int sock;
    char buffer[MAX_BUFFER];
    struct sockaddr_in server_addr;
    struct hostent* hp;

    if(argc != 2) { // Check for valid number of arguments
        printf("Usage: %s <server address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Get server address
    if((hp = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Setup server address struct
    memset(&server_addr, 0, sizeof(server_addr)); // Zero out struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    memcpy(&server_addr.sin_addr, hp->h_addr, hp->h_length);

    // Connect to server
    if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Receive greeting message
    if(recv(sock, buffer, MAX_BUFFER, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send username
    printf("Username: ");
    fgets(buffer, MAX_BUFFER, stdin);
    snprintf(buffer, MAX_BUFFER, "USER %s", buffer);
    if(send(sock, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    if(recv(sock, buffer, MAX_BUFFER, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send password
    printf("Password: ");
    fgets(buffer, MAX_BUFFER, stdin);
    snprintf(buffer, MAX_BUFFER, "PASS %s", buffer);
    if(send(sock, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    if(recv(sock, buffer, MAX_BUFFER, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send command to list emails
    if(send(sock, "LIST\r\n", 6, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    if(recv(sock, buffer, MAX_BUFFER, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Send command to quit
    if(send(sock, "QUIT\r\n", 6, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    if(recv(sock, buffer, MAX_BUFFER, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);

    // Close socket
    close(sock);

    return 0;
}