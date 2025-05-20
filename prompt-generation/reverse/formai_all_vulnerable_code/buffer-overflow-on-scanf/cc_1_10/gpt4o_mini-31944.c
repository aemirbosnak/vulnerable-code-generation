//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHexadecimal(int decimal) {
    // Function to print the hexadecimal representation of a decimal number
    if (decimal < 0) {
        printf("Invalid input! Please enter a non-negative integer.\n");
        return;
    }
    printf("The hexadecimal representation of %d is: 0x", decimal);
    if (decimal == 0) {
        printf("0\n");
    } else {
        // Create an array to store hexadecimal characters
        char hex[20];
        int index = 0;
        
        while (decimal > 0) {
            int remainder = decimal % 16;
            if (remainder < 10) {
                hex[index++] = remainder + '0'; // Convert to ASCII
            } else {
                hex[index++] = (remainder - 10) + 'A'; // Convert to ASCII for A-F
            }
            decimal /= 16;
        }
        
        // Print hexadecimal in reverse order
        for (int i = index - 1; i >= 0; i--) {
            printf("%c", hex[i]);
        }
        printf("\n");
    }
}

void printMenu() {
    // Function to display the menu to the user
    printf("\n--------- Hexadecimal Converter ---------\n");
    printf("1. Convert a decimal number to hexadecimal\n");
    printf("2. Exit\n");
    printf("---------------------------------------\n");
    printf("Please select an option (1 or 2): ");
}

int main() {
    int choice, decimal;
    
    do {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a non-negative decimal number: ");
                scanf("%d", &decimal);
                printHexadecimal(decimal);
                break;
            case 2:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}