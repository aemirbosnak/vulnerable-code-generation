//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int n);
void printBinary(int n);
char* convertToBinaryString(int n);
void displayBinary(int n);
void clearInputBuffer();
int isNumeric(char *str);

int main() {
    int choice;
    int number;

    printf("Welcome to the C Binary Converter!\n");
    printf("===================================\n");

    do {
        printf("1. Convert Decimal to Binary\n");
        printf("2. Exit\n");
        printf("Please enter your choice (1 or 2): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                if (number < 0) {
                    printf("Please enter a non-negative decimal number.\n");
                    clearInputBuffer();
                    break;
                }
                printf("Decimal: %d\n", number);
                displayBinary(number);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 2);

    return 0;
}

void displayBinary(int n) {
    printf("Binary: ");
    decimalToBinary(n);
    printf("\n");
}

void decimalToBinary(int n) {
    if (n > 1) {
        decimalToBinary(n >> 1);
    }
    printf("%d", n & 1);
}

char* convertToBinaryString(int n) {
    char* binaryRepresentation = (char*)malloc(33); // 32 bits + 1 for null terminator
    if (!binaryRepresentation) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    binaryRepresentation[32] = '\0'; // Null terminator
    
    for (int i = 0; i < 32; i++) {
        binaryRepresentation[31 - i] = (n & (1 << i)) ? '1' : '0';
    }
    return binaryRepresentation;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int isNumeric(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

void printBinary(int n) {
    char* binaryStr = convertToBinaryString(n);
    printf("Binary representation of %d is: %s\n", n, binaryStr);
    free(binaryStr);
}