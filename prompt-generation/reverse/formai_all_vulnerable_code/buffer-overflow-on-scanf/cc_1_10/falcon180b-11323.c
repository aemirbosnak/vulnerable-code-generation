//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert hex to rgb
void hexToRgb(char *hex, int *r, int *g, int *b) {
    // check if hex is valid
    if (strlen(hex)!= 7 || hex[0]!= '#') {
        printf("Invalid hex code.\n");
        exit(1);
    }

    // convert hex to rgb
    *r = strtol(hex + 1, NULL, 16);
    *g = strtol(hex + 3, NULL, 16);
    *b = strtol(hex + 5, NULL, 16);
}

// function to convert rgb to hex
void rgbToHex(int r, int g, int b, char *hex) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hex/rgb> <hex/rgb>\n", argv[0]);
        exit(1);
    }

    char input1[8], input2[8];
    int r1, g1, b1, r2, g2, b2;

    // get user input
    printf("Enter first color code (hex or rgb): ");
    scanf("%s", input1);
    hexToRgb(input1, &r1, &g1, &b1);

    printf("Enter second color code (hex or rgb): ");
    scanf("%s", input2);
    hexToRgb(input2, &r2, &g2, &b2);

    // calculate average color
    int avgR = (r1 + r2) / 2;
    int avgG = (g1 + g2) / 2;
    int avgB = (b1 + b2) / 2;

    // convert average color to hex
    char avgHex[8];
    rgbToHex(avgR, avgG, avgB, avgHex);

    // print results
    printf("Average color: %s\n", avgHex);

    return 0;
}