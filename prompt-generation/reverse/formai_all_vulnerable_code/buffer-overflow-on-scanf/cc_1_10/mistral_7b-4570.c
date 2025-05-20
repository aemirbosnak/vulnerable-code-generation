//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"

void print_color(char color) {
    switch (color) {
        case 'R':
            printf(RED);
            break;
        case 'G':
            printf(GREEN);
            break;
        case 'B':
            printf(BLUE);
            break;
        case 'Y':
            printf(YELLOW);
            break;
        default:
            printf(RESET);
            break;
    }
}

int main() {
    char shape;
    printf("Enter a shape (R for rectangle, S for square, T for triangle): ");
    scanf("%c", &shape);

    printf(RESET);

    switch (shape) {
        case 'R':
            printf("Coloring a rectangle...\n");
            print_color('R');
            printf("Color: RED\n");
            print_color('G');
            printf("Color: GREEN\n");
            print_color('B');
            printf("Color: BLUE\n");
            print_color('Y');
            printf("Color: YELLOW\n");
            print_color('R');
            printf("Color: RED\n");
            print_color(RESET);
            break;
        case 'S':
            printf("Coloring a square...\n");
            print_color('B');
            printf("Color: BLUE\n");
            print_color('B');
            print_color('B');
            print_color('B');
            print_color('B');
            print_color(RESET);
            break;
        case 'T':
            printf("Coloring a triangle...\n");
            print_color('G');
            print_color('G');
            print_color(RESET);
            print_color('G');
            print_color('G');
            print_color(RESET);
            print_color('G');
            print_color('G');
            print_color('R');
            print_color('R');
            print_color('R');
            print_color(RESET);
            break;
        default:
            printf("Invalid shape.\n");
            break;
    }

    return 0;
}