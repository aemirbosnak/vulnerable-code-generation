//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>

void gotoxy(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

void clearScreen()
{
    printf("\033[2J");
}

void hideCursor()
{
    printf("\033[?25l");
}

void printFibonacci(int n)
{
    int a = 0, b = 1, c;
    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n\nPress any key to exit...");
}

int main()
{
    int n;
    struct termios oldt, newt;

    // Hide cursor
    hideCursor();

    // Get terminal settings
    tcgetattr(STDIN_FILENO, &oldt);

    // Set new terminal settings
    newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Clear screen
    clearScreen();

    // Print instructions
    printf("Enter the number of Fibonacci numbers to generate: ");

    // Get input
    scanf("%d", &n);

    // Print Fibonacci sequence
    printFibonacci(n);

    // Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    // Wait for key press
    getchar();

    return 0;
}