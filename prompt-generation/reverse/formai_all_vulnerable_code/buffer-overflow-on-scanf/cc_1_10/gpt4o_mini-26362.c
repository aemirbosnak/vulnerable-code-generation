//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void convertToHex(int decimal, char *hex);

int main() {
    int *decimals;  // Pointer to hold dynamic array of decimal values
    int numValues;  // Number of values to convert
    char hex[9];    // String to hold the hexadecimal value

    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    printf("Enter the number of decimal values you want to convert: ");
    scanf("%d", &numValues);
    
    // Dynamically allocate memory for decimals array
    decimals = (int *)malloc(numValues * sizeof(int));
    if (decimals == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    
    // Input decimal values
    for (int i = 0; i < numValues; i++) {
        printf("Enter decimal value %d: ", i + 1);
        scanf("%d", &decimals[i]);
    }
    
    // Convert and print hexadecimal values
    printf("\nDecimal to Hexadecimal Conversion:\n");
    printf("Decimal\tHexadecimal\n");
    printf("---------------\n");
    for (int i = 0; i < numValues; i++) {
        convertToHex(decimals[i], hex);
        printf("%d\t%s\n", decimals[i], hex);
    }
    
    // Free allocated memory
    free(decimals);
    decimals = NULL;

    printf("\nThank you for using the converter!\n");
    return 0;
}

// Function to convert decimal to hexadecimal
void convertToHex(int decimal, char *hex) {
    char temp[9]; // Temporary string to hold characters
    int index = 0; // Index for storing characters
    int remainder;  // Variable to hold remainder

    if (decimal == 0) {
        hex[0] = '0';
        hex[1] = '\0';
        return;
    }

    // Conversion loop
    while (decimal != 0) {
        remainder = decimal % 16; // Get remainder
        if (remainder < 10) {
            temp[index++] = remainder + '0'; // Convert to character
        } else {
            temp[index++] = (remainder - 10) + 'A'; // Convert to character A-F
        }
        decimal /= 16; // Divide decimal by 16
    }

    // Reverse the string
    for (int i = 0; i < index; i++) {
        hex[i] = temp[index - i - 1];
    }
    hex[index] = '\0'; // Null-terminate the string
}