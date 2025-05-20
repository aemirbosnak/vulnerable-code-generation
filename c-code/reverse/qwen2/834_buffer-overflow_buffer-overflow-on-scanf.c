#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void vulnerableFunction(char *buffer) {
    char localBuffer[256];
    scanf("%s", localBuffer);
}

void safeFunction() {
    printf("This is a safe function.\n");
}

int main() {
    int choice;
    while (1) {
        printf("Menu:\n1. Vulnerable Function\n2. Safe Function\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            char input[10];
            printf("Enter input: ");
            scanf("%9s", input); // Safe input handling
            vulnerableFunction(input);
        } else if (choice == 2) {
            safeFunction();
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
