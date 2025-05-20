//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 1234
#define SERVER_IP "127.0.0.1"

int main(int argc, char *argv[]) {
    int sock = 0, n = 0;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *message = "Hello, World!";
    int message_len = strlen(message);
    struct timeval timeout;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) == -1) {
        printf("Error setting socket timeout\n");
        exit(1);
    }

    if (send(sock, message, message_len, 0) == -1) {
        printf("Error sending message\n");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = recv(sock, buffer, BUFFER_SIZE, 0);
    if (n == -1) {
        printf("Error receiving response\n");
        exit(1);
    } else if (n == 0) {
        printf("Server disconnected\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);

    close(sock);

    return 0;
}