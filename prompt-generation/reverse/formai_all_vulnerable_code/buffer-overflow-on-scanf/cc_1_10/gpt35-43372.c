//FormAI DATASET v1.0 Category: Firewall ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

// Firewall Rule structure
typedef struct Firewall {
    long lower_ip;
    long upper_ip;
    long lower_port;
    long upper_port;
    bool allow;
} Firewall;

// Function to read a firewall rule
void read_firewall(Firewall *fw) {
    printf("\n---Enter Firewall Rule---\n");
    printf("Enter lower IP address: ");
    scanf("%ld", &fw->lower_ip);
    printf("Enter upper IP address: ");
    scanf("%ld", &fw->upper_ip);
    printf("Enter lower port: ");
    scanf("%ld", &fw->lower_port);
    printf("Enter upper port: ");
    scanf("%ld", &fw->upper_port);
    printf("Allow/Deny? (0/1): ");
    scanf("%d", &fw->allow);
}

// Function to print a firewall rule
void print_firewall(Firewall fw) {
    printf("\n-----------------------\n");
    printf("IP: %ld-%ld\n", fw.lower_ip, fw.upper_ip);
    printf("Port: %ld-%ld\n", fw.lower_port, fw.upper_port);
    printf("Allow/Deny: %s\n", fw.allow ? "Allow" : "Deny");
    printf("-----------------------\n");
}

// Function to check if an IP address is valid
bool is_valid_ip(long ip) {
    return ip >= 0 && ip <= ULONG_MAX;
}

// Function to check if a port number is valid
bool is_valid_port(long port) {
    return port >= 0 && port < 65536;
}

// Function to check if an IP address is allowed/denied by a firewall rule
bool check_ip(long ip, Firewall fw) {
    return ip >= fw.lower_ip && ip <= fw.upper_ip;
}

// Function to check if a port number is allowed/denied by a firewall rule
bool check_port(long port, Firewall fw) {
    return port >= fw.lower_port && port <= fw.upper_port;
}

// Function to check if a packet is allowed/denied by a firewall rule
bool check_packet(long ip, long port, Firewall fw) {
    return check_ip(ip, fw) && check_port(port, fw);
}

// Function to process a packet and check if it is allowed/denied by the firewall rules
bool process_packet(long ip, long port, Firewall *rules, int num_rules) {
    bool allow_packet = false;
    for (int i = 0; i < num_rules; i++) {
        if (check_packet(ip, port, rules[i])) {
            allow_packet = rules[i].allow;
        }
    }
    return allow_packet;
}

int main() {
    int num_rules;
    printf("Enter number of firewall rules: ");
    scanf("%d", &num_rules);

    // Memory allocation for Firewall rules
    Firewall *rules = (Firewall*) calloc(num_rules, sizeof(Firewall));
    if (rules == NULL) {
        printf("Memory allocation error!\n");
        return -1;
    }

    // Reading all firewall rules
    for (int i = 0; i < num_rules; i++) {
        read_firewall(&rules[i]);
    }

    // Printing all firewall rules
    printf("\n---All Firewall Rules---\n");
    for (int i = 0; i < num_rules; i++) {
        print_firewall(rules[i]);
    }

    // Processing packets and printing results
    long ip, port;
    bool allow_packet;
    while (true) {
        printf("\nEnter IP address of packet (-1 to exit): ");
        scanf("%ld", &ip);
        if (ip == -1) {
            break;
        }
        if (!is_valid_ip(ip)) {
            printf("Invalid IP address!\n");
            continue;
        }
        printf("Enter port number of packet: ");
        scanf("%ld", &port);
        if (!is_valid_port(port)) {
            printf("Invalid port number!\n");
            continue;
        }
        allow_packet = process_packet(ip, port, rules, num_rules);
        printf("Packet is %s\n", allow_packet ? "Allowed" : "Denied");
    }

    // Freeing allocated memory
    free(rules);

    return 0;
}