//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 100

struct rule {
    char source_ip[16];
    char destination_ip[16];
    int source_port;
    int destination_port;
    char protocol[10];
    int action;
};

struct firewall {
    struct rule rules[MAX_RULES];
    int num_rules;
};

struct firewall firewall;

int load_rules(char *filename) {
    FILE *fp;
    char line[MAX_RULE_LENGTH];
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    i = 0;
    while (fgets(line, MAX_RULE_LENGTH, fp) != NULL) {
        if (line[0] == '#') {
            continue;
        }

        if (sscanf(line, "%s %s %d %d %s %d",
                firewall.rules[i].source_ip,
                firewall.rules[i].destination_ip,
                &firewall.rules[i].source_port,
                &firewall.rules[i].destination_port,
                firewall.rules[i].protocol,
                &firewall.rules[i].action) != 6) {
            fprintf(stderr, "Invalid rule: %s", line);
            continue;
        }

        i++;
        if (i >= MAX_RULES) {
            fprintf(stderr, "Too many rules: %d", i);
            break;
        }
    }

    fclose(fp);

    firewall.num_rules = i;

    return 0;
}

int check_packet(struct sockaddr_in *source, struct sockaddr_in *destination, int protocol, int port) {
    int i;

    for (i = 0; i < firewall.num_rules; i++) {
        if (strcmp(firewall.rules[i].source_ip, inet_ntoa(source->sin_addr)) == 0 &&
                strcmp(firewall.rules[i].destination_ip, inet_ntoa(destination->sin_addr)) == 0 &&
                firewall.rules[i].source_port == ntohs(source->sin_port) &&
                firewall.rules[i].destination_port == ntohs(destination->sin_port) &&
                strcmp(firewall.rules[i].protocol, protocol) == 0) {
            return firewall.rules[i].action;
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    int port;
    int action;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    if (load_rules("firewall.rules") < 0) {
        exit(1);
    }

    while (1) {
        client_len = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        action = check_packet(&client_addr, &server_addr, "tcp", ntohs(client_addr.sin_port));
        if (action == 0) {
            // Allow packet
            printf("Allowed packet from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        } else if (action == 1) {
            // Drop packet
            printf("Dropped packet from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        } else {
            // Log packet
            printf("Logged packet from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        }

        close(newsockfd);
    }

    close(sockfd);

    return 0;
}