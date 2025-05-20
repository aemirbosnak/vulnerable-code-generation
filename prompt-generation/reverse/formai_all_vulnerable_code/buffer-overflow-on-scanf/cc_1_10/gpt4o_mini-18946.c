//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define ALLOWED_IPS 5

// Function Prototypes
void displayMenu();
void addAllowedIP(char allowedIPs[][20], int *count);
void checkPacket(char allowedIPs[][20], int count);
void listAllowedIPs(char allowedIPs[][20], int count);

int main() {
    char allowedIPs[ALLOWED_IPS][20];
    int count = 0;
    int choice;

    printf("🎈 Welcome to the Cheery C Firewall! 🎈\n");
    printf("Let’s keep this network safe and sound! 🌟\n");

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAllowedIP(allowedIPs, &count);
                break;
            case 2:
                checkPacket(allowedIPs, count);
                break;
            case 3:
                listAllowedIPs(allowedIPs, count);
                break;
            case 4:
                printf("🚀 Exiting the Cheery C Firewall. Stay Safe!\n");
                break;
            default:
                printf("🤔 Invalid choice! Please try again.\n");
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("🌈 Menu:\n");
    printf("1. Add Allowed IP Address 📡\n");
    printf("2. Check Incoming Packet 🚪\n");
    printf("3. List Allowed IP Addresses 📝\n");
    printf("4. Exit 🚫\n");
}

void addAllowedIP(char allowedIPs[][20], int *count) {
    if (*count >= ALLOWED_IPS) {
        printf("😞 Can't add more IPs! Max limit reached.\n");
        return;
    }
    
    char newIP[20];
    printf("💡 Enter the IP address to allow (e.g., 192.168.1.1): ");
    scanf("%s", newIP);
    strcpy(allowedIPs[*count], newIP);
    (*count)++;
    printf("🎉 Successfully added %s to allowed IPs!\n", newIP);
}

void checkPacket(char allowedIPs[][20], int count) {
    if (count == 0) {
        printf("😱 No allowed IPs! Please add IP addresses first.\n");
        return;
    }

    char incomingIP[20];
    printf("🛡️ Enter the incoming packet IP to check: ");
    scanf("%s", incomingIP);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(incomingIP, allowedIPs[i]) == 0) {
            printf("✅ Packet from %s is ALLOWED! Welcome aboard! 🎉\n", incomingIP);
            return;
        }
    }
    printf("❌ Packet from %s is BLOCKED! Go away! 🚫\n", incomingIP);
}

void listAllowedIPs(char allowedIPs[][20], int count) {
    if (count == 0) {
        printf("😢 No allowed IPs found. Add some first!\n");
        return;
    }
    
    printf("🗂️ Allowed IP Addresses:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, allowedIPs[i]);
    }
}