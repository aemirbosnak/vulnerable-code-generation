//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 256

// Rule structure
typedef struct rule {
    char source_ip[16];
    char destination_ip[16];
    char protocol[16];
    char port[16];
    bool allow;
} rule;

// Firewall rules
rule rules[MAX_RULES];

// Number of rules
int num_rules = 0;

// Load firewall rules from a file
int load_rules(const char *filename) {
    FILE *fp;
    char line[MAX_RULE_LENGTH];
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    while (fgets(line, MAX_RULE_LENGTH, fp) != NULL) {
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }

        sscanf(line, "%s %s %s %s %d", rules[num_rules].source_ip, rules[num_rules].destination_ip, rules[num_rules].protocol, rules[num_rules].port, &rules[num_rules].allow);
        num_rules++;
    }

    fclose(fp);

    return 0;
}

// Check if a packet is allowed by the firewall
int check_packet(const char *source_ip, const char *destination_ip, const char *protocol, const char *port) {
    int i;

    for (i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].source_ip, source_ip) == 0 && strcmp(rules[i].destination_ip, destination_ip) == 0 && strcmp(rules[i].protocol, protocol) == 0 && strcmp(rules[i].port, port) == 0) {
            return rules[i].allow;
        }
    }

    return -1;
}

// Main loop
int main(int argc, char **argv) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[256];
    int n;

    // Load firewall rules
    if (load_rules("firewall.rules") < 0) {
        perror("load_rules");
        return -1;
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Set up the server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        return -1;
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        return -1;
    }

    // Main loop
    while (1) {
        // Accept an incoming connection
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        // Read the packet from the client
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 256);
        if (n < 0) {
            perror("read");
            continue;
        }

        // Parse the packet
        char source_ip[16], destination_ip[16], protocol[16], port[16];
        sscanf(buffer, "%s %s %s %s", source_ip, destination_ip, protocol, port);

        // Check if the packet is allowed by the firewall
        int allowed = check_packet(source_ip, destination_ip, protocol, port);
        if (allowed == -1) {
            // Packet is not allowed
            const char *response = "Packet not allowed\n";
            write(newsockfd, response, strlen(response));
        } else {
            // Packet is allowed
            const char *response = "Packet allowed\n";
            write(newsockfd, response, strlen(response));
        }

        // Close the connection
        close(newsockfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}