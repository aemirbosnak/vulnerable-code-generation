//FormAI DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#define MAX_RULES 1000          // Maximum number of rules allowed
#define MAX_RULE_SIZE 100       // Maximum size of each rule
#define MAX_PACKET_SIZE 1500    // Maximum packet size

typedef struct {
    char src_ip[16];            // Source IP address
    char dest_ip[16];           // Destination IP address
    uint8_t protocol;           // Protocol number (6 for TCP, 17 for UDP)
    uint16_t src_port;          // Source port number
    uint16_t dest_port;         // Destination port number
    uint8_t action;             // Action to perform (0 for block, 1 for allow)
} rule_t;

int num_rules = 0;              // Number of rules currently loaded
rule_t rules[MAX_RULES];        // Array of rules

void add_rule(char *rule_str) {
    if (num_rules == MAX_RULES) {
        fprintf(stderr, "Error: Maximum number of rules exceeded\n");
        return;
    }

    rule_t new_rule;
    int result = sscanf(rule_str, "%15s %15s %hhu %hu %hu %hhu",
            new_rule.src_ip, new_rule.dest_ip, &new_rule.protocol,
            &new_rule.src_port, &new_rule.dest_port, &new_rule.action);
    if (result == 6) {
        rules[num_rules] = new_rule;
        num_rules++;
    } else {
        fprintf(stderr, "Error: Invalid rule format\n");
    }
}

uint8_t check_packet(char *packet) {
    char src_ip[16], dest_ip[16];
    uint32_t src_ip_val, dest_ip_val;
    uint16_t src_port, dest_port;
    uint8_t protocol;

    // Extract packet header fields
    memcpy(&src_ip_val, &packet[0], 4);
    memcpy(&dest_ip_val, &packet[4], 4);
    memcpy(&protocol, &packet[9], 1);
    memcpy(&src_port, &packet[20], 2);
    memcpy(&dest_port, &packet[22], 2);

    // Convert IP addresses to string format
    sprintf(src_ip, "%u.%u.%u.%u", (src_ip_val >> 24) & 0xff, (src_ip_val >> 16) & 0xff,
            (src_ip_val >> 8) & 0xff, src_ip_val & 0xff);
    sprintf(dest_ip, "%u.%u.%u.%u", (dest_ip_val >> 24) & 0xff, (dest_ip_val >> 16) & 0xff,
            (dest_ip_val >> 8) & 0xff, dest_ip_val & 0xff);

    // Check packet against each rule
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].src_ip, src_ip) == 0 || strcmp(rules[i].src_ip, "*") == 0) {
            if (strcmp(rules[i].dest_ip, dest_ip) == 0 || strcmp(rules[i].dest_ip, "*") == 0) {
                if (rules[i].protocol == protocol) {
                    if (rules[i].src_port == src_port || rules[i].src_port == 0) {
                        if (rules[i].dest_port == dest_port || rules[i].dest_port == 0) {
                            return rules[i].action;
                        }
                    }
                }
            }
        }
    }

    // Packet did not match any rule
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: No rules file specified\n");
        return 1;
    }

    // Load rules from file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open rules file\n");
        return 1;
    }
    char buffer[MAX_RULE_SIZE];
    while (fgets(buffer, MAX_RULE_SIZE, fp)) {
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline character
        add_rule(buffer);
    }
    fclose(fp);

    // Run firewall loop
    char packet[MAX_PACKET_SIZE];
    while (1) {
        ssize_t packet_size = read(STDIN_FILENO, packet, MAX_PACKET_SIZE);
        if (packet_size < 0) {
            fprintf(stderr, "Error: Unable to read packet\n");
            return 1;
        } else if (packet_size == 0) {
            break;  // End of input stream
        }
        uint8_t action = check_packet(packet);
        if (action == 0) {
            continue;  // Block packet
        }
        write(STDOUT_FILENO, packet, packet_size);  // Allow packet
    }

    return 0;
}