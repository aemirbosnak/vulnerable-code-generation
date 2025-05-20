//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToBinary(int number, char *binaryRepresentation) {
    int index = 0;
    if (number == 0) {
        binaryRepresentation[index++] = '0';
    } else {
        while (number > 0) {
            binaryRepresentation[index++] = (number % 2) + '0';
            number /= 2;
        }
    }
    // Reverse the string for correct binary representation
    binaryRepresentation[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        char temp = binaryRepresentation[i];
        binaryRepresentation[i] = binaryRepresentation[index - i - 1];
        binaryRepresentation[index - i - 1] = temp;
    }
}

int main() {
    int decimalNumber;
    char binaryRepresentation[33]; // enough to hold binary for a 32-bit unsigned int
    char answer[3];

    printf("Welcome to the Decimal to Binary Converter!\n");
    
    do {
        printf("Please enter a non-negative integer: ");
        while (1) {
            if (scanf("%d", &decimalNumber) != 1 || decimalNumber < 0) {
                printf("Invalid input! Please enter a non-negative integer: ");
                while(getchar() != '\n'); // clear the input buffer
            } else {
                break;
            }
        }

        convertToBinary(decimalNumber, binaryRepresentation);

        printf("Decimal: %d\nBinary: %s\n", decimalNumber, binaryRepresentation);

        printf("Would you like to convert another number? (yes/no) ");
        scanf("%s", answer);
        
        // Clear the input buffer
        while(getchar() != '\n');

        // Normalize the answer for comparison
        for(int i = 0; answer[i]; i++){
            answer[i] = tolower(answer[i]);
        }

    } while (strcmp(answer, "yes") == 0);

    printf("Thank you for using the converter! Goodbye!\n");
    
    return 0;
}