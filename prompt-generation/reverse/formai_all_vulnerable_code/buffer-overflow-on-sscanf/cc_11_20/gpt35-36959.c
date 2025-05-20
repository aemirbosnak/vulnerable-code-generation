//FormAI DATASET v1.0 Category: Firewall ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 2048
#define MAX_RULES 100
#define MAX_IP_LEN 16
#define MAX_PORT_LEN 16
#define MAX_PROTOCOL_LEN 8

// Firewall rule struct
typedef struct {
    char ip[MAX_IP_LEN];
    char port[MAX_PORT_LEN];
    char protocol[MAX_PROTOCOL_LEN];
} Rule;

int main(int argc, char** argv) {
    // Read firewall rule file
    Rule rules[MAX_RULES];
    int num_rules = 0;
    FILE* rule_file = fopen("firewall_rules.txt", "r");
    if (rule_file == NULL) {
        printf("Error: could not open firewall_rules.txt\n");
        exit(1);
    }
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, rule_file)) {
        if (num_rules >= MAX_RULES) {
            printf("Error: too many firewall rules\n");
            exit(1);
        }
        sscanf(buffer, "%s %s %s", rules[num_rules].ip, rules[num_rules].port, rules[num_rules].protocol);
        num_rules++;
    }
    fclose(rule_file);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    // Bind socket to port
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(80);
    if (bind(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Error: could not bind socket to port 80\n");
        exit(1);
    }

    // Listen for incoming connections
    listen(sock, 5);

    // Handle incoming connections
    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            printf("Error: could not accept incoming connection\n");
            continue;
        }

        // Read incoming data
        char buffer[BUFFER_SIZE];
        int read_size = recv(client_sock, buffer, BUFFER_SIZE, 0);
        if (read_size <= 0) {
            printf("Error: could not read incoming data\n");
            close(client_sock);
            continue;
        }

        // Check incoming data against firewall rules
        int allowed = 0;
        struct sockaddr_in addr;
        socklen_t addr_len = sizeof(addr);
        getpeername(client_sock, (struct sockaddr*)&addr, &addr_len);
        char client_ip[MAX_IP_LEN];
        inet_ntop(AF_INET, &addr.sin_addr, client_ip, MAX_IP_LEN);
        char client_port[MAX_PORT_LEN];
        sprintf(client_port, "%d", ntohs(addr.sin_port));
        char* client_protocol = "TCP";
        for (int i = 0; i < num_rules; i++) {
            if (strcmp(rules[i].ip, client_ip) == 0 && strcmp(rules[i].port, client_port) == 0 && strcmp(rules[i].protocol, client_protocol) == 0) {
                allowed = 1;
                break;
            }
        }

        // Send response based on whether incoming data is allowed or not
        char* response;
        if (allowed) {
            response = "HTTP/1.1 200 OK\r\n\r\n";
        } else {
            response = "HTTP/1.1 403 Forbidden\r\n\r\n";
        }
        int sent_size = send(client_sock, response, strlen(response), 0);
        if (sent_size < strlen(response)) {
            printf("Error: could not send response\n");
        }

        // Close connection
        close(client_sock);
    }

    // Close socket
    close(sock);

    return 0;
}