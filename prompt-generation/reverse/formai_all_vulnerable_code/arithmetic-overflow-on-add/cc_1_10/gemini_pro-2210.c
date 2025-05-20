//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

// Define robot movement commands
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define STOP 0

// Define the robot's state
typedef struct {
    int x;
    int y;
    int direction;
} robot_state;

// Define the message format
typedef struct {
    int command;
    robot_state state;
} message;

// Create a socket for communication
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }
    return sockfd;
}

// Bind the socket to an address
void bind_socket(int sockfd, struct sockaddr_in *addr) {
    int bind_status = bind(sockfd, (struct sockaddr *)addr, sizeof(*addr));
    if (bind_status == -1) {
        perror("bind");
        exit(1);
    }
}

// Listen for connections on the socket
void listen_socket(int sockfd) {
    int listen_status = listen(sockfd, 5);
    if (listen_status == -1) {
        perror("listen");
        exit(1);
    }
}

// Accept a connection on the socket
int accept_connection(int sockfd) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sockfd == -1) {
        perror("accept");
        exit(1);
    }
    return client_sockfd;
}

// Send a message to the client
void send_message(int sockfd, message *msg) {
    int send_status = send(sockfd, msg, sizeof(*msg), 0);
    if (send_status == -1) {
        perror("send");
        exit(1);
    }
}

// Receive a message from the client
void receive_message(int sockfd, message *msg) {
    int recv_status = recv(sockfd, msg, sizeof(*msg), 0);
    if (recv_status == -1) {
        perror("recv");
        exit(1);
    }
}

// Thread function to handle client connections
void *handle_client(void *arg) {
    int client_sockfd = (int)arg;
    message msg;

    // Receive the initial state of the robot
    receive_message(client_sockfd, &msg);
    robot_state state = msg.state;

    // Continuously receive commands and update the robot's state
    while (1) {
        receive_message(client_sockfd, &msg);
        switch (msg.command) {
            case FORWARD:
                state.y++;
                break;
            case BACKWARD:
                state.y--;
                break;
            case LEFT:
                state.x--;
                break;
            case RIGHT:
                state.x++;
                break;
            case STOP:
                break;
        }

        // Send the updated state of the robot back to the client
        msg.state = state;
        send_message(client_sockfd, &msg);
    }

    // Close the client socket and free resources
    close(client_sockfd);
    pthread_exit(NULL);
}

int main() {
    // Create a socket for communication
    int sockfd = create_socket();

    // Bind the socket to an address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5000);
    addr.sin_addr.s_addr = INADDR_ANY;
    bind_socket(sockfd, &addr);

    // Listen for connections on the socket
    listen_socket(sockfd);

    // Create a thread pool to handle client connections
    pthread_t threads[5];
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, handle_client, NULL);
    }

    // Accept connections and dispatch them to threads
    while (1) {
        int client_sockfd = accept_connection(sockfd);
        pthread_create(&threads[0], NULL, handle_client, (void *)client_sockfd);
    }

    // Close the server socket and free resources
    close(sockfd);
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}