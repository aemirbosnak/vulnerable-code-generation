//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define PORT 8080
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

char *spam_words[] = {"viagra", "cialis", "levitra", "spam", "junk", "unsolicited"};
int num_spam_words = sizeof(spam_words)/sizeof(spam_words[0]);

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        int i;
        for (i = 0; i < num_spam_words; i++) {
            if (strstr(buffer, spam_words[i])) {
                printf("SPAM detected from client %d\n", client_socket);
                close(client_socket);
                pthread_exit(0);
            }
        }
    }

    printf("Client %d disconnected\n", client_socket);
    close(client_socket);
    pthread_exit(0);
}

int main() {
    int server_thread_id;
    pthread_t thread_id[MAX_CLIENTS];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    listen(server_socket, 3);

    printf("Server started on port %d\n", PORT);

    while (num_clients < MAX_CLIENTS) {
        socklen_t addr_size = sizeof(struct sockaddr_in);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_sockets[num_clients], &addr_size);

        if (client_socket < 0) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Client %d connected\n", client_socket);
        pthread_create(&thread_id[num_clients], NULL, handle_client, (void *)&client_socket);
        num_clients++;
    }

    pthread_join(server_thread_id, NULL);

    return 0;
}