//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_LIST_LENGTH 100

typedef struct {
    char allow[MAX_LIST_LENGTH][MAX_IP_LENGTH];
    char block[MAX_LIST_LENGTH][MAX_IP_LENGTH];
    int allow_count;
    int block_count;
} Firewall;

void init_firewall(Firewall *fw) {
    fw->allow_count = 0;
    fw->block_count = 0;
}

// Function to add IP to the allow list
void add_allow_ip(Firewall *fw, const char *ip) {
    if (fw->allow_count < MAX_LIST_LENGTH) {
        strcpy(fw->allow[fw->allow_count], ip);
        fw->allow_count++;
        printf("IP %s added to allow list.\n", ip);
    } else {
        printf("Allow list is full!\n");
    }
}

// Function to remove IP from the allow list
void remove_allow_ip(Firewall *fw, const char *ip) {
    for (int i = 0; i < fw->allow_count; i++) {
        if (strcmp(fw->allow[i], ip) == 0) {
            strcpy(fw->allow[i], fw->allow[fw->allow_count - 1]); // replace with last element
            fw->allow_count--;
            printf("IP %s removed from allow list.\n", ip);
            return;
        }
    }
    printf("IP %s not found in allow list.\n", ip);
}

// Function to add IP to the block list
void add_block_ip(Firewall *fw, const char *ip) {
    if (fw->block_count < MAX_LIST_LENGTH) {
        strcpy(fw->block[fw->block_count], ip);
        fw->block_count++;
        printf("IP %s added to block list.\n", ip);
    } else {
        printf("Block list is full!\n");
    }
}

// Function to remove IP from the block list
void remove_block_ip(Firewall *fw, const char *ip) {
    for (int i = 0; i < fw->block_count; i++) {
        if (strcmp(fw->block[i], ip) == 0) {
            strcpy(fw->block[i], fw->block[fw->block_count - 1]); // replace with last element
            fw->block_count--;
            printf("IP %s removed from block list.\n", ip);
            return;
        }
    }
    printf("IP %s not found in block list.\n", ip);
}

// Function to display all allowed IPs
void display_allow_ips(const Firewall *fw) {
    printf("\nAllowed IPs:\n");
    for (int i = 0; i < fw->allow_count; i++) {
        printf("%s\n", fw->allow[i]);
    }
}

// Function to display all blocked IPs
void display_block_ips(const Firewall *fw) {
    printf("\nBlocked IPs:\n");
    for (int i = 0; i < fw->block_count; i++) {
        printf("%s\n", fw->block[i]);
    }
}

// Function to save the firewall rules to a file
void save_firewall_rules(const Firewall *fw) {
    FILE *file = fopen("firewall_rules.txt", "w");
    if (file == NULL) {
        printf("Error opening the file for saving rules.\n");
        return;
    }
    
    fprintf(file, "Allowed IPs:\n");
    for (int i = 0; i < fw->allow_count; i++) {
        fprintf(file, "%s\n", fw->allow[i]);
    }

    fprintf(file, "\nBlocked IPs:\n");
    for (int i = 0; i < fw->block_count; i++) {
        fprintf(file, "%s\n", fw->block[i]);
    }

    fclose(file);
    printf("Firewall rules saved to firewall_rules.txt\n");
}

// Function to load firewall rules from a file
void load_firewall_rules(Firewall *fw) {
    FILE *file = fopen("firewall_rules.txt", "r");
    if (file == NULL) {
        printf("No saved firewall rules found.\n");
        return;
    }
    
    char line[MAX_IP_LENGTH];
    // Load allowed IPs
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Allowed IPs:") != NULL) {
            while (fgets(line, sizeof(line), file) && strlen(line) > 1) {
                line[strcspn(line, "\n")] = 0; // Remove newline
                add_allow_ip(fw, line);
            }
        }
        // Load blocked IPs
        if (strstr(line, "Blocked IPs:") != NULL) {
            while (fgets(line, sizeof(line), file) && strlen(line) > 1) {
                line[strcspn(line, "\n")] = 0; // Remove newline
                add_block_ip(fw, line);
            }
        }
    }

    fclose(file);
    printf("Firewall rules loaded from firewall_rules.txt\n");
}

int main() {
    Firewall fw;
    init_firewall(&fw);
    load_firewall_rules(&fw);

    int choice;
    char ip[MAX_IP_LENGTH];

    do {
        printf("\nFirewall Menu:\n");
        printf("1. Add Allowed IP\n");
        printf("2. Remove Allowed IP\n");
        printf("3. Add Blocked IP\n");
        printf("4. Remove Blocked IP\n");
        printf("5. Display Allowed IPs\n");
        printf("6. Display Blocked IPs\n");
        printf("7. Save Firewall Rules\n");
        printf("8. Load Firewall Rules\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter IP to allow: ");
                fgets(ip, sizeof(ip), stdin);
                ip[strcspn(ip, "\n")] = 0; // Remove newline
                add_allow_ip(&fw, ip);
                break;
            case 2:
                printf("Enter IP to remove from allow list: ");
                fgets(ip, sizeof(ip), stdin);
                ip[strcspn(ip, "\n")] = 0; // Remove newline
                remove_allow_ip(&fw, ip);
                break;
            case 3:
                printf("Enter IP to block: ");
                fgets(ip, sizeof(ip), stdin);
                ip[strcspn(ip, "\n")] = 0; // Remove newline
                add_block_ip(&fw, ip);
                break;
            case 4:
                printf("Enter IP to remove from block list: ");
                fgets(ip, sizeof(ip), stdin);
                ip[strcspn(ip, "\n")] = 0; // Remove newline
                remove_block_ip(&fw, ip);
                break;
            case 5:
                display_allow_ips(&fw);
                break;
            case 6:
                display_block_ips(&fw);
                break;
            case 7:
                save_firewall_rules(&fw);
                break;
            case 8:
                load_firewall_rules(&fw);
                break;
            case 0:
                printf("Exiting Firewall Program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}