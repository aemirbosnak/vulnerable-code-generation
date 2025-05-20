//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1000

typedef enum {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    CYAN,
    MAGENTA,
    WHITE,
    BLACK,
    RESET
} ColorCode;

void print_color(ColorCode color_code, char* message) {
    printf("\033[1;%dm%s\033[0m", (int)color_code, message);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <color_code>\n", argv[0]);
        return 1;
    }

    ColorCode color_code = RED;
    if (strcmp(argv[1], "red") == 0) {
        color_code = RED;
    } else if (strcmp(argv[1], "green") == 0) {
        color_code = GREEN;
    } else if (strcmp(argv[1], "blue") == 0) {
        color_code = BLUE;
    } else if (strcmp(argv[1], "yellow") == 0) {
        color_code = YELLOW;
    } else if (strcmp(argv[1], "cyan") == 0) {
        color_code = CYAN;
    } else if (strcmp(argv[1], "magenta") == 0) {
        color_code = MAGENTA;
    } else if (strcmp(argv[1], "white") == 0) {
        color_code = WHITE;
    } else if (strcmp(argv[1], "black") == 0) {
        color_code = BLACK;
    } else if (strcmp(argv[1], "reset") == 0) {
        color_code = RESET;
    } else {
        printf("Invalid color code\n");
        return 1;
    }

    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, stdin)!= NULL) {
        int i = 0;
        while (line[i]!= '\0') {
            if (isalnum(line[i])) {
                print_color(color_code, &line[i]);
            } else {
                print_color(RESET, &line[i]);
            }
            i++;
        }
        printf("\n");
    }

    return 0;
}