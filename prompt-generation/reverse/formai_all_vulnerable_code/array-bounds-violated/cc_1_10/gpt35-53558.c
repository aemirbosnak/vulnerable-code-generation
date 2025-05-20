//FormAI DATASET v1.0 Category: Chat server ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[2000];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind
    if(bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        // shapeshift into a bat and fly away to avoid the bind error
        printf("Binding failed, morphing into a bat\n");
        system("ping 127.0.0.1");
        return 1;
    }
    printf("Shapeshift complete, bind successful\n");

    // Listen
    listen(socket_desc, 3);

    // Accept incoming connections
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))) {
        puts("Connection accepted!");

        // Receive a message from client
        while((read_size = recv(client_sock, client_message, 2000, 0)) > 0 ) {
            // shapeshift into a werewolf and howl the message
            client_message[read_size] = '\0';
            printf("Werewolf transformation complete, howling message: %s\n", client_message);

            // Reply to client
            write(client_sock, "Message received!", strlen("Message received!"));
        }

        if(read_size == 0) {
            puts("Client disconnected");
        }
        else {
            puts("Receive failed");
        }
    }

    return 0;
}