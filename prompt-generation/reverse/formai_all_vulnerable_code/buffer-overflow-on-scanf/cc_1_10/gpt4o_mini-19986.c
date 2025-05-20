//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: synchronous
#include <stdio.h>

void toHex(int num, char *output) {
    if (num < 0) {
        num = -num;
    }
    int index = 0;
    const char hexDigits[] = "0123456789ABCDEF";
    
    // Handle case for zero
    if (num == 0) {
        output[index++] = '0';
    } else {
        while (num != 0) {
            int remainder = num % 16;
            output[index++] = hexDigits[remainder];
            num /= 16;
        }
    }
    // Reverse the hex string to get the correct order
    output[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        char temp = output[i];
        output[i] = output[index - i - 1];
        output[index - i - 1] = temp;
    }
}

int main() {
    int number = 0;
    char hexOutput[20]; // To hold the hexadecimal representation
    char choice;

    printf("Welcome to the Integer to Hexadecimal Converter!\n");
    
    do {
        printf("Please enter an integer: ");
        if (scanf("%d", &number) != 1) {
            printf("Invalid input, please enter a valid integer.\n");
            while(getchar() != '\n'); // Clear invalid input
            continue;
        }

        toHex(number, hexOutput);
        printf("The hexadecimal representation of %d is: %s\n", number, hexOutput);

        printf("Would you like to convert another number? (Y/N): ");
        while (getchar() != '\n'); // clear buffer before reading choice
        choice = getchar();
        
        while (choice != 'Y' && choice != 'N' && choice != 'y' && choice != 'n') {
            printf("Invalid choice. Please enter 'Y' to continue or 'N' to exit: ");
            while (getchar() != '\n'); // clear buffer before reading choice
            choice = getchar();
        }

    } while (choice == 'Y' || choice == 'y');

    printf("Thank you for using the converter. Goodbye!\n");
    
    return 0;
}