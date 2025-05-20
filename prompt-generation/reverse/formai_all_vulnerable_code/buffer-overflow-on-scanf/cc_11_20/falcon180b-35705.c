//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000

int main() {
    char input[MAX_INPUT_SIZE];
    int choice, decimal, binary[32];
    char binary_str[33]; // 32 binary digits + null terminator

    printf("Enter a decimal number: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    decimal = atoi(input);
    choice = 1;

    while (choice == 1) {
        printf("\nSelect a conversion option:\n");
        printf("1. Decimal to binary\n");
        printf("2. Binary to decimal\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the number of binary digits: ");
                scanf("%d", &choice);
                if (choice < 1 || choice > 32) {
                    printf("Invalid number of binary digits.\n");
                    break;
                }
                sprintf(binary_str, "%.32s", "");
                for (int i = 0; i < choice; i++) {
                    binary[i] = decimal % 2;
                    decimal /= 2;
                }
                for (int i = choice - 1; i >= 0; i--) {
                    binary_str[i] = binary[i] + '0';
                }
                printf("Binary representation: %s\n", binary_str);
                break;
            case 2:
                printf("\nEnter the binary number: ");
                fgets(input, MAX_INPUT_SIZE, stdin);
                for (int i = 0; i < strlen(input); i++) {
                    if (input[i]!= '0' && input[i]!= '1') {
                        printf("Invalid binary number.\n");
                        break;
                    }
                }
                decimal = 0;
                for (int i = strlen(input) - 1; i >= 0; i--) {
                    if (input[i] == '1') {
                        decimal += pow(2, strlen(input) - i - 1);
                    }
                }
                printf("Decimal representation: %d\n", decimal);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}