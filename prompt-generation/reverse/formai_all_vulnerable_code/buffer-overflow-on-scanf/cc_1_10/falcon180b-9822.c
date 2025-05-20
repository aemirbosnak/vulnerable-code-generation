//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define COLOR_RESET "\x1b[0m"
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_WHITE "\x1b[37m"

int main() {
    printf(COLOR_YELLOW "Welcome to the Cyberpunk Color Code Converter!\n" COLOR_RESET);
    printf(COLOR_BLUE "Enter a color code in hexadecimal format:\n" COLOR_RESET);
    char input[7];
    scanf("%s", input);
    int code = strtol(input, NULL, 16);

    switch (code) {
        case 0:
            printf(COLOR_RED "Error: Invalid color code\n" COLOR_RESET);
            break;
        case 1:
            printf(COLOR_GREEN "Color code: %s\n" COLOR_RESET, "Black");
            break;
        case 2:
            printf(COLOR_RED "Color code: %s\n" COLOR_RESET, "Red");
            break;
        case 3:
            printf(COLOR_GREEN "Color code: %s\n" COLOR_RESET, "Green");
            break;
        case 4:
            printf(COLOR_BLUE "Color code: %s\n" COLOR_RESET, "Blue");
            break;
        case 5:
            printf(COLOR_MAGENTA "Color code: %s\n" COLOR_RESET, "Purple");
            break;
        case 6:
            printf(COLOR_CYAN "Color code: %s\n" COLOR_RESET, "Cyan");
            break;
        case 7:
            printf(COLOR_WHITE "Color code: %s\n" COLOR_RESET, "White");
            break;
        default:
            printf(COLOR_RED "Error: Invalid color code\n" COLOR_RESET);
            break;
    }

    return 0;
}