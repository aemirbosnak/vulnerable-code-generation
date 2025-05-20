//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 256

void toHexadecimal(unsigned int number, char *hexString) {
    int temp;
    int i = 0;
    
    // Build the hexadecimal string in reverse
    do {
        temp = number % 16;
        if (temp < 10) {
            hexString[i++] = (char)(temp + '0');  // Convert 0-9 to '0'-'9'
        } else {
            hexString[i++] = (char)(temp - 10 + 'A');  // Convert 10-15 to 'A'-'F'
        }
        number /= 16;
    } while (number != 0);
    
    // Add null terminator
    hexString[i] = '\0';
    
    // Reverse the string to get the correct order
    int start = 0;
    int end = i - 1;
    char tempChar;
    while (start < end) {
        tempChar = hexString[start];
        hexString[start] = hexString[end];
        hexString[end] = tempChar;
        start++;
        end--;
    }
}

void displayMenu() {
    printf("========================================\n");
    printf("           Hexadecimal Converter        \n");
    printf("========================================\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Exit\n");
    printf("========================================\n");
}

int main() {
    unsigned int number;
    char hexString[MAX_BUFFER];

    while (1) {
        displayMenu();
        int choice;
        printf("Enter your choice (1-2): ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Please enter a number.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                if (scanf("%u", &number) != 1) {
                    fprintf(stderr, "Invalid input! Please enter a valid decimal number.\n");
                    // Clear input buffer
                    while (getchar() != '\n');
                    continue;
                }

                toHexadecimal(number, hexString);
                printf("The hexadecimal representation of %u is: %s\n", number, hexString);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                fprintf(stderr, "Invalid choice! Please select 1 or 2.\n");
                break;
        }
        // Clear input buffer
        while (getchar() != '\n');
    }

    return 0;
}