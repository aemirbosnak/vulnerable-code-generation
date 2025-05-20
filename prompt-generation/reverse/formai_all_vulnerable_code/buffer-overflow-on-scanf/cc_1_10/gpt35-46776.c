//FormAI DATASET v1.0 Category: Firewall ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* struct to hold firewall rules */
typedef struct fw_rule {
    char protocol[6];
    char source_ip[16];
    char dest_ip[16];
    int source_port;
    int dest_port;
} fw_rule;

/* function to check if a given IP address is valid */
int is_valid_ip(char *ip) {
    int a, b, c, d;
    if (sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d) != 4) {
        return 0;
    }
    if (a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 || d > 255) {
        return 0;
    }
    return 1;
}

/* function to check if a given port number is valid */
int is_valid_port(int port) {
    if (port < 0 || port > 65535) {
        return 0;
    }
    return 1;
}

/* function to read a firewall rule from standard input */
void read_fw_rule(fw_rule *rule) {
    printf("Enter protocol (TCP/UDP): ");
    scanf("%s", rule->protocol);
    printf("Enter source IP address: ");
    scanf("%s", rule->source_ip);
    while (!is_valid_ip(rule->source_ip)) {
        printf("Invalid IP address. Enter source IP address: ");
        scanf("%s", rule->source_ip);
    }
    printf("Enter destination IP address: ");
    scanf("%s", rule->dest_ip);
    while (!is_valid_ip(rule->dest_ip)) {
        printf("Invalid IP address. Enter destination IP address: ");
        scanf("%s", rule->dest_ip);
    }
    printf("Enter source port number: ");
    scanf("%d", &rule->source_port);
    while (!is_valid_port(rule->source_port)) {
        printf("Invalid port number. Enter source port number: ");
        scanf("%d", &rule->source_port);
    }
    printf("Enter destination port number: ");
    scanf("%d", &rule->dest_port);
    while (!is_valid_port(rule->dest_port)) {
        printf("Invalid port number. Enter destination port number: ");
        scanf("%d", &rule->dest_port);
    }
}

/* function to print a firewall rule */
void print_fw_rule(fw_rule *rule) {
    printf("Protocol: %s\n", rule->protocol);
    printf("Source IP address: %s\n", rule->source_ip);
    printf("Destination IP address: %s\n", rule->dest_ip);
    printf("Source port number: %d\n", rule->source_port);
    printf("Destination port number: %d\n", rule->dest_port);
}

/* function to check if a packet matches a given firewall rule */
int packet_matches_rule(fw_rule *rule, char *protocol, char *source_ip, char *dest_ip, int source_port, int dest_port) {
    if (strcmp(rule->protocol, protocol) != 0) {
        return 0;
    }
    if (strcmp(rule->source_ip, source_ip) != 0) {
        return 0;
    }
    if (strcmp(rule->dest_ip, dest_ip) != 0) {
        return 0;
    }
    if (rule->source_port != source_port) {
        return 0;
    }
    if (rule->dest_port != dest_port) {
        return 0;
    }
    return 1;
}

int main() {
    int num_rules, num_packets, i, j, match;
    fw_rule *rules;
    char protocol[6], source_ip[16], dest_ip[16];
    int source_port, dest_port;

    /* read number of rules */
    printf("Enter number of firewall rules: ");
    scanf("%d", &num_rules);

    /* allocate memory for rules */
    rules = malloc(num_rules * sizeof(fw_rule));

    /* read rules from user input */
    printf("Enter firewall rules:\n");
    for (i = 0; i < num_rules; i++) {
        read_fw_rule(&rules[i]);
    }

    /* read number of packets */
    printf("Enter number of packets to test: ");
    scanf("%d", &num_packets);

    /* test each packet against each rule */
    for (i = 0; i < num_packets; i++) {
        /* read packet from user input */
        printf("Enter packet information:\n");
        printf("Protocol (TCP/UDP): ");
        scanf("%s", protocol);
        printf("Source IP address: ");
        scanf("%s", source_ip);
        printf("Destination IP address: ");
        scanf("%s", dest_ip);
        printf("Source port number: ");
        scanf("%d", &source_port);
        printf("Destination port number: ");
        scanf("%d", &dest_port);

        /* check packet against each rule */
        match = 0;
        for (j = 0; j < num_rules; j++) {
            if (packet_matches_rule(&rules[j], protocol, source_ip, dest_ip, source_port, dest_port)) {
                printf("Packet matches rule %d:\n", j+1);
                print_fw_rule(&rules[j]);
                match = 1;
                break;
            }
        }
        if (!match) {
            printf("Packet does not match any rules.\n");
        }
    }

    /* free memory */
    free(rules);

    return 0;
}