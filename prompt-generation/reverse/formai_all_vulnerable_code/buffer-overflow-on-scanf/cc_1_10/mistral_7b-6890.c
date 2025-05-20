//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_LENGTH 512
#define MIN_BINARY_LENGTH 1

void print_binary(char binary[]) {
    int i = strlen(binary) - 1;
    printf("Decimal Equivalent of Binary Number: ");
    while (binary[i] != '\0') {
        printf("%c", binary[i]);
        i--;
    }
    printf(" = %d\n", strtoul(binary, NULL, 2));
}

int main() {
    char binary[MAX_BINARY_LENGTH];
    int length, choice;

    printf("----------------------------------------\n");
    printf("| Welcome to Binary Converter           |\n");
    printf("|----------------------------------------|\n");
    printf("| Enter binary number:                   |\n");
    printf("----------------------------------------\n");

    fgets(binary, sizeof(binary), stdin);
    binary[strcspn(binary, "\n")] = '\0'; // Remove newline character

    do {
        printf("\nOptions:\n");
        printf("1. Convert binary to decimal\n");
        printf("2. Display binary number in different lengths\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_binary(binary);
                break;
            case 2:
                printf("Enter binary number length: ");
                scanf("%d", &length);
                length = (length < MIN_BINARY_LENGTH) ? MIN_BINARY_LENGTH : length;
                length = (length > MAX_BINARY_LENGTH) ? MAX_BINARY_LENGTH : length;
                memset(binary + length, '0', MAX_BINARY_LENGTH - length);
                print_binary(binary);
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}