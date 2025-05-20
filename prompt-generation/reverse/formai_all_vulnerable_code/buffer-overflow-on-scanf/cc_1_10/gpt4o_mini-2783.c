//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void execute_command(const char *command) {
    FILE *fp;
    char buffer[BUFFER_SIZE];

    // Open the command for reading
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        return;
    }

    // Read the output a line at a time
    printf("\nCommand output:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    // Close the command stream
    pclose(fp);
}

void ping_test(const char *host) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "ping -c 5 %s", host);
    execute_command(command);
}

void iperf_test(const char *host, int port) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "iperf3 -c %s -p %d -t 10", host, port);
    execute_command(command);
}

void display_menu() {
    printf("\nNetwork Quality of Service (QoS) Monitor\n");
    printf("1. Ping Test\n");
    printf("2. Iperf Test\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    char host[BUFFER_SIZE];
    int port;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter host to ping: ");
                scanf("%s", host);
                ping_test(host);
                break;
            case 2:
                printf("Enter host for iperf test: ");
                scanf("%s", host);
                printf("Enter port number (default 5201): ");
                scanf("%d", &port);
                iperf_test(host, port);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}