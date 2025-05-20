//FormAI DATASET v1.0 Category: Firewall ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum input lengths
#define MAX_IP_LEN 15
#define MAX_PORT_LEN 5
#define MAX_PROTOCOL_LEN 10

// Define a structure to represent a rule in the firewall
struct FirewallRule {
    char ip[MAX_IP_LEN];
    char port[MAX_PORT_LEN];
    char protocol[MAX_PROTOCOL_LEN];
    struct FirewallRule* next;
};

int main() {
    // Initialize the firewall with an empty rule
    struct FirewallRule* firewall = malloc(sizeof(struct FirewallRule));
    memset(firewall->ip, 0, MAX_IP_LEN);
    memset(firewall->port, 0, MAX_PORT_LEN);
    memset(firewall->protocol, 0, MAX_PROTOCOL_LEN);
    firewall->next = NULL;

    // Print a paranoid welcome message
    printf("Welcome to the ultra-secure firewall!\n");
    printf("We will keep your network safe from any intruders.\n\n");
    printf("To get started, please tell me your secret passphrase:\n");

    // Read in the passphrase and store it
    char passphrase[20];
    scanf("%s", passphrase);

    // Hash the passphrase (for extra security!)
    unsigned int hash = 0;
    for (int i = 0; i < strlen(passphrase); i++) {
        hash = (hash * 31) + passphrase[i];
    }

    // Paranoid check to ensure the passphrase is secure enough
    if (hash == 0) {
        printf("ERROR: Passphrase is too weak!\n");
        exit(1);
    }

    // Print a warning message
    printf("WARNING: Only use this firewall if you know what you are doing!\n");
    printf("Any invalid input will trigger the alarm and lock down the system.\n\n");

    // Loop to add rules to the firewall
    while (1) {
        // Read in the IP address, port, and protocol for the new rule
        char ip[MAX_IP_LEN], port[MAX_PORT_LEN], protocol[MAX_PROTOCOL_LEN];
        printf("Enter the IP address for the new rule: ");
        scanf("%s", ip);
        printf("Enter the port number (1-65535) for the new rule: ");
        scanf("%s", port);
        printf("Enter the protocol (TCP/UDP) for the new rule: ");
        scanf("%s", protocol);

        // Paranoid check to ensure input is valid
        if (strlen(ip) > MAX_IP_LEN || strlen(port) > MAX_PORT_LEN || strlen(protocol) > MAX_PROTOCOL_LEN) {
            printf("ERROR: Invalid input detected!\n");
            printf("ALERT! ALARM! LOCKDOWN MODE ACTIVATED!\n");
            exit(1);
        }

        // Create a new rule and add it to the firewall
        struct FirewallRule* newRule = malloc(sizeof(struct FirewallRule));
        strncpy(newRule->ip, ip, MAX_IP_LEN);
        strncpy(newRule->port, port, MAX_PORT_LEN);
        strncpy(newRule->protocol, protocol, MAX_PROTOCOL_LEN);
        newRule->next = firewall;
        firewall = newRule;

        // Paranoid confirmation message
        printf("New firewall rule added successfully!\n");
        printf("Total number of rules: %d\n\n", countRules(firewall));

        // Check if the user wants to add another rule
        printf("Do you want to add another rule? (y/n) ");
        char answer[2];
        scanf("%s", answer);

        // Paranoid check to ensure input is valid
        if (strcmp(answer, "y") && strcmp(answer, "n")) {
            printf("ERROR: Invalid input detected!\n");
            printf("ALERT! ALARM! LOCKDOWN MODE ACTIVATED!\n");
            exit(1);
        }

        // Quit the loop if the user says no
        if (!strcmp(answer, "n")) {
            break;
        }
    }

    // Print a paranoid message before exiting
    printf("Thank you for using the ultra-secure firewall!\n");
    printf("Remember, security is everyone's responsibility.\n\n");
    printf("ALERT! ALARM! LOCKDOWN MODE ACTIVATED!\n");

    return 0;
}

// Helper function to count the number of rules in the firewall
int countRules(struct FirewallRule* firewall) {
    int count = 0;
    struct FirewallRule* current = firewall;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}