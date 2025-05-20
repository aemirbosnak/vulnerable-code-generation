//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep function
#include <signal.h> // for signal function
#include <netinet/in.h> // for SO_REUSEADDR, IPPROTO_TCP, struct sockaddr_in
#include <sys/socket.h> // for socket functions
#include <sys/types.h> // for socket functions
#include <errno.h> // for errno variable

#define BUFFER_SIZE 1024
#define MIN_QOS 50.0
#define MAX_QOS 70.0

volatile sig_atomic_t running = 1; // used to stop the program gracefully
double qos_value = 0.0;
int tcp_server_socket; // socket for TCP server

// function to handle SIGINT signal and stop the program gracefully
void handle_sigint(int sig) {
    running = 0;
}

// function to initialize the TCP server socket
int init_server_socket() {
    tcp_server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (tcp_server_socket < 0) {
        printf("Error: failed to create TCP server socket, error code %d\n", errno);
        return -1;
    }

    int opt = 1;
    if (setsockopt(tcp_server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        printf("Error: failed to set TCP server socket options, error code %d\n", errno);
        return -1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(2222);

    if (bind(tcp_server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printf("Error: failed to bind TCP server socket to port, error code %d\n", errno);
        return -1;
    }

    if (listen(tcp_server_socket, 1) < 0) {
        printf("Error: failed to start listening on TCP server socket, error code %d\n", errno);
        return -1;
    }

    return tcp_server_socket;
}

// function to accept and handle incoming client connections
void handle_client() {
    char buffer[BUFFER_SIZE];
    int client_socket = accept(tcp_server_socket, NULL, NULL);
    if (client_socket < 0) {
        printf("Error: failed to accept incoming client connection, error code %d\n", errno);
        return;
    }
    printf("Client connected\n");

    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        printf("Error: failed to receive data from client, error code %d\n", errno);
        close(client_socket);
        return;
    }

    buffer[bytes_received] = '\0';
    qos_value = atof(buffer);

    printf("QoS value received: %.2f\n", qos_value);

    if (qos_value < MIN_QOS) {
        printf("QoS value too low, taking actions to boost the network\n");
        // insert code here to boost the network quality of service
    }

    if (qos_value > MAX_QOS) {
        printf("QoS value too high, reducing network load\n");
        // insert code here to reduce the network load
    }

    close(client_socket);
}

int main() {
    signal(SIGINT, handle_sigint); // handle SIGINT signal to stop the program gracefully

    // initialize the TCP server socket
    if (init_server_socket() < 0) {
        printf("Error: failed to initialize TCP server socket\n");
        return -1;
    }

    printf("QoS monitor program started\n");

    while (running) {
        handle_client();
        sleep(1);
    }

    printf("QoS monitor program stopped\n");
    close(tcp_server_socket);
    return 0;
}