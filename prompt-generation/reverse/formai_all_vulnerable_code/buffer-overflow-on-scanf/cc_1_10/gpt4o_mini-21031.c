//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define IP_LENGTH 16

typedef struct {
    char blocked_ips[MAX_RULES][IP_LENGTH];
    int count;
} Firewall;

void initialize_firewall(Firewall *fw) {
    fw->count = 0;
}

int add_blocked_ip(Firewall *fw, const char *ip) {
    if (fw->count >= MAX_RULES) {
        printf("Firewall rule limit reached. Cannot add more IPs.\n");
        return -1;
    }
    strncpy(fw->blocked_ips[fw->count], ip, IP_LENGTH);
    fw->blocked_ips[fw->count][IP_LENGTH - 1] = '\0'; // Ensure null-termination
    fw->count++;
    printf("Added blocked IP: %s\n", ip);
    return 0;
}

int remove_blocked_ip(Firewall *fw, const char *ip) {
    for (int i = 0; i < fw->count; i++) {
        if (strcmp(fw->blocked_ips[i], ip) == 0) {
            // Shift remaining blocked IPs to remove the one being unblocked
            for (int j = i; j < fw->count - 1; j++) {
                strncpy(fw->blocked_ips[j], fw->blocked_ips[j + 1], IP_LENGTH);
                fw->blocked_ips[j][IP_LENGTH - 1] = '\0';
            }
            fw->count--;
            printf("Removed blocked IP: %s\n", ip);
            return 0;
        }
    }
    printf("IP %s not found in blocked list.\n", ip);
    return -1;
}

int is_ip_blocked(Firewall *fw, const char *ip) {
    for (int i = 0; i < fw->count; i++) {
        if (strcmp(fw->blocked_ips[i], ip) == 0) {
            return 1; // IP is blocked
        }
    }
    return 0; // IP is not blocked
}

void print_blocked_ips(Firewall *fw) {
    if (fw->count == 0) {
        printf("No blocked IPs.\n");
        return;
    }
    printf("Blocked IPs:\n");
    for (int i = 0; i < fw->count; i++) {
        printf("  %s\n", fw->blocked_ips[i]);
    }
}

void show_menu() {
    printf("\n--- Simple Firewall Menu ---\n");
    printf("1. Add blocked IP\n");
    printf("2. Remove blocked IP\n");
    printf("3. Check if IP is blocked\n");
    printf("4. Show blocked IPs\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

int main() {
    Firewall fw;
    initialize_firewall(&fw);
    int choice;
    char ip[IP_LENGTH];

    while (1) {
        show_menu();
        scanf("%d", &choice);
        getchar(); // clear the newline character

        switch (choice) {
            case 1:
                printf("Enter IP to block: ");
                fgets(ip, sizeof(ip), stdin);
                ip[strcspn(ip, "\n")] = 0; // Remove newline
                add_blocked_ip(&fw, ip);
                break;
            case 2:
                printf("Enter IP to unblock: ");
                fgets(ip, sizeof(ip), stdin);
                ip[strcspn(ip, "\n")] = 0; // Remove newline
                remove_blocked_ip(&fw, ip);
                break;
            case 3:
                printf("Enter IP to check: ");
                fgets(ip, sizeof(ip), stdin);
                ip[strcspn(ip, "\n")] = 0; // Remove newline
                if (is_ip_blocked(&fw, ip)) {
                    printf("IP %s is blocked.\n", ip);
                } else {
                    printf("IP %s is allowed.\n", ip);
                }
                break;
            case 4:
                print_blocked_ips(&fw);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    
    return 0;
}