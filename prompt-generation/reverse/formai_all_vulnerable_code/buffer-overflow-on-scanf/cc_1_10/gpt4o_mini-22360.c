//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimalNum) {
    // Array to store hexadecimal digits
    char hexDigits[100];
    
    int i = 0;
    while (decimalNum != 0) {
        int remainder = decimalNum % 16;

        // Convert remainder to a hex digit
        if (remainder < 10) {
            hexDigits[i] = remainder + '0';
        } else {
            hexDigits[i] = (remainder - 10) + 'A';
        }
        decimalNum /= 16;
        i++;
    }

    // Print the hexadecimal representation in reverse
    printf("The hexadecimal representation is: ");
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hexDigits[j]);
    }
    printf("\n");
}

// Function to convert hexadecimal to decimal
void hexadecimalToDecimal(char hexNum[]) {
    int decimalNum = 0;
    int base = 1; // Base value for hexadecimal

    // Calculate the length of the hex string
    int len = strlen(hexNum);
    
    // Convert from last digit to the first
    for (int i = len - 1; i >= 0; i--) {
        // If it is a valid digit, convert
        if (hexNum[i] >= '0' && hexNum[i] <= '9') {
            decimalNum += (hexNum[i] - '0') * base;
        } 
        // If it is a valid letter in hexadecimal
        else if (hexNum[i] >= 'A' && hexNum[i] <= 'F') {
            decimalNum += (hexNum[i] - 'A' + 10) * base;
        } 
        else if (hexNum[i] >= 'a' && hexNum[i] <= 'f') {
            decimalNum += (hexNum[i] - 'a' + 10) * base;
        } 
        base *= 16; // Increase base for next higher digit
    }

    printf("The decimal representation is: %d\n", decimalNum);
}

int main() {
    // Welcome Message
    printf("Welcome to the Magical Hexadecimal Converter!\n");
    printf("-------------------------------------------------\n");

    int choice;
    do {
        printf("Choose an option:\n");
        printf("1. Convert Decimal to Hexadecimal\n");
        printf("2. Convert Hexadecimal to Decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        if (choice == 1) {
            int decimalNum;
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNum);
            decimalToHexadecimal(decimalNum);
        } else if (choice == 2) {
            char hexNum[100];
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexNum);
            hexadecimalToDecimal(hexNum);
        } else if (choice == 3) {
            printf("Exiting the Magical Hexadecimal Converter. Have a great day!\n");
        } else {
            printf("Invalid choice! Please select a valid option (1-3).\n");
        }

        printf("-------------------------------------------------\n");
    } while (choice != 3); // Loop until the user wants to exit

    return 0;
}