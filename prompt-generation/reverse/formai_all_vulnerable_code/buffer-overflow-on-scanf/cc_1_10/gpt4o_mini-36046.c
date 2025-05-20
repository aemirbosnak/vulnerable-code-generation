//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void printIntro() {
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("This program will convert decimal numbers to hexadecimal format.\n");
    printf("You can input multiple numbers, and type 'exit' when you are done.\n");
    printf("Let's begin!\n");
}

void convertToHexadecimal(int decimal, char *hexadecimal) {
    int index = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[index++] = remainder + '0';
        } else {
            hexadecimal[index++] = (remainder - 10) + 'A';
        }
        decimal /= 16;
    }
    hexadecimal[index] = '\0';
    
    // Reverse the string to get the correct hexadecimal representation
    for (int i = 0; i < index / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[index - i - 1];
        hexadecimal[index - i - 1] = temp;
    }
}

int main() {
    printIntro();

    // Allocate memory for the hexadecimal string
    char *hexadecimal = (char *)malloc(20 * sizeof(char));
    
    if (hexadecimal == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    while (1) {
        char input[20];
        printf("Enter a decimal number (or type 'exit' to quit): ");
        scanf("%s", input);

        // Check for exit condition
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Convert the string input to an integer
        int decimal = atoi(input);
        
        // Handle negative input gracefully
        if (decimal < 0) {
            printf("Please enter a non-negative integer.\n");
            continue;
        }

        convertToHexadecimal(decimal, hexadecimal);
        printf("Decimal: %d -> Hexadecimal: %s\n", decimal, hexadecimal);
    }

    // Free allocated memory
    free(hexadecimal);
    printf("Thank you for using the Hexadecimal Converter. Goodbye!\n");
    return 0;
}