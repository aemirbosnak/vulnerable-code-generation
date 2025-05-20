//FormAI DATASET v1.0 Category: Firewall ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct FirewallRule {
    char direction[4];
    char protocol[4];
    char ip_address[16];
    unsigned int port_range[2];
    struct FirewallRule* next;
} FirewallRule;

enum { MAX_LENGTH = 30 };

bool firewall(FirewallRule* head, char* dir, char* prot, char* ip, unsigned int port) {
    FirewallRule* current_rule = head;
    
    // iterate through all firewall rules
    while (current_rule != NULL) {
        if (!strcmp(current_rule->direction, dir)
            && !strcmp(current_rule->protocol, prot)) {
            // check ip address range
            bool valid_ip_address = true;
            char* token = strtok(current_rule->ip_address, "-");
            unsigned int num1 = atoi(token);
            unsigned int num2 = 0;
            if ((token = strtok(NULL, "-")) != NULL) {
                num2 = atoi(token);
            }
            char* ip_token = strtok(ip, ".");
            for (int i = 0; i < 4; i++) {
                if (ip_token == NULL) {
                    valid_ip_address = false;
                    break;
                }
                unsigned int current_ip_num = atoi(ip_token);
                if (i == 0 && current_ip_num != num1) {
                    valid_ip_address = false;
                    break;
                } else if (i == 1 && !num2 && current_ip_num < num1) {
                    valid_ip_address = false;
                    break;
                } else if (i == 1 && num2 && (current_ip_num < num1 || current_ip_num > num2)) {
                    valid_ip_address = false;
                    break;
                } else {
                    ip_token = strtok(NULL, ".");
                }
            }
            
            // check port range
            bool valid_port_range = false;
            if (current_rule->port_range[0] == 0 && current_rule->port_range[1] == 0) {
                valid_port_range = true;
            } else if (current_rule->port_range[0] == current_rule->port_range[1]) {
                if (port == current_rule->port_range[0]) {
                    valid_port_range = true;
                }
            } else if (port >= current_rule->port_range[0]
                && port <= current_rule->port_range[1]) {
                valid_port_range = true;
            }
            
            if (valid_ip_address && valid_port_range) {
                return true;
            }
            
            // if the packet doesn't match a rule, move on to the next one
            current_rule = current_rule->next;
        }
    }

    return false;
}

int main() {
    FirewallRule* head = NULL;
    char direction[MAX_LENGTH], protocol[MAX_LENGTH], ip_address[MAX_LENGTH];
    unsigned int port_from, port_to;
    
    // read in firewall rules from a file
    FILE* rule_file = fopen("firewall_rules.txt", "r");
    if (rule_file == NULL) {
        printf("Error: Could not open firewall_rules.txt for reading.\n");
        return 1;
    }
    
    char line[MAX_LENGTH*5];
    while (fgets(line, sizeof(line), rule_file)) {
        FirewallRule* new_rule = (FirewallRule*) malloc(sizeof(FirewallRule));
        sscanf(line, "%s %s %s %u-%u", direction, protocol, ip_address,
               &port_from, &port_to);
        strcpy(new_rule->direction, direction);
        strcpy(new_rule->protocol, protocol);
        strcpy(new_rule->ip_address, ip_address);
        new_rule->port_range[0] = port_from;
        new_rule->port_range[1] = port_to;
        new_rule->next = head;
        head = new_rule;
    }
    fclose(rule_file);
    
    // simulate packet traffic to test firewall rules
    FILE* packet_file = fopen("packet_traffic.txt", "r");
    if (packet_file == NULL) {
        printf("Error: Could not open packet_traffic.txt for reading.\n");
        return 1;
    }
    
    char packet_direction[MAX_LENGTH], packet_protocol[MAX_LENGTH], packet_ip_address[MAX_LENGTH];
    unsigned int packet_port;
    while (fscanf(packet_file, "%s %s %s %u", packet_direction, packet_protocol,
                  packet_ip_address, &packet_port) >= 3) {
        if (firewall(head, packet_direction, packet_protocol,
                     packet_ip_address, packet_port)) {
            printf("%s packet allowed by firewall.\n", packet_direction);
        } else {
            printf("%s packet blocked by firewall.\n", packet_direction);
        }
    }
    fclose(packet_file);
    
    // free memory allocated for firewall rules
    FirewallRule* current_rule = head;
    while (current_rule != NULL) {
        FirewallRule* next_rule = current_rule->next;
        free(current_rule);
        current_rule = next_rule;
    }
    
    return 0;
}