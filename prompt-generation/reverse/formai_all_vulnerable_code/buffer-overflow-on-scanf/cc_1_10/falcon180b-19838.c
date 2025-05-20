//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LENGTH 33
#define BINARY_NUM_LENGTH 8

// Function to convert decimal to binary
void decimal_to_binary(int num) {
    char binary_num[BINARY_NUM_LENGTH];
    int i = 0;

    while (num > 0) {
        binary_num[i++] = (num % 2) + '0';
        num /= 2;
    }

    binary_num[i] = '\0';
    printf("Binary number: %s\n", binary_num);
}

// Function to convert binary to decimal
int binary_to_decimal(char binary_num[MAX_NUM_LENGTH]) {
    int decimal_num = 0, base = 1;
    int i = strlen(binary_num) - 1;

    while (i >= 0) {
        if (binary_num[i] == '1') {
            decimal_num += base;
        }

        base *= 2;
        i--;
    }

    return decimal_num;
}

// Function to validate user input
int validate_input(char input[MAX_NUM_LENGTH]) {
    int i = 0;

    while (i < strlen(input)) {
        if (input[i] < '0' || input[i] > '9') {
            return 0;
        }
        i++;
    }

    return 1;
}

int main(void) {
    char input[MAX_NUM_LENGTH];
    char choice;

    do {
        printf("Enter a decimal number: ");
        fgets(input, MAX_NUM_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (!validate_input(input)) {
            printf("Invalid input. Please enter a valid decimal number.\n");
            continue;
        }

        printf("Enter your choice:\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Convert binary to decimal\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                decimal_to_binary(atoi(input));
                break;

            case '2':
                printf("Binary number: ");
                scanf("%s", input);
                printf("Decimal number: %d\n", binary_to_decimal(input));
                break;

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (1);

    return 0;
}