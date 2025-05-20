//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

struct sockaddr_in server_addr;
int sock = 0;
char buffer[MAX_SIZE];

int main() {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char *message = "Hello, World!";
    send(sock, message, strlen(message), 0);

    while (1) {
        int bytes_received = recv(sock, buffer, MAX_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        buffer[bytes_received] = '\0';
        printf("Received data: %s\n", buffer);
    }

    close(sock);
    return 0;
}