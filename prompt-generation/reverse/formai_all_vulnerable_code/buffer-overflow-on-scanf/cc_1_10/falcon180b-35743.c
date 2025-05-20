//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LENGTH 32 // Maximum length of input number
#define BINARY_NUM_LENGTH 8 // Length of binary number
#define BASE 2 // Base of the number system

// Function to validate input number
int isValidNumber(char *num) {
    int i, j;
    for (i = 0; i < strlen(num); i++) {
        if (!isdigit(num[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert decimal to binary
void decToBin(int num) {
    int rem, i = 1;
    char bin[BINARY_NUM_LENGTH];
    bin[0] = '0';
    bin[1] = '1';
    while (num > 0) {
        rem = num % BASE;
        bin[i] = rem + '0';
        i++;
        num /= BASE;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", bin[j]);
    }
}

// Function to convert binary to decimal
int binToDec(char *bin) {
    int dec = 0, i, j;
    for (i = strlen(bin) - 1, j = 0; i >= 0; i--, j++) {
        dec += (bin[i] - '0') * pow(BASE, j);
    }
    return dec;
}

int main() {
    char num[MAX_NUM_LENGTH];
    int choice, dec;

    printf("Enter a decimal number: ");
    scanf("%s", num);

    if (isValidNumber(num)) {
        printf("Binary equivalent: ");
        decToBin(atoi(num));
        printf("\n");

        printf("Enter your choice:\n1. Convert binary to decimal\n2. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter a binary number: ");
            scanf("%s", num);

            dec = binToDec(num);
            printf("Decimal equivalent: %d\n", dec);
        }
    } else {
        printf("Invalid input\n");
    }

    return 0;
}