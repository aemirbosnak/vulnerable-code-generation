//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define MAX_SEQUENCE_LENGTH 100

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void print_sequence(int n)
{
    int sequence[MAX_SEQUENCE_LENGTH];
    int i;

    // Generate the sequence
    for (i = 0; i < n; i++)
    {
        sequence[i] = fibonacci(i);
    }

    // Print the sequence
    printf("Fibonacci Sequence:\n");
    printf("%d", sequence[0]);
    for (i = 1; i < n; i++)
    {
        printf(", %d", sequence[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int n;

    // Get the number of terms to compute
    printf("Enter the number of terms to compute: ");
    scanf("%d", &n);
    if (n > MAX_SEQUENCE_LENGTH)
    {
        printf("Error: maximum sequence length exceeded.\n");
        exit(1);
    }

    // Print the sequence
    print_sequence(n);

    // Wait for the user to press a key
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    if (ch == 10)
    {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return 0;
    }
}