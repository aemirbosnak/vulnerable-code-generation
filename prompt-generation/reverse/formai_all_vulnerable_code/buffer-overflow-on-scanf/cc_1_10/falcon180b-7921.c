//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7

typedef enum {
    RED = 31,
    GREEN = 32,
    BLUE = 34,
    YELLOW = 33,
    CYAN = 36,
    MAGENTA = 35,
    WHITE = 37
} ColorCode;

void printColor(ColorCode color, char* str) {
    printf("%c%s%c", 27, "[", color);
    printf("%s", str);
    printf("%c", 27);
    printf("[0m");
}

int main() {
    char input[MAX_CODE_LENGTH];
    printf("Enter a color code (up to %d characters): ", MAX_CODE_LENGTH);
    scanf("%s", input);

    ColorCode color = RED;
    if (strcmp(input, "red") == 0) {
        color = RED;
    } else if (strcmp(input, "green") == 0) {
        color = GREEN;
    } else if (strcmp(input, "blue") == 0) {
        color = BLUE;
    } else if (strcmp(input, "yellow") == 0) {
        color = YELLOW;
    } else if (strcmp(input, "cyan") == 0) {
        color = CYAN;
    } else if (strcmp(input, "magenta") == 0) {
        color = MAGENTA;
    } else if (strcmp(input, "white") == 0) {
        color = WHITE;
    } else {
        printf("Invalid color code.\n");
        return 1;
    }

    printColor(color, "Hello, world!");

    return 0;
}