//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    
    int binary[32];
    int index = 0;
    
    while (n > 0) {
        binary[index] = n % 2;
        n = n / 2;
        index++;
    }
    
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

void binaryToDecimal(char *binaryStr) {
    int decimalValue = 0;
    
    for (int i = 0; binaryStr[i] != '\0'; i++) {
        decimalValue = decimalValue * 2 + (binaryStr[i] - '0');
    }
    
    printf("Decimal: %d\n", decimalValue);
}

void displayMenu() {
    printf("\n*** Welcome to the Binary Converter ***\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Select an option (1-3): ");
}

int main() {
    int choice;
    char binaryStr[33]; // 32 bits + 1 for null terminator
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int decimal;
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                
                printf("Converting %d to binary...\n", decimal);
                decimalToBinary(decimal);
                break;
            }
            case 2: {
                printf("Enter a binary number: ");
                scanf("%s", binaryStr);
                
                printf("Converting binary %s to decimal...\n", binaryStr);
                binaryToDecimal(binaryStr);
                break;
            }
            case 3: {
                printf("Exiting the Binary Converter. Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Whoa! That option is out of bounds! Please try again.\n");
                break;
            }
        }
    }

    return 0;
}