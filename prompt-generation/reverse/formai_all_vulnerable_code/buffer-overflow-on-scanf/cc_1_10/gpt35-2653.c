//FormAI DATASET v1.0 Category: Color Code Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *hex_to_rgb(char *hex);
char *rgb_to_hex(char *rgb);

char *hex_to_rgb(char *hex) {
    char *rgb = (char *)malloc(sizeof(char) * 7);

    int r, g, b;
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);

    sprintf(rgb, "%d,%d,%d", r, g, b);
    return rgb;
}

char *rgb_to_hex(char *rgb) {
    char *hex = (char *)malloc(sizeof(char) * 7);

    int r, g, b;
    sscanf(rgb, "%d,%d,%d", &r, &g, &b);

    sprintf(hex, "#%02x%02x%02x", r, g, b);
    return hex;
}

int main() {
    char input[10], code[10];

    printf("Color Conversion (Hex to RGB and RGB to Hex)\n");

    printf("Enter 'hex' to convert from Hex to RGB\n");
    printf("Enter 'rgb' to convert from RGB to Hex\n");
    printf("Enter 'exit' to exit the program\n\n");

    while (1) {
        printf("Enter command: ");
        scanf("%s", input);

        if (strcmp(input, "hex") == 0) {
            printf("Enter 6-digit hexadecimal color code: ");
            scanf("%s", code);
            if (strlen(code) != 6) {
                printf("Invalid input! Hexadecimal code should be 6 digits\n");
            } else {
                char *rgb = hex_to_rgb(code);
                printf("RGB equivalent of %s is %s\n", code, rgb);
                free(rgb);
            }
        } else if (strcmp(input, "rgb") == 0) {
            printf("Enter RGB color code (in the format R,G,B): ");
            scanf("%s", code);
            int count = 0;
            for (int i = 0; i < strlen(code); i++) {
                if (code[i] == ',') {
                    count++;
                }
            }
            if (count != 2) {
                printf("Invalid input! RGB color code should be in the format R,G,B\n");
            } else {
                char *hex = rgb_to_hex(code);
                printf("Hexadecimal equivalent of %s is %s\n", code, hex);
                free(hex);
            }
        } else if (strcmp(input, "exit") == 0) {
            printf("Exiting the program\n");
            break;
        } else {
            printf("Invalid command! Please try again\n");
        }
    }

    return 0;
}