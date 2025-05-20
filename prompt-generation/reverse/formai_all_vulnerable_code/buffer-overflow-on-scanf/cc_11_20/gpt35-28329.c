//FormAI DATASET v1.0 Category: Firewall ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALLOWED_IP 100 // Maximum number of allowed IPs
#define MAX_IP_LENGTH 16 // Maximum length of an IP address

// Structure to store allowed IPs
typedef struct {
    char ip[MAX_IP_LENGTH];
} AllowedIP;

// Function to check if an IP is allowed or not
int isAllowed(char* ip, AllowedIP* allowed_ips, int num_allowed_ips) {
    int i;
    for (i = 0; i < num_allowed_ips; i++) {
        if (strcmp(ip, allowed_ips[i].ip) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char firewall_status = 'o'; // o = open, c = closed
    AllowedIP allowed_ips[MAX_ALLOWED_IP];
    int num_allowed_ips = 0;
    
    // Main loop
    while (1) {
        // Print current firewall status
        printf("Firewall is currently %s.\n", firewall_status == 'o' ? "open" : "closed");
        
        // Get user input
        printf("Enter command (open, close, add IP, remove IP, list IPs, exit): ");
        char command[20];
        scanf("%s", command);
        
        // Process user command
        if (strcmp(command, "open") == 0) {
            firewall_status = 'o';
            printf("Firewall opened.\n");
        }
        else if (strcmp(command, "close") == 0) {
            firewall_status = 'c';
            printf("Firewall closed.\n");
        }
        else if (strcmp(command, "add") == 0) {
            char ip[MAX_IP_LENGTH];
            printf("Enter IP address to allow: ");
            scanf("%s", ip);
            if (isAllowed(ip, allowed_ips, num_allowed_ips)) {
                printf("IP address already allowed.\n");
            }
            else {
                if (num_allowed_ips < MAX_ALLOWED_IP) {
                    strcpy(allowed_ips[num_allowed_ips].ip, ip);
                    num_allowed_ips++;
                    printf("%s added to allowed list.\n", ip);
                }
                else {
                    printf("Cannot add IP address. Maximum number of allowed IPs reached.\n");
                }
            }
        }
        else if (strcmp(command, "remove") == 0) {
            char ip[MAX_IP_LENGTH];
            printf("Enter IP address to remove: ");
            scanf("%s", ip);
            int i;
            for (i = 0; i < num_allowed_ips; i++) {
                if (strcmp(ip, allowed_ips[i].ip) == 0) {
                    // Shift all elements after i to the left
                    int j;
                    for (j = i; j < num_allowed_ips - 1; j++) {
                        strcpy(allowed_ips[j].ip, allowed_ips[j+1].ip);
                    }
                    num_allowed_ips--;
                    printf("%s removed from allowed list.\n", ip);
                    break;
                }
            }
            if (i == num_allowed_ips) {
                printf("IP address not found in allowed list.\n");
            }
        }
        else if (strcmp(command, "list") == 0) {
            if (num_allowed_ips == 0) {
                printf("No IPs allowed.\n");
            }
            else {
                printf("Allowed IPs:\n");
                int i;
                for (i = 0; i < num_allowed_ips; i++) {
                    printf("%s\n", allowed_ips[i].ip);
                }
            }
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid command.\n");
        }
        
        // Check if incoming IP is allowed and print message accordingly
        if (firewall_status == 'c') {
            char incoming_ip[MAX_IP_LENGTH];
            printf("Enter incoming IP address: ");
            scanf("%s", incoming_ip);
            if (isAllowed(incoming_ip, allowed_ips, num_allowed_ips)) {
                printf("Incoming IP allowed.\n");
            }
            else {
                printf("Incoming IP not allowed. Connection denied.\n");
            }
        }
        
        printf("\n");
    }

    return 0;
}