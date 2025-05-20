//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <pthread.h>

// Structure to store IP address and port number
struct sockaddr_in addr;

// Structure to store thread arguments
struct thread_args {
    int sockfd;
    struct sockaddr_in *addr;
};

// Function to get the IP address and port number from the user
void get_ip_port(struct sockaddr_in *addr) {
    char ip[16];
    int port;

    printf("Enter the IP address: ");
    scanf("%s", ip);
    printf("Enter the port number: ");
    scanf("%d", &port);

    // Convert the IP address to a binary format
    inet_pton(AF_INET, ip, &addr->sin_addr);

    // Set the port number
    addr->sin_port = htons(port);

    // Set the address family
    addr->sin_family = AF_INET;
}

// Function to create a socket and connect to the server
int create_socket(struct sockaddr_in *addr) {
    int sockfd;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)addr, sizeof(*addr)) == -1) {
        perror("connect");
        exit(1);
    }

    return sockfd;
}

// Function to send a message to the server
void send_message(int sockfd, char *message) {
    // Send the message to the server
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        exit(1);
    }
}

// Function to receive a message from the server
char *receive_message(int sockfd) {
    char *message;
    int len;

    // Receive the message from the server
    len = recv(sockfd, message, 1024, 0);
    if (len == -1) {
        perror("recv");
        exit(1);
    }

    // Null-terminate the message
    message[len] = '\0';

    return message;
}

// Function to close the socket
void close_socket(int sockfd) {
    // Close the socket
    close(sockfd);
}

// Function to perform network topology mapping
void *network_topology_mapping(void *args) {
    struct thread_args *thread_args = (struct thread_args *)args;

    // Create a socket and connect to the server
    int sockfd = create_socket(thread_args->addr);

    // Send a message to the server
    send_message(sockfd, "GET_NETWORK_MAP");

    // Receive a message from the server
    char *message = receive_message(sockfd);

    // Print the network topology map
    printf("%s\n", message);

    // Close the socket
    close_socket(sockfd);

    return NULL;
}

// Main function
int main() {
    // Get the IP address and port number from the user
    get_ip_port(&addr);

    // Create a thread
    pthread_t thread;
    struct thread_args thread_args;
    thread_args.sockfd = create_socket(&addr);
    thread_args.addr = &addr;
    pthread_create(&thread, NULL, network_topology_mapping, &thread_args);

    // Join the thread
    pthread_join(thread, NULL);

    return 0;
}