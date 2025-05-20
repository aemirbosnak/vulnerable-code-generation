//FormAI DATASET v1.0 Category: Color Code Converter ; Style: Cryptic
#include <stdio.h>

int num_of_digits(char nums[]);
int letter_to_num(char letter);
int convert_hex_to_dec(char hex[]);
void print_rgb_values(int r, int g, int b);

int main() {
    char hex_value[8];

    printf("Enter a valid HEX value (format: #RRGGBB): ");
    scanf("%s", hex_value);

    int r = convert_hex_to_dec(hex_value + 1);
    int g = convert_hex_to_dec(hex_value + 3);
    int b = convert_hex_to_dec(hex_value + 5);

    print_rgb_values(r, g, b);

    return 0;
}

// Get the number of digits in an array of numbers
int num_of_digits(char nums[]) {
    int num_of_digits = 0;
    for (int i = 0; nums[i] != '\0'; i++) {
        num_of_digits++;
    }
    return num_of_digits;
}

// Convert a hexadecimal letter to a number
int letter_to_num(char letter) {
    if (letter >= 'a' && letter <= 'f') {
        return letter - 'a' + 10;
    } else if (letter >= 'A' && letter <= 'F') {
        return letter - 'A' + 10;
    } else {
        return letter - '0';
    }
}

// Convert a hexadecimal value to decimal
int convert_hex_to_dec(char hex[]) {
    int num_of_hex_digits = num_of_digits(hex);
    int dec_value = 0;

    for (int i = 0; i < num_of_hex_digits; i++) {
        int num = letter_to_num(hex[num_of_hex_digits - i - 1]);
        dec_value += num * (1 << (4 * i));
    }

    return dec_value;
}

// Print out the RGB values
void print_rgb_values(int r, int g, int b) {
    printf("\nRGB Values:\n");
    printf("Red: %d\n", r);
    printf("Green: %d\n", g);
    printf("Blue: %d\n", b);
}