//FormAI DATASET v1.0 Category: Firewall ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define CONFIG_FILE "firewall.conf"
#define MAX_RULES 100

struct fw_rule {
    int allow;
    char* protocol;
    char* src_ip;
    char* dst_ip;
    int src_port;
    int dst_port;
};

struct firewall {
    int port;
    int num_rules;
    struct fw_rule rules[MAX_RULES];
};

int main() {
    struct firewall fw;
    fw.port = 8080;
    fw.num_rules = 0;

    // Read configuration file and populate firewall rules
    FILE* config = fopen(CONFIG_FILE, "r");
    if (config == NULL) {
        perror("Error opening configuration file");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), config)) {
        // Parse rule from configuration file
        struct fw_rule rule;
        char* token = strtok(line, " ");
        rule.allow = atoi(token);
        token = strtok(NULL, " ");
        rule.protocol = token;
        token = strtok(NULL, " ");
        rule.src_ip = token;
        token = strtok(NULL, " ");
        rule.dst_ip = token;
        token = strtok(NULL, " ");
        rule.src_port = atoi(token);
        token = strtok(NULL, " ");
        rule.dst_port = atoi(token);

        // Add rule to firewall
        fw.rules[fw.num_rules] = rule;
        fw.num_rules++;
    }

    // Initialize socket and server address
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in servaddr, cliaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(fw.port);

    // Bind socket to server address
    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        perror("Error binding socket");
        exit(1);
    }

    printf("Listening on port %d\n", fw.port);

    // Listen for incoming connections
    if (listen(sockfd, 10) == -1) {
        perror("Error listening on socket");
        exit(1);
    }

    while (1) {
        socklen_t clilen = sizeof(cliaddr);
        int connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &clilen);

        // Check each rule in firewall for a match
        int matched_rule = 0;
        for (int i = 0; i < fw.num_rules; i++) {
            struct fw_rule rule = fw.rules[i];
            if (strcmp(rule.protocol, "tcp") == 0 &&
                strcmp(rule.src_ip, inet_ntoa(cliaddr.sin_addr)) == 0 &&
                strcmp(rule.dst_ip, inet_ntoa(servaddr.sin_addr)) == 0 &&
                rule.src_port == ntohs(cliaddr.sin_port) &&
                rule.dst_port == fw.port) {
                // Rule matched, allow or deny connection
                if (rule.allow) {
                    printf("Connection allowed from %s:%d to %s:%d\n",
                        inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port),
                        inet_ntoa(servaddr.sin_addr), fw.port);
                    matched_rule = 1;
                    break;
                } else {
                    printf("Connection denied from %s:%d to %s:%d\n",
                        inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port),
                        inet_ntoa(servaddr.sin_addr), fw.port);
                    matched_rule = 1;
                    close(connfd);
                    break;
                }
            }
        }

        // No rule matched, default to allowing connection
        if (!matched_rule) {
            printf("Connection allowed from %s:%d to %s:%d\n",
                inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port),
                inet_ntoa(servaddr.sin_addr), fw.port);
        }

        close(connfd);
    }

    return 0;
}