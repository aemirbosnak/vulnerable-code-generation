//FormAI DATASET v1.0 Category: Chat server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080

// A linked list to store connected clients
typedef struct clientNode {
    int fd;
    char nickname[20];
    struct sockaddr_in address;
    struct clientNode* next;
} clientNode;

// The head of the client linked list
clientNode* head = NULL;

// Add a new client to the linked list
void addClient(int fd, char* nickname, struct sockaddr_in address) {
    clientNode* client = (clientNode*) malloc(sizeof(clientNode));
    client->fd = fd;
    strcpy(client->nickname, nickname);
    client->address = address;
    client->next = head;
    head = client;
}

// Remove a client from the linked list
void removeClient(int fd) {
    clientNode* current = head;
    clientNode* prev = NULL;
    while (current != NULL) {
        if (current->fd == fd) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

// Send a message to all connected clients
void broadcast(char* message, int senderFd) {
    clientNode* current = head;
    while (current != NULL) {
        if (current->fd != senderFd) {
            send(current->fd, message, strlen(message), 0);
        }
        current = current->next;
    }
}

// Handle client connections in a separate thread
void* handleConnection(void* args) {
    int client_fd = *(int*) args;
    char nickname[20];
    recv(client_fd, nickname, 20, 0);
    addClient(client_fd, nickname, *((struct sockaddr_in*) args));
    printf("%s connected\n", nickname);

    while (1) {
        char message[1024];
        int n = recv(client_fd, message, 1024, 0);
        if (n <= 0) {
            removeClient(client_fd);
            printf("%s disconnected\n", nickname);
            break;
        }

        message[n] = '\0';
        char broadcast_message[1048];
        sprintf(broadcast_message, "%s: %s", nickname, message);
        broadcast(broadcast_message, client_fd);
    }

    close(client_fd);
    return NULL;
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create a server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the server socket to a port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    pthread_t tid;

    // Handle client connections in separate threads
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                      (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        int err = pthread_create(&tid, NULL, handleConnection, (void*) &new_socket);
        if (err != 0) {
            printf("Can't create thread :[%s]", strerror(err));
        } else {
            pthread_detach(tid);
        }
    }
    return 0;
}