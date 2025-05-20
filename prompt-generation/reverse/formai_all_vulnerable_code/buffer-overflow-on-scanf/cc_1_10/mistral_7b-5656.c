//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BINARY_LENGTH 50
#define BASE 10

void binary_to_decimal(char binary[]) {
    int decimal = 0, i, power = 0;

    for (i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1')
            decimal += pow(2, power);
        power++;
    }

    printf("The decimal value of the binary number %s is: %d\n", binary, decimal);
}

int main(void) {
    char binary[MAX_BINARY_LENGTH];
    int choice;

    printf("\nWelcome to the Binary to Decimal Converter!\n");
    printf("This program will help you convert binary numbers to decimal numbers.\n\n");

    while (1) {
        printf("1. Convert binary number to decimal\n");
        printf("2. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter binary number: ");
            fflush(stdin);
            fgets(binary, sizeof(binary), stdin);

            binary[strlen(binary) - 1] = '\0';

            binary_to_decimal(binary);
        } else if (choice == 2) {
            printf("Thank you for using our program! Have a peaceful day.\n");
            exit(0);
        } else {
            printf("Invalid choice! Please enter 1 or 2.\n");
        }
    }

    return 0;
}