//FormAI DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>

/*
   Function to convert hex color code into RGB values
   Input: character array of size 7, containing hex code starting from '#'
   Output: integer array of size 3, containing RGB values in decimal form
*/
int* hexToRGB(char hex_code[]) {
    int i, digit, val, index = 0;
    int* rgb = (int *) malloc(3 * sizeof(int));

    for (i = 1; i < 7; i += 2) {
        digit = hex_code[i]; // extract each digit from hex code
        if (digit >= '0' && digit <= '9') {
            val = digit - '0';
        } else if (digit >= 'a' && digit <= 'f') { // convert a-f to 10-15
            val = digit - 'a' + 10;
        } else if (digit >= 'A' && digit <= 'F') { // convert A-F to 10-15
            val = digit - 'A' + 10;
        } else {
            printf("Invalid hex code\n");
            exit(0);
        }

        // combine two digits and store in RGB array
        if (i == 1) {
            rgb[index] = val << 4; // store first digit in R value
        } else if (i == 3) {
            rgb[index] |= val; // store second digit in R value
            index++; // move to next index for G value
        } else if (i == 5) {
            rgb[index] = val << 4; // store first digit in B value
        } else if (i == 7) {
            rgb[index] |= val; // store second digit in B value
        }
    }
    return rgb;
}

/*
   Function to convert RGB values into hex color code
   Input: integer array of size 3, containing RGB values in decimal form
   Output: character array of size 7, containing hex code starting from '#'
*/
char* RGBToHex(int r, int g, int b) {
    char* hex_code = (char *) malloc(7 * sizeof(char));
    sprintf(hex_code, "#%02x%02x%02x", r, g, b);
    return hex_code;
}

int main() {
    int* rgb;
    char* hex_code;
    char input_hex[8];
    int r, g, b;

    // take input hex code
    printf("Enter hex code of a color: ");
    scanf("%s", input_hex);

    // convert hex code to RGB values
    rgb = hexToRGB(input_hex);

    // display RGB values to user
    printf("RGB values of %s are: ", input_hex);
    printf("%d, %d, %d\n", rgb[0], rgb[1], rgb[2]);

    // take input RGB values
    printf("\nEnter R,G,B values of a color (separated by commas): ");
    scanf("%d,%d,%d", &r, &g, &b);

    // check validity of RGB values
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("Invalid RGB values\n");
        exit(0);
    }

    // convert RGB values to hex code
    hex_code = RGBToHex(r, g, b);

    // display hex code to user
    printf("Hex code of (%d,%d,%d) is: %s\n", r, g, b, hex_code);

    // free dynamically allocated memory
    free(rgb);
    free(hex_code);

    return 0; 
}