//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: distributed
// database_server.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define MAX_ENTRIES 100

typedef struct {
    int id;
    char data[256];
} DatabaseEntry;

DatabaseEntry db[MAX_ENTRIES];
int entry_count = 0;

void add_entry(const char *data) {
    if (entry_count < MAX_ENTRIES) {
        db[entry_count].id = entry_count + 1;
        strncpy(db[entry_count].data, data, sizeof(db[entry_count].data));
        entry_count++;
    } else {
        printf("Database is full. Cannot add more entries.\n");
    }
}

void list_entries(int sockfd) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "Current Entries:\n");
    for (int i = 0; i < entry_count; i++) {
        snprintf(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), "ID: %d, Data: %s\n", db[i].id, db[i].data);
    }
    send(sockfd, buffer, strlen(buffer), 0);
}

void handle_client(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';
        if (strncmp(buffer, "ADD", 3) == 0) {
            add_entry(buffer + 4);
            send(sockfd, "Entry added.\n", 14, 0);
        } else if (strncmp(buffer, "LIST", 4) == 0) {
            list_entries(sockfd);
        } else {
            send(sockfd, "Unknown command.\n", 17, 0);
        }
    }
    close(sockfd);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) >= 0) {
        handle_client(new_socket);
    }

    if (new_socket < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    close(server_fd);
    return 0;
}