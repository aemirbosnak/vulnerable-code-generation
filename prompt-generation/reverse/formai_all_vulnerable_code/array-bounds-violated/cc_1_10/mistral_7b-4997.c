//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 32
#define HEIGHT 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    char symbol;
    Point pos;
} Art;

Art arts[] = {
    {'O', {1, 1}},
    {'X', {2, 1}},
    {'I', {3, 1}},
    {'V', {3, 2}},
    {'<', {4, 1}},
    {'>', {5, 1}},
    {'-', {6, 1}},
    {'^', {7, 1}},
    {'_', {8, 1}},
    {'>', {9, 1}},
    {'@', {10, 1}},
    {'&', {11, 1}},
    {'*', {12, 1}},
    {'(', {13, 1}},
    {')', {14, 1}},
    {'[', {15, 1}},
    {']', {16, 1}},
    {'{', {17, 1}},
    {'}', {18, 1}},
    {'|', {19, 1}},
    {'/', {20, 1}},
    {'\\', {21, 1}},
    {'1', {22, 1}},
    {'2', {23, 1}},
    {'3', {24, 1}},
    {'4', {25, 1}},
    {'5', {26, 1}},
    {'6', {27, 1}},
    {'7', {28, 1}},
    {'8', {29, 1}},
    {'9', {30, 1}},
    {'0', {31, 1}}
};

void print_art(Art art) {
    int row = art.pos.y;
    int col = art.pos.x;

    if (row >= 0 && row < HEIGHT && col >= 0 && col < WIDTH) {
        putchar(art.symbol);
    }
}

void print_ascii_art(const char *text) {
    int text_len = strlen(text);
    int i, j;

    for (i = 0; i < text_len; i++) {
        char c = toupper(text[i]);

        for (j = 0; j < sizeof(arts) / sizeof(Art); j++) {
            if (arts[j].symbol == c) {
                print_art(arts[j]);
                break;
            }
        }
    }

    putchar('\n');
}

int main() {
    char text[100];

    printf("Enter a satisfied message: ");
    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0';

    printf("\nYour satisfied message as ASCII art:\n");
    print_ascii_art(text);

    return 0;
}