//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8000

int main(int argc, char *argv[]) {
    int socket_desc, read_size;
    struct sockaddr_in server;
    char message[2000], server_reply[2000];

    //create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    //connect to the server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("Connect error");
        return 1;
    }

    //receive server welcome message
    if ((read_size = recv(socket_desc, server_reply, 2000, 0)) > 0) {
        server_reply[read_size] = '\0';
        printf("%s\n", server_reply);
    } else {
        puts("Server disconnected");
        return 1;
    }

    //send user input to server and receive output
    while (1) {
        printf("Enter command: ");
        fgets(message, sizeof(message), stdin);

        if (send(socket_desc, message, strlen(message), 0) < 0) {
            puts("Send failed");
            return 1;
        }

        if ((read_size = recv(socket_desc, server_reply, 2000, 0)) > 0) {
            server_reply[read_size] = '\0';
            printf("%s\n", server_reply);
        } else {
            puts("Server disconnected");
            return 1;
        }
    }

    close(socket_desc);
    return 0;
}