//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 8

// Function prototypes
void printHex(int num);
char* decimalToHex(int num);
void toUppercase(char* str);

int main() {
    int number, choice;
    
    printf("Welcome to the Hexadecimal Converter!\n\n");

    while (1) {
        printf("Enter a decimal number (0 to exit): ");
        scanf("%d", &number);
        
        if (number == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        if (number < 0) {
            printf("Please enter a non-negative integer.\n");
            continue;
        }
        
        printf("You entered: %d\n", number);
        
        // Calling the function to print hex representation
        printHex(number);

        printf("\nWould you like to convert another number? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        }
    }

    return 0;
}

// This function prints the hexadecimal equivalent
void printHex(int num) {
    char* hexRepresentation = decimalToHex(num);
    
    printf("Hexadecimal representation: %s\n", hexRepresentation);
    
    free(hexRepresentation); // Clean up memory allocation
}

// Converts decimal number to hexadecimal
char* decimalToHex(int num) {
    char* hexStr = (char*)malloc(MAX_DIGITS + 1);
    if (hexStr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    int index = 0;
    
    while (num > 0) {
        int remainder = num % 16; // get remainder
        hexStr[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A'); // Convert to char
        
        num /= 16; // Move to next digit
    }
    
    hexStr[index] = '\0'; // Null-terminate the string
    toUppercase(hexStr); // Convert string to uppercase
  
    // Reverse the string
    for (int i = 0; i < index / 2; i++) {
        char temp = hexStr[i];
        hexStr[i] = hexStr[index - i - 1];
        hexStr[index - i - 1] = temp;
    }
    
    return hexStr;
}

// Function to convert string to uppercase
void toUppercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'f') {
            str[i] -= 32; // Convert to uppercase
        }
    }
}