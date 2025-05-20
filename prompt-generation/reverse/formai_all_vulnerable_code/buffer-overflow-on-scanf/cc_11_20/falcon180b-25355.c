//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_COLORS 256

enum {
    RED = 1,
    GREEN = 2,
    BLUE = 4,
    YELLOW = RED | GREEN,
    CYAN = GREEN | BLUE,
    MAGENTA = RED | BLUE,
    WHITE = RED | GREEN | BLUE
};

int main() {
    int color;
    char input[10];

    printf("Enter a color code (in hexadecimal): ");
    scanf("%s", input);

    if (strlen(input)!= 6 || input[0]!= '#') {
        printf("Invalid color code\n");
        return 1;
    }

    color = 0;
    for (int i = 1; i <= 5; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            color += input[i] - '0';
        } else if (input[i] >= 'A' && input[i] <= 'F') {
            color += (input[i] - 'A' + 10);
        } else {
            printf("Invalid color code\n");
            return 1;
        }
    }

    printf("Color Code: %d\n", color);
    printf("Color: ");

    if (color & RED) {
        printf("RED ");
    }

    if (color & GREEN) {
        printf("GREEN ");
    }

    if (color & BLUE) {
        printf("BLUE ");
    }

    if (color & YELLOW) {
        printf("YELLOW ");
    }

    if (color & CYAN) {
        printf("CYAN ");
    }

    if (color & MAGENTA) {
        printf("MAGENTA ");
    }

    if (color & WHITE) {
        printf("WHITE ");
    }

    printf("\n");

    return 0;
}