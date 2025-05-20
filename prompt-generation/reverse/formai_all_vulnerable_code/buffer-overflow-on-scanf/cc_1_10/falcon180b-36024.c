//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    int choice, length, i;

    printf("Enter a string (maximum %d characters): ", MAX_SIZE);
    fgets(input, MAX_SIZE, stdin);
    length = strlen(input);

    // Bitwise operations menu
    printf("\nBitwise operations menu:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Bitwise shift left\n");
    printf("6. Bitwise shift right\n");
    printf("7. Bitwise complement\n");
    printf("8. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Bitwise AND
                printf("\nBitwise AND result: %d\n", input[0] & input[1]);
                break;
            case 2:
                // Bitwise OR
                printf("\nBitwise OR result: %d\n", input[0] | input[1]);
                break;
            case 3:
                // Bitwise XOR
                printf("\nBitwise XOR result: %d\n", input[0] ^ input[1]);
                break;
            case 4:
                // Bitwise NOT
                printf("\nBitwise NOT result: %d\n", ~input[0]);
                break;
            case 5:
                // Bitwise shift left
                printf("\nBitwise shift left result: %d\n", input[0] << 2);
                break;
            case 6:
                // Bitwise shift right
                printf("\nBitwise shift right result: %d\n", input[0] >> 2);
                break;
            case 7:
                // Bitwise complement
                printf("\nBitwise complement result: %d\n", ~(input[0] | 0b11111111));
                break;
            case 8:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice!= 8);

    return 0;
}