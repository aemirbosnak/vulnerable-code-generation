//FormAI DATASET v1.0 Category: Firewall ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store IP addresses
typedef struct {
    unsigned char octet1;
    unsigned char octet2;
    unsigned char octet3;
    unsigned char octet4;
} IPAddress;

// Define a structure to store rules
typedef struct {
    char action;
    IPAddress source_addr;
    IPAddress dest_addr;
    unsigned short source_port;
    unsigned short dest_port;
} Rule;

// Compare two IP addresses
int compare_ip_address(const IPAddress *ip_addr1, const IPAddress *ip_addr2) {
    if (ip_addr1->octet1 == ip_addr2->octet1 &&
        ip_addr1->octet2 == ip_addr2->octet2 &&
        ip_addr1->octet3 == ip_addr2->octet3 &&
        ip_addr1->octet4 == ip_addr2->octet4)
    {
        return 1;
    } else {
        return 0;
    }
}

// Check if an IP address matches a rule
int matches_rule(const Rule *rule, IPAddress *ip_addr, unsigned short port) {
    if (rule->source_addr.octet1 != 0 && !compare_ip_address(&rule->source_addr, ip_addr)) {
        return 0;
    }
    if (rule->dest_addr.octet1 != 0 && !compare_ip_address(&rule->dest_addr, ip_addr)) {
        return 0;
    }
    if (rule->source_port != 0 && rule->source_port != port) {
        return 0;
    }
    if (rule->dest_port != 0 && rule->dest_port != port) {
        return 0;
    }
    return 1;
}

// Print an IP address in dotted decimal notation
void print_ip_address(const IPAddress *ip_addr) {
    printf("%d.%d.%d.%d", ip_addr->octet1, ip_addr->octet2, ip_addr->octet3, ip_addr->octet4);
}

int main() {
    // Initialize the firewall rules
    Rule rules[3];
    rules[0].action = 'A';
    rules[0].source_addr.octet1 = 192;
    rules[0].source_addr.octet2 = 168;
    rules[0].source_addr.octet3 = 1;
    rules[0].source_addr.octet4 = 1;
    rules[0].dest_addr.octet1 = 8;
    rules[0].dest_addr.octet2 = 8;
    rules[0].dest_addr.octet3 = 8;
    rules[0].dest_addr.octet4 = 8;
    rules[0].source_port = 0;
    rules[0].dest_port = 80;
    
    rules[1].action = 'D';
    rules[1].source_addr.octet1 = 0;
    rules[1].source_addr.octet2 = 0;
    rules[1].source_addr.octet3 = 0;
    rules[1].source_addr.octet4 = 0;
    rules[1].dest_addr.octet1 = 0;
    rules[1].dest_addr.octet2 = 0;
    rules[1].dest_addr.octet3 = 0;
    rules[1].dest_addr.octet4 = 0;
    rules[1].source_port = 0;
    rules[1].dest_port = 0;
    
    rules[2].action = 'A';
    rules[2].source_addr.octet1 = 172;
    rules[2].source_addr.octet2 = 16;
    rules[2].source_addr.octet3 = 0;
    rules[2].source_addr.octet4 = 0;
    rules[2].dest_addr.octet1 = 8;
    rules[2].dest_addr.octet2 = 8;
    rules[2].dest_addr.octet3 = 8;
    rules[2].dest_addr.octet4 = 8;
    rules[2].source_port = 0;
    rules[2].dest_port = 443;
    
    // Get the IP address and port from the user
    char ip_string[16];
    printf("Enter an IP address: ");
    scanf("%s", ip_string);
    IPAddress ip_addr;
    sscanf(ip_string, "%d.%d.%d.%d", &ip_addr.octet1, &ip_addr.octet2, &ip_addr.octet3, &ip_addr.octet4);
    unsigned short port;
    printf("Enter a port number: ");
    scanf("%hu", &port);
    
    // Check if the IP address and port match any of the rules
    int blocked = 0;
    int i;
    for (i = 0; i < 3; i++) {
        if (matches_rule(&rules[i], &ip_addr, port)) {
            if (rules[i].action == 'A') {
                blocked = 1;
            } else {
                blocked = 0;
            }
            break;
        }
    }
    
    // Print the result
    printf("IP address: ");
    print_ip_address(&ip_addr);
    printf("\n");
    printf("Port: %hu\n", port);
    if (blocked) {
        printf("Blocked\n");
    } else {
        printf("Not blocked\n");
    }
    
    return 0;
}