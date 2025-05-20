//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100000

// Function to convert decimal to binary
void decimal_to_binary(int num) {
    char binary[MAX_SIZE]; // Array to store binary equivalent
    int i = 0; // Index for binary array
    while (num!= 0) {
        binary[i] = num % 2 + '0'; // Adding remainder to binary array
        i++;
        num /= 2; // Updating num for next iteration
    }
    binary[i] = '\0'; // Adding null character at the end of binary array
    printf("%s\n", binary); // Printing binary equivalent
}

// Function to convert binary to decimal
int binary_to_decimal(char binary[]) {
    int decimal = 0; // Initializing decimal to 0
    int power = 0; // Initializing power to 0
    int i = strlen(binary) - 1; // Starting from end of binary array
    while (i >= 0) {
        if (binary[i] == '1') {
            decimal += pow(2, power); // Adding 2^power to decimal
        }
        power++; // Updating power for next iteration
        i--; // Decrementing i for next iteration
    }
    return decimal; // Returning decimal equivalent
}

int main() {
    int choice;
    char binary[MAX_SIZE];

    do {
        printf("\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n");
                printf("Enter a decimal number: ");
                scanf("%s", binary);
                decimal_to_binary(atoi(binary)); // Calling function to convert decimal to binary
                break;

            case 2:
                printf("\n");
                printf("Enter a binary number: ");
                scanf("%s", binary);
                printf("\n");
                printf("Decimal equivalent: %d\n", binary_to_decimal(binary)); // Calling function to convert binary to decimal
                break;

            case 3:
                printf("\n");
                printf("Exiting...\n");
                break;

            default:
                printf("\n");
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}