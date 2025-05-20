//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
#include <stdio.h>

void decToHex(int decimal) {
    char hex[100];
    int index = 0;

    if (decimal == 0) {
        printf("Hexadecimal representation: 0\n");
        return;
    }

    while (decimal > 0) {
        int remainder = decimal % 16;
        
        if (remainder < 10) {
            hex[index] = remainder + '0';
        } else {
            hex[index] = (remainder - 10) + 'A';
        }
        
        decimal /= 16; // Dividing decimal by 16 to shift right
        index++;
    }

    // Now we need to print it in reverse order
    printf("Hexadecimal representation: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]);
    }
    putchar('\n');
}

int main() {
    int decimal;
    printf("Hey there! Welcome to the Decimal to Hexadecimal Converter.\n");
    printf("Just a quick note: This program loves positive integers!\n\n");

    while (1) {
        printf("Please enter a positive decimal number (or negative number to exit): ");
        scanf("%d", &decimal);
        
        // Check for exit condition
        if (decimal < 0) {
            printf("Alright, exiting the program. Have a great day!\n");
            break;
        }
        
        decToHex(decimal); // Call our conversion function
        printf("\nWould you like to convert another number? (yes/no): ");
        char response[4];
        scanf("%s", response);
        
        if (response[0] == 'n' || response[0] == 'N') {
            printf("Thanks for using the converter! Bye now!\n");
            break;
        } else {
            printf("Awesome! Let's do another one.\n\n");
        }
    }
    
    return 0;
}