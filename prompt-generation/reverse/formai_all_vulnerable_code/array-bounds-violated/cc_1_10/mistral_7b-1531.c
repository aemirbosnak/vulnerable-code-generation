//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 32
#define HEIGHT 16

typedef struct { char str[WIDTH + 1]; int len; } line_t;
line_t lines[HEIGHT];

void init_ascii() {
    for (int i = 0; i < HEIGHT; i++) {
        lines[i].len = 0;
        memset(lines[i].str, 0, WIDTH + 1);
    }
}

void print_ascii() {
    for (int i = 0; i < HEIGHT; i++) {
        printf("\n%s", lines[i].str);
    }
}

void set_pixel(int x, int y, char c) {
    int idx = y * WIDTH + x;
    lines[y].str[idx] = c;
    lines[y].len = idx + 1;
}

void draw_char(int x, int y, char c) {
    switch (c) {
        case 'A':
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i < 3 || (i == 3 && j == 1)) {
                        set_pixel(x + j, y + i, '*');
                    } else {
                        set_pixel(x + j, y + i, ' ');
                    }
                }
            }
            break;
        case 'B':
            // Draw 'B' character here...
            break;
        // Add more cases for other characters here...
        default:
            break;
    }
}

int main() {
    char text[100];
    init_ascii();

    printf("Enter a text to convert to ASCII art (max 100 characters): ");
    scanf("%s", text);

    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        int x = i % WIDTH;
        int y = i / WIDTH;

        draw_char(x, y, toupper(c));
    }

    print_ascii();

    return 0;
}