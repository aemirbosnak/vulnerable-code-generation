//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: active
#include <stdio.h>

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

    // Print binary in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

void printMenu() {
    printf("********** Binary Converter **********\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Exit\n");
    printf("***************************************\n");
}

int main() {
    int choice;
    int decimalNumber;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                printf("Binary representation of %d is: ", decimalNumber);
                decimalToBinary(decimalNumber);
                printf("\n");
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        // New line for better readability in the menu
        printf("\n");

    } while (choice != 2);

    return 0;
}