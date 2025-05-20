//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_BUFFER 1024

void check_latency(const char *host) {
    char command[MAX_BUFFER];
    snprintf(command, sizeof(command), "ping -c 4 %s", host);
    printf("Checking latency to %s...\n", host);
    
    // Execute the command
    system(command);
}

void check_packet_loss(const char *host) {
    char command[MAX_BUFFER];
    snprintf(command, sizeof(command), "ping -c 10 %s | tail -2", host);
    printf("Checking packet loss to %s...\n", host);
    
    // Execute the command
    system(command);
}

void check_bandwidth(const char *host) {
    char command[MAX_BUFFER];
    snprintf(command, sizeof(command), "iperf3 -c %s -t 10 -f m", host);
    printf("Checking bandwidth to %s...\n", host);
    
    // Execute the command
    system(command);
}

void display_menu() {
    printf("Network Quality of Service (QoS) Monitor\n");
    printf("1. Check Latency\n");
    printf("2. Check Packet Loss\n");
    printf("3. Check Bandwidth\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char host[MAX_BUFFER];

    printf("Enter the host to monitor (e.g., google.com): ");
    fgets(host, sizeof(host), stdin);
    host[strcspn(host, "\n")] = 0; // Remove trailing newline

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_latency(host);
                break;
            case 2:
                check_packet_loss(host);
                break;
            case 3:
                check_bandwidth(host);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        printf("\n");
        sleep(2); // Pause for a moment before showing the menu again
    }

    return 0;
}