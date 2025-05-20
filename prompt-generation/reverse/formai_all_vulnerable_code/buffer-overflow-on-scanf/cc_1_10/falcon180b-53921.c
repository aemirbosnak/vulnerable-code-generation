//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define NO_OF_COLORS 7

enum color {
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    WHITE = 37
};

void draw_pixel(int x, int y, int color) {
    printf("\033[38;5;%dm ", color);
}

void clear_screen() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("\033[0m ");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int x, y, color;
    char text[100];

    printf("Enter your text: ");
    scanf("%[^\n]", text);

    clear_screen();

    for (int i = 0; i < strlen(text); i++) {
        x = rand() % WIDTH;
        y = rand() % HEIGHT;
        color = rand() % NO_OF_COLORS;
        draw_pixel(x, y, color);
    }

    printf("\n");

    for (int i = 0; i < strlen(text); i++) {
        printf("%c", text[i]);
        for (int j = 0; j < NO_OF_COLORS; j++) {
            if (j == (rand() % NO_OF_COLORS)) {
                draw_pixel(rand() % WIDTH, rand() % HEIGHT, j);
            }
        }
    }

    printf("\n");

    return 0;
}