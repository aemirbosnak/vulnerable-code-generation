//FormAI DATASET v1.0 Category: Firewall ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024
#define MAX_NUM_RULES 50

typedef struct Firewall {
    char status;
    int id;
    char protocol[MAX_BUF_SIZE];
    char source_ip[MAX_BUF_SIZE];
    char destination_ip[MAX_BUF_SIZE];
    char action[MAX_BUF_SIZE];
} Firewall;

// Read rules from file and return number of rules read
int readRules(char *filename, Firewall *rules) {
    char buffer[MAX_BUF_SIZE];
    int num_rules = 0;

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(buffer, MAX_BUF_SIZE, fp)) {
        sscanf(buffer, "%c %d %s %s %s %s",
                &rules[num_rules].status,
                &rules[num_rules].id,
                rules[num_rules].protocol,
                rules[num_rules].source_ip,
                rules[num_rules].destination_ip,
                rules[num_rules].action);
        num_rules++;
    }

    fclose(fp);

    return num_rules;
}

// Apply firewall rules on incoming packet
bool applyRules(Firewall *rules, int num_rules, char *packet) {
    char protocol[MAX_BUF_SIZE], source_ip[MAX_BUF_SIZE], destination_ip[MAX_BUF_SIZE];
    sscanf(packet, "%s %s %s", protocol, source_ip, destination_ip);

    bool matched = false;

    for (int i = 0; i < num_rules; i++) {
        if (rules[i].status == 'A') {
            if (strcmp(rules[i].protocol, "any") == 0 || strcmp(rules[i].protocol, protocol) == 0) {
                if (strcmp(rules[i].source_ip, "any") == 0 || strcmp(rules[i].source_ip, source_ip) == 0) {
                    if (strcmp(rules[i].destination_ip, "any") == 0 || strcmp(rules[i].destination_ip, destination_ip) == 0) {
                        printf("Packet matched rule %d\n", rules[i].id);
                        if (strcmp(rules[i].action, "permit") == 0) {
                            printf("Packet permitted by rule %d\n", rules[i].id);
                            return true;
                        } else if (strcmp(rules[i].action, "deny") == 0) {
                            printf("Packet denied by rule %d\n", rules[i].id);
                            return false;
                        }
                    }
                }
            }
        }
    }

    return matched;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <config-file> <port>\n", argv[0]);
        exit(1);
    }

    Firewall rules[MAX_NUM_RULES];
    int num_rules = readRules(argv[1], rules);

    int server_sockfd, client_sockfd, server_addr_len;
    char buffer[MAX_BUF_SIZE];

    struct sockaddr_in server_addr, client_addr;

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sockfd < 0) {
        printf("Error creating socket...\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket...\n");
        exit(1);
    }

    if (listen(server_sockfd, 5) < 0) {
        printf("Error listening on socket...\n");
        exit(1);
    }

    printf("Firewall listening on port %s...\n", argv[2]);

    while (true) {
        server_addr_len = sizeof(server_addr);
        client_sockfd = accept(server_sockfd, (struct sockaddr*) &client_addr, &server_addr_len);

        if (client_sockfd < 0) {
            printf("Error accepting connection...\n");
            exit(1);
        }

        printf("Incoming packet...\n");

        read(client_sockfd, buffer, MAX_BUF_SIZE);

        if (applyRules(rules, num_rules, buffer)) {
            write(client_sockfd, "Permitted", strlen("Permitted"));
            printf("Packet permitted.\n");
        } else {
            write(client_sockfd, "Denied", strlen("Denied"));
            printf("Packet denied.\n");
        }

        close(client_sockfd);

        printf("\n");
    }

    return 0;
}