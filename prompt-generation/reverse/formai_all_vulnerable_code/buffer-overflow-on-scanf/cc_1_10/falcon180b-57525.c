//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_COLORS 8

enum colors {
    RED,
    BLUE,
    GREEN,
    YELLOW,
    ORANGE,
    PURPLE,
    BLACK,
    WHITE
};

char *color_names[NUMBER_OF_COLORS] = {
    "Red",
    "Blue",
    "Green",
    "Yellow",
    "Orange",
    "Purple",
    "Black",
    "White"
};

int main() {
    int choice;
    char input[50];
    enum colors color;

    printf("Welcome to the Color Code Converter!\n");
    printf("Please enter a color code (e.g. #FF0000 for red): ");
    scanf("%s", input);

    // Check if input is a valid hexadecimal number
    if (strlen(input)!= 7 || input[0]!= '#') {
        printf("Invalid input. Please enter a valid hexadecimal color code.\n");
        return 1;
    }

    // Convert hexadecimal color code to decimal value
    int decimal_value = 0;
    for (int i = 1; i < strlen(input); i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            decimal_value = decimal_value * 16 + input[i] - '0';
        } else if (input[i] >= 'A' && input[i] <= 'F') {
            decimal_value = decimal_value * 16 + input[i] - 'A' + 10;
        } else {
            printf("Invalid input. Please enter a valid hexadecimal color code.\n");
            return 1;
        }
    }

    // Convert decimal value to color name
    for (int i = 0; i < NUMBER_OF_COLORS; i++) {
        if (decimal_value == i) {
            color = (enum colors) i;
            printf("The color code %s represents the color %s.\n", input, color_names[color]);
            break;
        }
    }

    return 0;
}