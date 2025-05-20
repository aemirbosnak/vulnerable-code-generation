//FormAI DATASET v1.0 Category: Firewall ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

pthread_t thread_id[MAX_SIZE];
int thread_count = 0;
char *blacklist[MAX_SIZE];
int blacklist_count = 0;

void *process_request(void *arg) {
    int client_fd = (int) arg;
    char request[MAX_SIZE];
    bzero(request, MAX_SIZE);
    read(client_fd, request, MAX_SIZE);
    for (int i = 0; i < blacklist_count; i++) {
        if (strstr(request, blacklist[i])) {
            printf("Blocked: %s\n", request);
            close(client_fd);
            pthread_exit(NULL);
        }
    }
    printf("Passed: %s\n", request);
    close(client_fd);
    pthread_exit(NULL);
}

void read_blacklist() {
    FILE *file = fopen("blacklist.txt", "r");
    if (file) {
        char buffer[MAX_SIZE];
        while (fgets(buffer, MAX_SIZE, file) != NULL) {
            if (buffer[strlen(buffer)-1] == '\n') buffer[strlen(buffer)-1] = '\0';
            blacklist[blacklist_count++] = strdup(buffer);
        }
        fclose(file);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./firewall <port>\n");
        exit(1);
    }

    int port = atoi(argv[1]);
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    listen(server_fd, 100);

    printf("Firewall is running on port %d\n", port);

    read_blacklist();

    while (1) {
        if (thread_count < MAX_SIZE) {
            struct sockaddr_in client_addr;
            socklen_t client_len = sizeof(client_addr);
            int client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_len);
            if (client_fd < 0) {
                printf("Error accepting client\n");
            } else {
                pthread_create(&thread_id[thread_count++], NULL, process_request, (void *) client_fd);
            }
        }
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(thread_id[i], NULL);
    }

    close(server_fd);
    exit(0);
}