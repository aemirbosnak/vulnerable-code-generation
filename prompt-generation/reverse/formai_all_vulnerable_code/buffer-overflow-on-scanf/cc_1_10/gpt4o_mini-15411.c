//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void decimalToHexadecimal(int decimal, char *hexadecimal) {
    int index = 0;
    
    // Handle the special case of zero
    if (decimal == 0) {
        hexadecimal[index++] = '0';
    }

    while (decimal != 0) {
        int remainder = decimal % 16;

        // Convert the remainder to the right character
        if (remainder < 10) {
            hexadecimal[index++] = remainder + '0';
        } else {
            hexadecimal[index++] = (remainder - 10) + 'A';
        }

        decimal /= 16;
    }

    // Reverse the hex string since we've constructed it backwards
    for (int i = 0; i < index / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[index - i - 1];
        hexadecimal[index - i - 1] = temp;
    }
    
    hexadecimal[index] = '\0'; // Null terminate the string
}

void printHexadecimal(int decimal) {
    char hexadecimal[20]; // Allocation sufficient for conversion
    decimalToHexadecimal(decimal, hexadecimal);
    printf("Decimal: %d = Hexadecimal: %s\n", decimal, hexadecimal);
}

void getInputAndConvert() {
    int *numbers = NULL;
    size_t size = 0;
    size_t capacity = 2; // Initial capacity
    numbers = malloc(capacity * sizeof(int));
    
    if (!numbers) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter integers to convert to hexadecimal (enter -1 to stop):\n");

    while (1) {
        int num;
        printf("Input a decimal number: ");
        scanf("%d", &num);

        if (num == -1) { // Stop condition
            break;
        }

        if (size >= capacity) {
            capacity *= 2; // Increase capacity as necessary
            numbers = realloc(numbers, capacity * sizeof(int));

            if (!numbers) {
                fprintf(stderr, "Memory reallocation failed\n");
                exit(EXIT_FAILURE);
            }
        }

        numbers[size++] = num;
    }

    printf("\nHexadecimal Conversions:\n");
    for (size_t i = 0; i < size; i++) {
        printHexadecimal(numbers[i]);
    }

    free(numbers);
}

int main() {
    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    getInputAndConvert();
    
    printf("\nThank you for using the converter. Goodbye!\n");
    return 0;
}