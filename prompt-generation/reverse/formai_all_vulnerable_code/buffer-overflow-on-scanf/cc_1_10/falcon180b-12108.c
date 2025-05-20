//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function prototypes
void convert(char *string);
int is_valid_hex(char c);
int is_valid_rgb(char *string);

int main() {
    char string[100];
    printf("Enter a color code: ");
    scanf("%s", string);

    // check if input is valid
    if (is_valid_hex(string[0]) == 1) {
        printf("Hexadecimal color code: %s\n", string);
        convert(string);
    } else if (is_valid_rgb(string) == 1) {
        printf("RGB color code: %s\n", string);
        convert(string);
    } else {
        printf("Invalid color code.\n");
    }

    return 0;
}

// function to convert hexadecimal color code to RGB
void convert(char *string) {
    int i, j;
    char hex[3];
    char rgb[8];
    for (i = 0, j = 0; i < strlen(string); i += 2, j += 3) {
        strncpy(hex, &string[i], 2);
        hex[2] = '\0';
        int decimal = strtol(hex, NULL, 16);
        sprintf(&rgb[j], "%02X", decimal);
    }
    printf("RGB color code: %s\n", rgb);
}

// function to check if input is valid hexadecimal color code
int is_valid_hex(char c) {
    if (isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) {
        return 1;
    } else {
        return 0;
    }
}

// function to check if input is valid RGB color code
int is_valid_rgb(char *string) {
    int i, j;
    for (i = 0, j = 0; i < strlen(string); i++, j++) {
        if (isdigit(string[i])) {
            j++;
        } else {
            return 0;
        }
    }
    return 1;
}