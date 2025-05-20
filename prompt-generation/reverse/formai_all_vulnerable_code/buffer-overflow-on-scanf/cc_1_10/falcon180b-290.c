//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TERMS 10000
#define MAX_WIDTH 80
#define MAX_HEIGHT 50

// Function to generate Fibonacci sequence
int fibonacci(int n)
{
    if(n <= 1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

// Function to print Fibonacci sequence
void print_fibonacci(int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", fibonacci(i));
    printf("\n");
}

// Function to generate random color
int random_color()
{
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    return (r << 16) | (g << 8) | b;
}

// Function to print Fibonacci sequence with colors
void print_fibonacci_colors(int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        int color = random_color();
        printf("\033[38;5;%dm%d\033[0m ", (color >> 16) & 0xFF, fibonacci(i));
    }
    printf("\n");
}

// Function to visualize Fibonacci sequence
void visualize_fibonacci(int n)
{
    int i, j;
    int width = MAX_WIDTH;
    int height = MAX_HEIGHT;

    // Initialize screen
    printf("\033[2J");
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
            printf("\033[H\033[2J");
    }

    // Print Fibonacci sequence
    print_fibonacci_colors(n);

    // Wait for key press
    printf("\nPress any key to exit...");
    getchar();
}

int main()
{
    srand(time(NULL));

    // Get user input
    int n;
    printf("Enter the number of terms to generate: ");
    scanf("%d", &n);

    // Check for valid input
    if(n < 1 || n > MAX_TERMS)
    {
        printf("Invalid input.\n");
        return 1;
    }

    // Visualize Fibonacci sequence
    visualize_fibonacci(n);

    return 0;
}