//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 24
#define DELAY 100000

void gotoxy(int x, int y)
{
    printf("\033[%d;%df", y, x);
}

void draw(int x, int y, int n)
{
    gotoxy(x, y);
    printf("%d", n);
}

int main()
{
    // Disable line buffering
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int x = 0, y = 0, n1 = 0, n2 = 1, nn = 0, c = 0;
    while (1) {
        // Get key press
        c = getchar();
        if (c == 'q') {
            break;
        }

        // Calculate next Fibonacci number
        nn = n1 + n2;
        n1 = n2;
        n2 = nn;

        // Draw Fibonacci number
        draw(x, y, nn);

        // Move cursor to next position
        if (x == WIDTH - 1) {
            x = 0;
            y++;
        } else {
            x++;
        }

        // Delay
        usleep(DELAY);
    }

    // Restore line buffering
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return 0;
}