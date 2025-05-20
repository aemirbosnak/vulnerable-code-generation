//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>

void print_shape(int length) {
    // Print a decorative header based on length
    for (int i = 0; i < length; i++) {
        printf(" * ");
    }
    printf("\n");
}

void print_hexadecimal(int number) {
    // Determine the necessary buffer size
    char hex_buffer[20];
    int index = 0;

    // Convert the integer to hexadecimal representation
    while (number != 0) {
        int remainder = number % 16;
        if (remainder < 10) {
            hex_buffer[index++] = remainder + '0';
        } else {
            hex_buffer[index++] = (remainder - 10) + 'A';
        }
        number /= 16;
    }

    // Print hex in reverse order
    printf("Hexadecimal: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hex_buffer[i]);
    }
    printf("\n");
}

int main() {
    int number;

    while (1) {
        printf("Enter a positive integer to convert to hexadecimal (or -1 to quit): ");
        scanf("%d", &number);
        
        if (number == -1) {
            break;
        }
        
        // Shape-shifting style header based on input length
        print_shape(10); // Decorative border
        printf("Converting number: %d\n", number);
        
        // Shape-shifting style conversion
        print_hexadecimal(number);
        
        print_shape(10); // Decorative border
        printf("\n");
    }

    printf("Exiting the Hexadecimal Converter. Goodbye!\n");
    return 0;
}