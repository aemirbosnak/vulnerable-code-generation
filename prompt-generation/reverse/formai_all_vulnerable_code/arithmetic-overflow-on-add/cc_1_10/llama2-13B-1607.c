//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct message {
    char *data;
    int len;
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    char buffer[1024];
    int recv_len = recv(sock, buffer, 1024, 0);
    if (recv_len < 0) {
        perror("Received data failed");
        return 1;
    }

    printf("Received message: %s\n", buffer);

    struct message msg = {
        .data = "Hello, server!",
        .len = strlen("Hello, server!")
    };

    send(sock, msg.data, msg.len, 0);

    char *send_buffer = malloc(recv_len + 1);
    recv_len = recv(sock, send_buffer, recv_len + 1, 0);
    send_buffer[recv_len] = '\0';

    printf("Sent message: %s\n", send_buffer);

    free(send_buffer);

    close(sock);

    return 0;
}