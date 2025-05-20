//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

int main() {
    char input[100];
    int r, g, b;

    printf("Enter a color in RGB format (e.g., 255 255 255): ");
    scanf("%d %d %d", &r, &g, &b);

    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("Invalid RGB values. Please enter values between 0 and 255.\n");
        return 1;
    }

    printf("The color code in HTML format is: #%02x%02x%02x\n", r, g, b);

    if (r == 0 && g == 0 && b == 0) {
        printf("The color is %sblack%s.\n", BLACK, RESET);
    } else if (r == 255 && g == 0 && b == 0) {
        printf("The color is %sred%s.\n", RED, RESET);
    } else if (r == 0 && g == 255 && b == 0) {
        printf("The color is %sgreen%s.\n", GREEN, RESET);
    } else if (r == 255 && g == 255 && b == 0) {
        printf("The color is %syellow%s.\n", YELLOW, RESET);
    } else if (r == 0 && g == 0 && b == 255) {
        printf("The color is %sblue%s.\n", BLUE, RESET);
    } else if (r == 255 && g == 0 && b == 255) {
        printf("The color is %smagenta%s.\n", MAGENTA, RESET);
    } else if (r == 0 && g == 255 && b == 255) {
        printf("The color is %scyan%s.\n", CYAN, RESET);
    } else if (r == 255 && g == 255 && b == 255) {
        printf("The color is %swhite%s.\n", WHITE, RESET);
    } else {
        printf("The color is a custom color.\n");
    }

    return 0;
}