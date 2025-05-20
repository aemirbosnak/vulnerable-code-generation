//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void print_hex(int number) {
    printf("The hexadecimal representation of %d is: ", number);
    if (number == 0) {
        printf("0\n");
    } else {
        char hex[20];
        int index = 0;
        while (number > 0) {
            int remainder = number % 16;
            if (remainder < 10) {
                hex[index++] = 48 + remainder; // 48 is ASCII for '0'
            } else {
                hex[index++] = 87 + remainder; // 87 is ASCII for 'a' (10 + 87 = 'a')
            }
            number = number / 16;
        }
        // We need to reverse the string to display the correct order
        for (int i = index - 1; i >= 0; i--) {
            putchar(hex[i]);
        }
        putchar('\n');
    }
}

int main() {
    int decimal_number;
    
    printf("Welcome to the Grateful Hexadecimal Converter!\n");
    printf("Enter your decimal number, and let’s convert it to hexadecimal together.\n");

    while (1) {
        printf("\nPlease enter a positive decimal integer (or -1 to exit): ");
        scanf("%d", &decimal_number);
        
        if (decimal_number == -1) {
            printf("Thank you for using the Grateful Hexadecimal Converter!\n");
            printf("Your enthusiasm for learning is greatly appreciated!\n");
            break;
        } 

        if (decimal_number < 0) {
            printf("We can only convert positive numbers! Let's try that again.\n");
            continue;
        }
        
        print_hex(decimal_number);
    }

    return 0;
}