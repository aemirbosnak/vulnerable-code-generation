//Gemma-7B DATASET v1.0 Category: Firewall ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    char *firewall = "FIREWALL IS ON";
    int i = 0;
    char buffer[1024];

    printf("%s\n", firewall);

    while (1) {
        printf("Enter a command: ");
        scanf("%s", buffer);

        for (i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = buffer[i] - 32;
            }
        }

        if (strcmp(buffer, "EXIT") == 0) {
            printf("Goodbye!\n");
            break;
        } else if (strcmp(buffer, "LIST") == 0) {
            printf("Current commands:\n");
            printf("1. ADD\n");
            printf("2. REMOVE\n");
            printf("3. ENABLE\n");
            printf("4. DISABLE\n");
            printf("5. STATUS\n");
            printf("Enter a command: ");
        } else if (strcmp(buffer, "ADD") == 0) {
            printf("Enter the command to add: ");
            scanf("%s", buffer);
            printf("Command added.\n");
        } else if (strcmp(buffer, "REMOVE") == 0) {
            printf("Enter the command to remove: ");
            scanf("%s", buffer);
            printf("Command removed.\n");
        } else if (strcmp(buffer, "ENABLE") == 0) {
            printf("Enter the command to enable: ");
            scanf("%s", buffer);
            printf("Command enabled.\n");
        } else if (strcmp(buffer, "DISABLE") == 0) {
            printf("Enter the command to disable: ");
            scanf("%s", buffer);
            printf("Command disabled.\n");
        } else if (strcmp(buffer, "STATUS") == 0) {
            printf("Current status:\n");
            printf("Commands:\n");
            printf("1. ADD\n");
            printf("2. REMOVE\n");
            printf("3. ENABLE\n");
            printf("4. DISABLE\n");
            printf("5. STATUS\n");
            printf("Firewall: %s\n", firewall);
        } else {
            printf("Invalid command.\n");
        }
    }
}