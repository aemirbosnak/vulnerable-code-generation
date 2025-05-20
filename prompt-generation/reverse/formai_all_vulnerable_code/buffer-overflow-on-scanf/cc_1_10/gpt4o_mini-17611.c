//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal, char *binary) {
    int index = 0;

    if(decimal == 0) {
        strcpy(binary, "0");
        return;
    }

    while(decimal > 0) {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[index] = '\0';

    // Reverse the string
    int start = 0, end = index - 1;
    while (start < end) {
        char temp = binary[start];
        binary[start] = binary[end];
        binary[end] = temp;
        start++;
        end--;
    }
}

// Function to add two binary numbers
void binaryAddition(const char *binary1, const char *binary2, char *result) {
    int carry = 0;
    int len1 = strlen(binary1);
    int len2 = strlen(binary2);

    int maxLength = len1 > len2 ? len1 : len2;
    for(int i = 0; i < maxLength; i++) {
        int bit1 = (i < len1) ? (binary1[len1 - 1 - i] - '0') : 0;
        int bit2 = (i < len2) ? (binary2[len2 - 1 - i] - '0') : 0;

        int sum = bit1 + bit2 + carry;
        carry = sum / 2;
        result[i] = (sum % 2) + '0';
    }

    if(carry) {
        result[maxLength] = '1';
        maxLength++;
    }
    result[maxLength] = '\0';

    // Reverse the result
    for(int j = 0; j < maxLength / 2; j++) {
        char temp = result[j];
        result[j] = result[maxLength - 1 - j];
        result[maxLength - 1 - j] = temp;
    }
}

// Function to display the menu options
void displayMenu() {
    printf("\n--- Binary Converter ---\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Add Two Binary Numbers\n");
    printf("3. Exit\n");
    printf("-------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char binary1[65], binary2[65], result[66];
    int decimal;

    while(1) {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimalToBinary(decimal, binary1);
                printf("Binary representation: %s\n", binary1);
                break;

            case 2:
                printf("Enter the first binary number: ");
                scanf("%s", binary1);
                printf("Enter the second binary number: ");
                scanf("%s", binary2);
                binaryAddition(binary1, binary2, result);
                printf("Sum: %s\n", result);
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}