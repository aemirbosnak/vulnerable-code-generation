//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define PORT 8080
#define BUF_SIZE 1024

void handle_client(int client_sock) {
    char buffer[BUF_SIZE];
    int bytes_read;

    // Basic interaction loop for the client
    while ((bytes_read = recv(client_sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        printf("Received: %s\n", buffer);

        // Check for malicious keywords (in a real firewall, more complex rules would apply)
        if (strstr(buffer, "malware") || strstr(buffer, "attack")) {
            printf("Block suspicious activity: %s\n", buffer);
            const char *response = "HTTP/1.1 403 Forbidden\r\n\r\nAccess Denied";
            send(client_sock, response, strlen(response), 0);
        } else {
            const char *response = "HTTP/1.1 200 OK\r\n\r\nYour request was received!";
            send(client_sock, response, strlen(response), 0);
        }
    }

    if (bytes_read < 0) {
        perror("recv");
    }

    close(client_sock);
}

int setup_server() {
    int server_sock;
    struct sockaddr_in server_addr;

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, 3) < 0) {
        perror("listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    return server_sock;
}

void run_firewall() {
    int server_sock = setup_server();
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int client_sock;

    printf("Firewall server running on port %d...\n", PORT);

    while (1) {
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("accept failed");
            continue;
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        handle_client(client_sock);
    }

    close(server_sock);
}

int main() {
    run_firewall();
    return 0;
}