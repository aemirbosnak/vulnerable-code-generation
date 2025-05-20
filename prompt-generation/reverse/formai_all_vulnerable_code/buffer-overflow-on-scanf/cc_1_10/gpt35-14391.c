//FormAI DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// C Color Code Converter

char* hex_to_rgb(char* hex) {

    char r[3] = {hex[1], hex[2], '\0'};
    char g[3] = {hex[3], hex[4], '\0'};
    char b[3] = {hex[5], hex[6], '\0'};

    int red = strtol(r, NULL, 16);
    int green = strtol(g, NULL, 16);
    int blue = strtol(b, NULL, 16);

    char *rgb = (char*) malloc(12);
    sprintf(rgb, "rgb(%d,%d,%d)", red, green, blue);

    return rgb;
}

char* rgb_to_hex(char *rgb) {

    int r, g, b;
    char hex[7];

    sscanf(rgb, "rgb(%d,%d,%d)", &r, &g, &b);

    sprintf(hex, "#%02x%02x%02x", r, g, b);

    char *hexcode = (char*) malloc(8);
    strcpy(hexcode, hex);

    return hexcode;
}

int main() {

    char option;
    char answer[100];

    printf("Enter C to convert hex code to RGB or R to convert RGB code to hex: ");
    scanf(" %c", &option);

    if (option == 'C' || option == 'c') {
        printf("Enter the hex code: ");
        scanf(" %s", answer);

        char *rgb = hex_to_rgb(answer);
        printf("The RGB code is %s.\n", rgb);
        free(rgb);
    }

    else if (option == 'R' || option == 'r') {
        printf("Enter the RGB code: ");
        scanf(" %[^\n]", answer);

        char *hex = rgb_to_hex(answer);
        printf("The hex code is %s.\n", hex);
        free(hex);
    }

    else {
        printf("Invalid Option!\n");
    }

    return 0;
}