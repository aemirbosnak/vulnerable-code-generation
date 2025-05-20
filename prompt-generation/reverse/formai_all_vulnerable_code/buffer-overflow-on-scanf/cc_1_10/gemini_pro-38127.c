//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_LEN 1024

// Create a socket and connect to the server
int create_client_socket(char *ip_addr, int port) {
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_addr, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    if (connect(client_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return client_fd;
}

// Send a message to the server
int send_message(int client_fd, char *msg) {
    int len = strlen(msg);
    int sent_bytes = send(client_fd, msg, len, 0);
    if (sent_bytes < 0) {
        perror("send");
        return -1;
    }
    return sent_bytes;
}

// Receive a message from the server
int receive_message(int client_fd, char *msg) {
    int len = recv(client_fd, msg, MAX_MSG_LEN, 0);
    if (len < 0) {
        perror("recv");
        return -1;
    }
    return len;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_addr = argv[1];
    int port = atoi(argv[2]);

    int client_fd = create_client_socket(ip_addr, port);

    char msg[MAX_MSG_LEN];
    while (1) {
        printf("Enter a message to send to the server: ");
        scanf("%s", msg);

        int sent_bytes = send_message(client_fd, msg);
        if (sent_bytes < 0) {
            break;
        }

        int recv_bytes = receive_message(client_fd, msg);
        if (recv_bytes < 0) {
            break;
        }

        printf("Received message from server: %s\n", msg);
    }

    close(client_fd);

    return 0;
}