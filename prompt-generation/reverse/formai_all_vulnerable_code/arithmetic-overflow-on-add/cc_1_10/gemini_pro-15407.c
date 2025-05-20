//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define ESC_SEQ "\033"
#define COL_RESET ESC_SEQ"[0m"

typedef struct {
    int x;
    int y;
} coord;

void gotoxy(coord c) {
    printf(ESC_SEQ"[%d;%dH", c.y, c.x);
}

void clear_screen() {
    printf(ESC_SEQ"[2J");
    gotoxy((coord){0, 0});
}

int fib(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

void draw_fibonacci(int n, int offset_x, int offset_y, bool invert) {
    coord c = {offset_x, offset_y};
    for (int i = 0; i < n; i++) {
        int fib_n = fib(i);
        if (invert) {
            fib_n = -fib_n;
        }
        gotoxy(c);
        printf(COL_RESET"%d", fib_n);
        c.x += abs(fib_n) + 1;
    }
}

int main() {
    int n;
    int offset_x;
    int offset_y;
    bool invert = false;

    printf("Enter the number of Fibonacci numbers to draw: ");
    scanf("%d", &n);

    printf("Enter the offset from the left (in characters): ");
    scanf("%d", &offset_x);

    printf("Enter the offset from the top (in lines): ");
    scanf("%d", &offset_y);

    printf("Invert the sequence (yes/no)? ");
    char c = getchar();
    if (c == 'y' || c == 'Y') {
        invert = true;
    }

    clear_screen();
    draw_fibonacci(n, offset_x, offset_y, invert);

    return 0;
}