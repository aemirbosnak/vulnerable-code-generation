//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 256
#define CLIENT_COUNT 3

// Define some intrusion patterns
const char *patterns[] = {
    "Failed login attempt",
    "Unauthorized access",
    "SQL injection",
    NULL
};

void *client_function(void *arg) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *messages[] = {
        "User1: Failed login attempt",
        "User2: Successfully logged in",
        "User2: Unauthorized access",
        "User3: Database connection established",
        "User1: SQL injection attempt detected",
        NULL
    };

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // use appropriate server IP in a real scenario
    server_addr.sin_port = htons(PORT);

    for (int i = 0; messages[i] != NULL; i++) {
        sendto(sock, messages[i], strlen(messages[i]), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        sleep(1); // simulate delay in log generation
    }

    close(sock);
    return NULL;
}

void *server_function(void *arg) {
    int sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    while (1) {
        int n = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &client_len);
        
        buffer[n] = '\0'; // Null-terminate the message

        // Check for intrusion patterns
        for (int i = 0; patterns[i] != NULL; i++) {
            if (strstr(buffer, patterns[i]) != NULL) {
                printf("ALERT: Intrusion detected in log: %s\n", buffer);
                break;
            }
        }
    }

    close(sock);
    return NULL;
}

int main() {
    pthread_t server_thread;
    pthread_t client_threads[CLIENT_COUNT];

    // Start the server thread
    pthread_create(&server_thread, NULL, server_function, NULL);

    // Start client threads
    for (int i = 0; i < CLIENT_COUNT; i++) {
        pthread_create(&client_threads[i], NULL, client_function, NULL);
    }

    // Join client threads
    for (int i = 0; i < CLIENT_COUNT; i++) {
        pthread_join(client_threads[i], NULL);
    }

    // The server will keep running; you might want to implement a graceful shutdown mechanism
    pthread_cancel(server_thread);
    pthread_join(server_thread, NULL);

    return 0;
}