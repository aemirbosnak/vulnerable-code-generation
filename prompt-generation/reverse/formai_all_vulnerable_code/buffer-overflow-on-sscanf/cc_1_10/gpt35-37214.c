//FormAI DATASET v1.0 Category: Firewall ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold IP address information
struct IpAddress {
    int octet1;
    int octet2;
    int octet3;
    int octet4;
};

// Struct to hold rule information
struct Rule {
    struct IpAddress ip;
    char* protocol;
    int port;
};

// Helper function to parse IP addresses from string
struct IpAddress parseIpAddress(char* ipString) {
    struct IpAddress ipAddress;
    sscanf(ipString, "%d.%d.%d.%d", &ipAddress.octet1, &ipAddress.octet2, &ipAddress.octet3, &ipAddress.octet4);
    return ipAddress;
}

// Helper function to check if two IP addresses are equal
int isEqualIpAddress(struct IpAddress ipAddress1, struct IpAddress ipAddress2) {
    return ipAddress1.octet1 == ipAddress2.octet1 &&
           ipAddress1.octet2 == ipAddress2.octet2 &&
           ipAddress1.octet3 == ipAddress2.octet3 &&
           ipAddress1.octet4 == ipAddress2.octet4;
}

// Helper function to free dynamically allocated rule memory
void freeRule(struct Rule* rule) {
    free(rule->protocol);
    free(rule);
}

// Function to apply rules to incoming packets
void applyRules(struct Rule* rules, int numRules, char* packet) {
    struct IpAddress sourceIp = parseIpAddress(strtok(packet, ","));
    struct IpAddress destIp = parseIpAddress(strtok(NULL, ","));
    char* protocol = strtok(NULL, ",");
    int port = atoi(strtok(NULL, ","));

    for (int i = 0; i < numRules; i++) {
        struct Rule rule = rules[i];
        if (isEqualIpAddress(rule.ip, sourceIp) &&
            strcmp(rule.protocol, protocol) == 0 &&
            rule.port == port) {
            printf("Packet allowed!\n");
            return;
        }
    }

    printf("Packet blocked!\n");
}

int main() {
    // Example rules to allow incoming HTTP traffic from specific IP addresses
    struct Rule* rules = malloc(sizeof(struct Rule) * 3);
    rules[0].ip = parseIpAddress("192.168.0.1");
    rules[0].protocol = strdup("HTTP");
    rules[0].port = 80;

    rules[1].ip = parseIpAddress("192.168.0.2");
    rules[1].protocol = strdup("HTTP");
    rules[1].port = 80;

    rules[2].ip = parseIpAddress("192.168.0.3");
    rules[2].protocol = strdup("HTTP");
    rules[2].port = 80;

    // Example packets to test against rules
    char* packet1 = "192.168.0.1,10.10.10.10,HTTP,80";
    applyRules(rules, 3, packet1);

    char* packet2 = "192.168.0.4,10.10.10.10,HTTP,80";
    applyRules(rules, 3, packet2);

    // Free dynamically allocated memory
    for (int i = 0; i < 3; i++) {
        freeRule(&(rules[i]));
    }
    free(rules);

    return 0;
}