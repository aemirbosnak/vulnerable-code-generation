//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: multivariable
#include <stdio.h>

// Function to convert integer to hexadecimal
void toHexadecimal(int num, char* hexStr) {
    int index = 0;

    // Handle 0 explicitly
    if (num == 0) {
        hexStr[index++] = '0';
        hexStr[index] = '\0';
        return;
    }

    while (num != 0) {
        int remainder = num % 16;

        // Convert remainder to appropriate hex character
        if (remainder < 10) {
            hexStr[index++] = 48 + remainder; // ASCII '0' - '9'
        } else {
            hexStr[index++] = 87 + remainder; // ASCII 'a' - 'f' for 10-15
        }

        num /= 16;
    }
    
    hexStr[index] = '\0';
    
    // Reverse the string to get the correct order
    for (int start = 0, end = index - 1; start < end; start++, end--) {
        char temp = hexStr[start];
        hexStr[start] = hexStr[end];
        hexStr[end] = temp;
    }
}

// Print the result
void printConversionResults(int number, char* hexStr) {
    printf("The hexadecimal representation of %d is: %s\n", number, hexStr);
}

// Main function to accept input and execute conversion
int main() {
    int num, limit;
    char hexStr[20]; // Buffer to hold hexadecimal string

    printf("Welcome to the Hexadecimal Converter!\n");
    printf("How many numbers would you like to convert? ");
    scanf("%d", &limit);
    
    for (int i = 0; i < limit; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);

        // Convert to hexadecimal
        toHexadecimal(num, hexStr);
        
        // Print results
        printConversionResults(num, hexStr);
    }

    printf("Thank you for using the Hexadecimal Converter!\n");

    return 0;
}