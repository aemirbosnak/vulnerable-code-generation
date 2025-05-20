//FormAI DATASET v1.0 Category: Networking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int sock;
    struct sockaddr_in server;
    char message[1024], server_reply[2000];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connect failed. Error");
        return 1;
    }

    // Send some data
    while (1) {
        printf("\nType a message: ");
        gets(message);

        // Send the message to server
        if (send(sock, message, strlen(message), 0) < 0) {
            puts("Send failed");
            return 1;
        }

        // Receive a reply from the server
        if (recv(sock, server_reply, 2000, 0) < 0) {
            puts("Recv failed");
            break;
        }

        printf("Server reply: ");
        puts(server_reply);
    }

    // Close the socket
    close(sock);
    return 0;
}