//MISTRAL-7B DATASET v1.0 Category: Socket programming ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char send_buffer[10] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nSocket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed");
        return -1;
    }

    printf("Connected to server\n");

    while(1) {
        printf("Enter message to send to server: ");
        scanf("%s", send_buffer);

        send(sock, send_buffer, strlen(send_buffer), 0);
        printf("Message sent to server\n");

        valread = recv(sock, buffer, BUFFER_SIZE, 0);

        if (valread == 0) {
            printf("Connection Closed by the server\n");
            break;
        }

        printf("Server response: %s\n", buffer);
    }

    if (close(sock) < 0) {
        printf("\nError occurred during closing socket");
        return -1;
    }

    printf("Socket closed\n");
    return 0;
}