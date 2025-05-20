//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void decimalToHexadecimal(int decimal) {
    char hexadecimal[100];
    int index = 0;

    while (decimal > 0) {
        int remainder = decimal % 16;

        // Convert remainder to corresponding hex character
        if (remainder < 10) {
            hexadecimal[index] = remainder + '0';
        } else {
            hexadecimal[index] = (remainder - 10) + 'A';
        }
        index++;
        decimal /= 16;
    }
    
    // Output the hexadecimal representation
    printf("Your hexadecimal number is: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }
    printf("\n");
}

int main() {
    int decimalNumber;

    printf("Welcome to the Hexadecimal Converter!\n");
    printf("------------------------------------------------\n");
    
    while (1) {
        printf("Please enter a decimal number (or -1 to exit): ");
        scanf("%d", &decimalNumber);

        // Exit condition
        if (decimalNumber == -1) {
            printf("Thank you for using the Hexadecimal Converter!\n");
            break;
        }

        // Validate input
        if (decimalNumber < 0) {
            printf("Oops! That's not a valid decimal number. Try again...\n");
            continue;
        }

        // Call conversion function
        decimalToHexadecimal(decimalNumber);
        printf("------------------------------------------------\n");
    }

    return 0;
}