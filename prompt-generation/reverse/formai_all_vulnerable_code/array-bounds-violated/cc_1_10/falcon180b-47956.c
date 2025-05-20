//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 8888

void error_handling(char* message) {
    perror(message);
    exit(1);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(server_addr);
    int bytes_received;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket failed");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, addrlen) == -1)
        error_handling("connect failed");

    while(1) {
        if ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) <= 0) {
            if (bytes_received == 0)
                printf("Server disconnected\n");
            else
                error_handling("recv failed");
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Received: %s", buffer);
    }

    close(sock);
    return 0;
}