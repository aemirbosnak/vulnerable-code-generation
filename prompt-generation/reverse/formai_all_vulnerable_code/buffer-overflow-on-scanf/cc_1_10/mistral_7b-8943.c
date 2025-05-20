//MISTRAL-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_FIB 51
#define WIDTH 41
#define HEIGHT 11
#define DELAY 100000

typedef struct {
    int x, y;
} point;

void gotoxy(int x, int y) {
    char buf[32];
    snprintf(buf, sizeof(buf), "\033[%d;%dH", y, x);
    write(STDOUT_FILENO, buf, strlen(buf));
}

void draw_fibonacci(int fib) {
    int i, x, y, a = 0, b = 1;
    point p1 = {0, 0}, p2 = {0, 1};

    for (i = 0; i < fib; i++) {
        x = 2 * i + 1;
        y = HEIGHT / 2 - i;

        if (i < 2) {
            gotoxy(x, y);
            putchar(i == 0 ? 'O' : 'X');
            continue;
        }

        gotoxy(x, y);
        putchar(' ');

        p1 = p2;
        p2.x = x;
        p2.y = y;

        a = b;
        b += p1.x;
    }

    gotoxy(WIDTH / 2, HEIGHT / 2);
    printf("Fibonacci(%d) = %d", fib, b);

    for (i = 0; i < fib; i++) {
        if (i < 2) continue;

        x = 2 * i + 1;
        y = HEIGHT / 2 - i;

        gotoxy(p2.x, p2.y);
        putchar(i % 2 == 0 ? 'O' : 'X');

        usleep(DELAY);
        gotoxy(x, y);
        putchar(' ');

        point temp = p1;
        p1 = p2;
        p2.x = x;
        p2.y = y;

        a = b;
        b += p1.x;
    }
}

int main() {
    int n;

    if (2 > scanf("%d", &n) || n > MAX_FIB || n < 0) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    printf("Fibonacci Sequence Visualizer\n");
    printf("Enter the number of Fibonacci numbers to print: %d\n", n);

    printf("\033[2J"); // Clear the terminal

    draw_fibonacci(n);

    return 0;
}