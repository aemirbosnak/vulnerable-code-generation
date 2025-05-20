//FormAI DATASET v1.0 Category: Chat server ; Style: high level of detail
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <pthread.h> 

#define PORT 8888 

void *connection_handler(void *);

int main(int argc, char const *argv[]) {
    int socket_desc, client_sock, c;
    struct sockaddr_in server, client;

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed. Error");
        return 1;
    }
    puts("Server is now running...");

    listen(socket_desc, 3);

    while (1) {
        c = sizeof(struct sockaddr_in);
        client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);

        printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        pthread_t sniffer_thread;
        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *)&client_sock) < 0) {
            perror("could not create thread");
            return 1;
        }

        puts("Handler assigned");
    }

    return 0;
}

void *connection_handler(void *socket_desc) {
    int sock = *(int *)socket_desc;
    int read_size;
    char message[2000];

    while ((read_size = recv(sock, message, 2000, 0)) > 0) {
        message[read_size] = '\0';
        printf("%s\n", message);
        write(sock, message, strlen(message));
    }

    return 0;
}