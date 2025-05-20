//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: Claude Shannon
/*
 * Color Code Converter
 *
 * Converts RGB color codes to hexadecimal and vice versa.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED 0
#define GREEN 1
#define BLUE 2

int main() {
    char *input;
    char *output;
    int r, g, b;

    printf("Enter a color code (e.g. #FF0000): ");
    scanf("%s", input);

    if (strlen(input) == 4) {
        // Convert shorthand hex code to full hex code
        output = malloc(sizeof(char) * 7);
        strcpy(output, "#");
        strncat(output, input, 4);
        strncat(output, input, 4);
    } else if (strlen(input) == 7) {
        // Convert full hex code to RGB values
        r = (int) strtol(input + 1, NULL, 16);
        g = (int) strtol(input + 3, NULL, 16);
        b = (int) strtol(input + 5, NULL, 16);

        output = malloc(sizeof(char) * 4);
        sprintf(output, "%d,%d,%d", r, g, b);
    } else {
        printf("Invalid color code.");
        return 1;
    }

    printf("RGB value: %s\n", output);
    printf("Hex value: %s\n", input);

    free(output);
    return 0;
}