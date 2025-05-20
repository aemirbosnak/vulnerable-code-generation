//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

void intToBinary(int num, char *binaryStr) {
    binaryStr[MAX_BITS - 1] = '\0'; // Null-terminate the string
    for (int i = MAX_BITS - 2; i >= 0; i--) {
        binaryStr[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
}

void floatToBinary(float num, char *binaryStr) {
    unsigned int *ptr = (unsigned int*)&num;
    for (int i = 0; i < MAX_BITS; i++) {
        binaryStr[MAX_BITS - 1 - i] = (*ptr & (1 << i)) ? '1' : '0';
    }
    binaryStr[MAX_BITS] = '\0'; // Null-terminate the string
}

void charToBinary(char c, char *binaryStr) {
    for (int i = 0; i < 8; i++) {
        binaryStr[7 - i] = (c & (1 << i)) ? '1' : '0';
    }
    binaryStr[8] = '\0'; // Null-terminate the string
}

void printBinaryRepresentation(const char *label, const char *binaryStr) {
    printf("%s: %s\n", label, binaryStr);
}

void handleInput(int choice) {
    if (choice == 1) {
        int intNum;
        char binaryStr[MAX_BITS];
        
        printf("Enter an integer: ");
        scanf("%d", &intNum);
        intToBinary(intNum, binaryStr);
        printBinaryRepresentation("Integer Binary Representation", binaryStr);
    } else if (choice == 2) {
        float floatNum;
        char binaryStr[MAX_BITS];
        
        printf("Enter a floating-point number: ");
        scanf("%f", &floatNum);
        floatToBinary(floatNum, binaryStr);
        printBinaryRepresentation("Float Binary Representation", binaryStr);
    } else if (choice == 3) {
        char charInput;
        char binaryStr[9];
        
        printf("Enter a character: ");
        scanf(" %c", &charInput);
        charToBinary(charInput, binaryStr);
        printBinaryRepresentation("Character Binary Representation", binaryStr);
    } else {
        printf("Invalid choice! Please select a valid option.\n");
    }
}

void displayMenu() {
    printf("Welcome to the Binary Converter!\n");
    printf("Please select an option:\n");
    printf("1. Convert an Integer to Binary\n");
    printf("2. Convert a Float to Binary\n");
    printf("3. Convert a Character to Binary\n");
    printf("4. Exit\n");
}

int main() {
    int choice = 0;

    while (choice != 4) {
        displayMenu();
        scanf("%d", &choice);
        if (choice != 4) {
            handleInput(choice);
            printf("\n");
        }
    }

    printf("Thank you for using the Binary Converter!\n");
    return 0;
}