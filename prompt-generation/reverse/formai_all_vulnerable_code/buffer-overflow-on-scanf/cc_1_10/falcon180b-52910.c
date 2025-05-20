//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7
#define HEX_CHARS "0123456789ABCDEF"

typedef struct {
    char *name;
    int value;
} ColorCode;

ColorCode *getColorCode(char *colorName) {
    ColorCode *colorCode = (ColorCode *)malloc(sizeof(ColorCode));
    if (colorCode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(colorCode->name, colorName);
    colorCode->value = -1;
    return colorCode;
}

void setColorCodeValue(ColorCode *colorCode, int value) {
    colorCode->value = value;
}

int getColorCodeValue(ColorCode *colorCode) {
    return colorCode->value;
}

void printColorCodeTable() {
    printf("Color Code Table:\n");
    printf("-----------------\n");
    printf("Color Name\tValue\n");
    printf("-----------------\n");
    printf("Black\t\t0\n");
    printf("White\t\t7\n");
    printf("Red\t\t1\n");
    printf("Green\t\t2\n");
    printf("Blue\t\t4\n");
    printf("Yellow\t\t3\n");
    printf("Magenta\t\t5\n");
    printf("Cyan\t\t6\n");
}

int main() {
    char colorName[50];
    int value;
    ColorCode *colorCode;

    printf("Enter the color name: ");
    scanf("%s", colorName);

    colorCode = getColorCode(colorName);
    if (colorCode->value == -1) {
        printf("Color not found in table.\n");
        exit(1);
    }

    value = getColorCodeValue(colorCode);
    printf("The %s color code is: %s\n", colorName, "0123456789ABCDEF"[value]);

    return 0;
}