//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to convert decimal to hexadecimal
void decimal_to_hexadecimal(int decimal) {
    char hexadecimal[10];
    int i = 0;
    int temp = decimal;
    
    // Iterate until the decimal number becomes zero
    while (temp!= 0) {
        // Get the remainder when divided by 16
        int remainder = temp % 16;
        
        // Convert the remainder to hexadecimal character
        if (remainder < 10) {
            hexadecimal[i] = remainder + '0';
        } else {
            hexadecimal[i] = remainder + 'A' - 10;
        }
        
        // Move to the next digit
        i++;
        
        // Divide the number by 16
        temp /= 16;
    }
    
    // Reverse the hexadecimal string
    for (i = 0; i < strlen(hexadecimal); i++) {
        printf("%c", hexadecimal[strlen(hexadecimal) - i - 1]);
    }
}

int main() {
    int choice;
    int decimal;
    
    printf("Welcome to the Medieval Hexadecimal Converter!\n");
    printf("Enter 1 to convert decimal to hexadecimal:\n");
    printf("Enter 2 to exit:\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Enter a decimal number to convert to hexadecimal:\n");
        scanf("%d", &decimal);
        decimal_to_hexadecimal(decimal);
    } else if (choice == 2) {
        printf("Exiting...\n");
    } else {
        printf("Invalid choice! Exiting...\n");
    }
    
    return 0;
}