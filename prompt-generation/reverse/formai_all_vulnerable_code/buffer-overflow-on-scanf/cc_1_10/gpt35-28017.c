//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RAM_USAGE 1000000 // max RAM usage in bytes

int main() {
    int ramUsage = 0;

    while(1) {
        char command[100];
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "status") == 0) {
            printf("Current RAM usage: %d bytes\n", ramUsage);
        }
        else if (strcmp(command, "add") == 0) {
            int memSize;
            printf("Enter memory size to add: ");
            scanf("%d", &memSize);

            if (ramUsage + memSize > MAX_RAM_USAGE) {
                printf("Sorry, cannot add more memory. Memory limit reached.\n");
            }
            else {
                ramUsage += memSize;
                printf("%d bytes added to RAM usage.\n", memSize);
            }
        }
        else if (strcmp(command, "remove") == 0) {
            int memSize;
            printf("Enter memory size to remove: ");
            scanf("%d", &memSize);

            if (ramUsage - memSize < 0) {
                printf("Sorry, cannot remove more memory. RAM usage too low.\n");
            }
            else {
                ramUsage -= memSize;
                printf("%d bytes removed from RAM usage.\n", memSize);
            }
        }
        else if (strcmp(command, "quit") == 0) {
            printf("Exiting program...");
            return 0;
        }
        else {
            printf("Invalid command. Please try again.\n");
        }
    }
}