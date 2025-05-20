//Falcon-180B DATASET v1.0 Category: Networking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char sendData[1024];
    char recvData[1024];
    int n;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("Error getting host by name\n");
        exit(2);
    }
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(12345);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(3);
    }

    // Send data to server
    strcpy(sendData, "Hello, World!");
    n = send(sock, sendData, strlen(sendData), 0);
    if (n < 0) {
        printf("Error sending data\n");
        exit(4);
    }

    // Receive data from server
    n = recv(sock, recvData, sizeof(recvData), 0);
    if (n < 0) {
        printf("Error receiving data\n");
        exit(5);
    }
    printf("Received data: %s\n", recvData);

    // Close socket
    close(sock);
    return 0;
}