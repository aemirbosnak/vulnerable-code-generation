//FormAI DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
#include <stdio.h>

// Convert an integer to binary
void intToBinary(int n) {
    int binary[32], i = 0;

    // Convert the decimal number to binary
    while (n > 0) {
        binary[i++] = n % 2;
        n /= 2;
    }

    // Print the binary number
    printf("\nThe binary representation of the given integer is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

// Convert a binary string to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0, base = 1, length = 0;
    char* temp = binary;

    // Calculate the length of the binary string
    while (*temp != '\0') {
        length++;
        temp++;
    }

    // Convert the binary string to decimal
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }

    return decimal;
}

int main() {
    int choice, num;
    char binary[32];

    do {
        // Print menu
        printf("\n1. Convert integer to binary");
        printf("\n2. Convert binary to integer");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Convert integer to binary
                printf("\nEnter an integer: ");
                scanf("%d", &num);
                intToBinary(num);
                break;

            case 2:
                // Convert binary to integer
                printf("\nEnter a binary string: ");
                scanf("%s", binary);
                printf("\nThe decimal representation of the given binary is: %d", binaryToDecimal(binary));
                break;

            case 3:
                // Exit program
                printf("\nExiting...");
                break;

            default:
                // Handle invalid choice
                printf("\nInvalid choice. Please try again.");
        }
    } while (choice != 3);

    return 0;
}