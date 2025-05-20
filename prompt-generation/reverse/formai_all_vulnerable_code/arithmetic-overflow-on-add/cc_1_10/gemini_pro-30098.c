//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define MAX_QUESTIONS 100
#define MAX_ANSWERS 100

struct client_info {
    int socket;
    char name[100];
    int score;
};

struct question {
    char question[1000];
    char answers[MAX_ANSWERS][100];
    int correct_answer;
};

struct exam {
    char name[100];
    int num_questions;
    struct question questions[MAX_QUESTIONS];
};

struct server_info {
    int port;
    int num_clients;
    struct client_info clients[MAX_CLIENTS];
    struct exam exam;
};

struct server_info server;

void *client_handler(void *args) {
    struct client_info *client = (struct client_info *)args;
    int socket = client->socket;

    char buffer[1024];
    int n;

    // Send the client the exam name and number of questions.
    sprintf(buffer, "%s\n%d", server.exam.name, server.exam.num_questions);
    n = send(socket, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        return NULL;
    }

    // Send the client the questions and answers.
    for (int i = 0; i < server.exam.num_questions; i++) {
        sprintf(buffer, "%s\n", server.exam.questions[i].question);
        n = send(socket, buffer, strlen(buffer), 0);
        if (n < 0) {
            perror("send");
            return NULL;
        }

        for (int j = 0; j < MAX_ANSWERS; j++) {
            sprintf(buffer, "%s\n", server.exam.questions[i].answers[j]);
            n = send(socket, buffer, strlen(buffer), 0);
            if (n < 0) {
                perror("send");
                return NULL;
            }
        }
    }

    // Receive the client's answers.
    for (int i = 0; i < server.exam.num_questions; i++) {
        n = recv(socket, buffer, 1024, 0);
        if (n < 0) {
            perror("recv");
            return NULL;
        }

        int answer = atoi(buffer);
        if (answer == server.exam.questions[i].correct_answer) {
            client->score++;
        }
    }

    // Send the client their score.
    sprintf(buffer, "%d", client->score);
    n = send(socket, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        return NULL;
    }

    // Close the client's socket.
    close(socket);

    return NULL;
}

int main() {
    // Initialize the server.
    server.port = 8080;
    server.num_clients = 0;

    // Load the exam from a file.
    FILE *fp = fopen("exam.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fscanf(fp, "%s", server.exam.name);
    fscanf(fp, "%d", &server.exam.num_questions);

    for (int i = 0; i < server.exam.num_questions; i++) {
        fscanf(fp, "%s", server.exam.questions[i].question);

        for (int j = 0; j < MAX_ANSWERS; j++) {
            fscanf(fp, "%s", server.exam.questions[i].answers[j]);
        }

        fscanf(fp, "%d", &server.exam.questions[i].correct_answer);
    }

    fclose(fp);

    // Create a socket.
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind the socket to an address.
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(server.port);

    int bind_status = bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (bind_status < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections.
    int listen_status = listen(server_socket, MAX_CLIENTS);
    if (listen_status < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept incoming connections.
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);

        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Add the client to the list of clients.
        server.clients[server.num_clients].socket = client_socket;
        server.num_clients++;

        // Create a thread to handle the client.
        pthread_t thread;
        pthread_create(&thread, NULL, client_handler, &server.clients[server.num_clients - 1]);
    }

    // Close the server socket.
    close(server_socket);

    return EXIT_SUCCESS;
}