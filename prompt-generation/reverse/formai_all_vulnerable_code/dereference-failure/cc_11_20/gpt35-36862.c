//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define PARANOIA_LEVEL 10

int main(int argc, char *argv[]) {
    int sock, client_sock, len, level = 0;
    struct sockaddr_in server, client;
    char buffer[1024], response[1024];

    srand(time(NULL));

    // Socket creation
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        printf("Socket creation failed!\n");
        exit(1);
    }

    // Socket configuration
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(argv[1]));

    // Bind
    if(bind(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Socket binding failed!\n");
        exit(1);
    }

    // Listen
    if(listen(sock, 10) == -1) {
        printf("Socket listening failed!\n");
        exit(1);
    }

    while(1) {
        printf("Waiting for incoming connections...\n");

        // Connection acceptance
        len = sizeof(struct sockaddr_in);
        client_sock = accept(sock, (struct sockaddr *)&client, (socklen_t *)&len);
        if(client_sock == -1) {
            printf("Client connection failed!\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // First level of paranoia
        if(rand() % PARANOIA_LEVEL == 0) {
            printf("Terminating connection due to Paranoia level %d!\n", level++);
            close(client_sock);
            continue;
        }

        // Receive message from client
        if(recv(client_sock, buffer, 1024, 0) == -1) {
            printf("Message receiving failed!\n");
            close(client_sock);
            continue;
        }

        memset(response, 0, strlen(response));

        // Second level of paranoia
        if(rand() % PARANOIA_LEVEL == 0) {
            sprintf(response, "Paranoia level %d: The message you sent triggered the firewall. Disconnecting.", level++);
            if(send(client_sock, response, strlen(response), 0) == -1) {
                printf("Failed to send response to client!\n");
                close(client_sock);
                continue;
            }
            close(client_sock);
            continue;
        }

        // Message processing
        sprintf(response, "Your message was %d characters long.", strlen(buffer));

        // Third and final level of paranoia
        if(rand() % PARANOIA_LEVEL == 0) {
            sprintf(response, "Paranoia level %d: Your message triggered a security alert and is being analyzed. Disconnecting.", level++);
            if(send(client_sock, response, strlen(response), 0) == -1) {
                printf("Failed to send response to client!\n");
                close(client_sock);
                continue;
            }
            close(client_sock);
            continue;
        }

        printf("Received message: %s\n", buffer);

        // Send response to client
        if(send(client_sock, response, strlen(response), 0) == -1) {
            printf("Failed to send response to client!\n");
            close(client_sock);
            continue;
        }

        printf("Response sent: %s\n", response);

        close(client_sock);
    }

    close(sock);

    return 0;
}