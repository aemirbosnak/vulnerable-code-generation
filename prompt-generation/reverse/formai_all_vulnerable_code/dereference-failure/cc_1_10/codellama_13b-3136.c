//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: Romeo and Juliet
/*
 * Romeo and Juliet Color Code Converter
 *
 * Convert a color code from one format to another
 *
 * Usage:
 *   $ ./color-converter <code> <from> <to>
 *
 * where:
 *   <code> is the color code to convert
 *   <from> is the format of the color code (e.g. RGB, HEX, etc.)
 *   <to> is the format to convert the color code to
 *
 * Example:
 *   $ ./color-converter #FF0000 RGB HEX
 *   #FF0000
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert RGB color code to HEX
char *rgb_to_hex(char *rgb) {
    char *hex = malloc(7 * sizeof(char));
    sprintf(hex, "#%02x%02x%02x", (unsigned char) rgb[0], (unsigned char) rgb[1], (unsigned char) rgb[2]);
    return hex;
}

// Function to convert HEX color code to RGB
char *hex_to_rgb(char *hex) {
    char *rgb = malloc(3 * sizeof(char));
    sscanf(hex, "#%02x%02x%02x", (unsigned char *) rgb, (unsigned char *) rgb + 1, (unsigned char *) rgb + 2);
    return rgb;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./color-converter <code> <from> <to>\n");
        return 1;
    }

    char *code = argv[1];
    char *from = argv[2];
    char *to = argv[3];

    if (strcmp(from, "RGB") == 0 && strcmp(to, "HEX") == 0) {
        printf("%s\n", rgb_to_hex(code));
    } else if (strcmp(from, "HEX") == 0 && strcmp(to, "RGB") == 0) {
        printf("%s\n", hex_to_rgb(code));
    } else {
        printf("Invalid format\n");
    }

    return 0;
}