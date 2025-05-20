#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_INPUT_SIZE 256

void executeCommand(char *command) {
    char buffer[MAX_INPUT_SIZE];
    snprintf(buffer, sizeof(buffer), "%s", command);
    printf("Executing: %s\n", buffer);
}

int main() {
    int choice;
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("Smart Home Automation System\n");
        printf("1. Turn On Lights\n");
        printf("2. Turn Off Lights\n");
        printf("3. Set Temperature\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Turning on lights...\n");
                break;
            case 2:
                printf("Turning off lights...\n");
                break;
            case 3:
                printf("Set temperature to: ");
                scanf("%s", input);
                executeCommand(input); // Vulnerable to buffer overflow
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
