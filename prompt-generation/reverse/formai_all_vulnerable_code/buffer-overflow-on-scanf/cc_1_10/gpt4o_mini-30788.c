//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_IPS 100
#define IP_LEN 16

// A whimsical list of allowed fowls, I mean IPs.
const char* allowed_ips[MAX_IPS] = {
    "192.168.1.1", // The noble server
    "192.168.1.10", // The friendly neighbor
    "10.0.0.1" // The wizard of 10's
};
int allowed_count = 3;

// Function declarations for firewall sorcery
void initialize_firewall();
void block_ip(const char* ip);
int ip_is_allowed(const char* ip);
void simulate_connection(const char* incoming_ip);
void listen_for_connections();

// Main function where the firewall magic begins
int main() {
    printf("Welcome to the Curious C Firewall!\n");
    printf("Casting protective spells...\n");

    initialize_firewall();
    listen_for_connections();

    return 0;
}

// A function to initialize the firewall and print some whimsical thoughts
void initialize_firewall() {
    printf("Waving the wand of initialization...\n");
    // In a production firewall, setup might include socket creation, etc.
    for (int i = 0; i < allowed_count; i++) {
        printf("Allowed IP detected: %s - A friend indeed!\n", allowed_ips[i]);
    }
}

// A function to simulate a blocking spell on an IP
void block_ip(const char* ip) {
    printf("Alas! Blocking the malicious entity: %s\n", ip);
}

// A function to check if an IP is allowed entry into the kingdom
int ip_is_allowed(const char* ip) {
    for (int i = 0; i < allowed_count; i++) {
        if (strcmp(ip, allowed_ips[i]) == 0) {
            return 1; // Huzzah! The IP is allowed.
        }
    }
    return 0; // Oh no! The IP is a rogue bend on the road.
}

// A function to simulate connections - the battlefield of IPs
void simulate_connection(const char* incoming_ip) {
    printf("A brave knight approaches with IP: %s...\n", incoming_ip);
    
    // Check if the incoming knight is a friend or foe
    if (ip_is_allowed(incoming_ip)) {
        printf("Welcome, noble knight! You may pass.\n");
    } else {
        block_ip(incoming_ip);
    }
}

// A function to simulate listening for connections in a whimsical land
void listen_for_connections() {
    char incoming_ip[IP_LEN];

    // Here we will pretend to listen for various connections in a loop
    while (1) {
        printf("Enter an IP address to simulate a connection (or 'exit' to flee): ");
        scanf("%s", incoming_ip);
        
        if (strcmp(incoming_ip, "exit") == 0) {
            printf("Fleeing the battleground...\n");
            break;
        }

        simulate_connection(incoming_ip);
    }
}