//FormAI DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hex to decimal
int hex_to_decimal(char hex[]) {
    int decimal = 0;
    int length = strlen(hex);

    for (int i = 0; i < length; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * pow(16, length - i - 1);
        } else if (toupper(hex[i]) >= 'A' && toupper(hex[i]) <= 'F') {
            decimal += (toupper(hex[i]) - 'A' + 10) * pow(16, length - i - 1);
        } else {
            printf("Invalid hex code!");
            exit(0);
        }
    }

    return decimal;
}

// Function to convert decimal to hex
char* decimal_to_hex(int decimal) {
    char hex[100];
    int remainder, quotient;
    int i = 1;

    while (decimal != 0) {
        remainder = decimal % 16;
        if (remainder < 10) {
            hex[i++] = remainder + 48;
        } else {
            hex[i++] = remainder + 55;
        }
        decimal /= 16;
    }

    // Create a char array to hold the hex value
    char* hex_value = malloc(i * sizeof(char));

    // Copy the hex value from the char array to the newly allocated array
    for (int j = 1; j < i; j++) {
        hex_value[j - 1] = hex[i - j];
    }

    // Add null terminator to the end of the hex value
    hex_value[i - 1] = '\0';

    return hex_value;
}

int main() {
    char color_code[7];
    printf("Enter the color code (in hex format): ");
    scanf("%s", color_code);

    // Convert hex to decimal
    int red = hex_to_decimal(strncpy(color_code, color_code + 1, 2));
    int green = hex_to_decimal(strncpy(color_code + 2, color_code + 3, 2));
    int blue = hex_to_decimal(strncpy(color_code + 4, color_code + 5, 2));

    // Convert decimal to hex
    char* new_red = decimal_to_hex(red);
    char* new_green = decimal_to_hex(green);
    char* new_blue = decimal_to_hex(blue);

    // Print the new color code
    printf("The new color code is #%s%s%s", new_red, new_green, new_blue);

    // Free the allocated memory
    free(new_red);
    free(new_green);
    free(new_blue);

    return 0;
}