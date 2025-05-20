//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the maximum number of terms to be calculated
#define MAX_TERMS 40

// Declare the function prototypes
void clear_screen();
void print_header();
void print_sequence(int n);

int main(int argc, char *argv[])
{
    // Initialize the first two terms of the sequence
    int fib[MAX_TERMS] = {0, 1};

    // Get the number of terms from the user
    int n;
    printf("Enter the number of terms to be calculated (maximum %d): ", MAX_TERMS);
    scanf("%d", &n);

    // Check that the number of terms is within the bounds
    if (n < 1 || n > MAX_TERMS) {
        printf("Error: Invalid number of terms.\n");
        exit(1);
    }

    // Print the initial header of the program
    clear_screen();
    print_header();

    // Generate and display the Fibonacci sequence
    print_sequence(n);

    // Wait for the user to press enter before exiting the program
    printf("\nPress enter to exit...");
    getchar();
    getchar();

    return 0;
}

// Function for clearing the console screen
void clear_screen()
{
    #ifdef _WIN32
        system("cls");
    #else
        printf("\033c");
    #endif
}

// Function for printing the program header
void print_header()
{
    printf("Fibonacci Sequence Visualizer\n");
    printf("==============================\n\n");
}

// Function for printing the Fibonacci sequence
void print_sequence(int n)
{
    int fib[MAX_TERMS] = {0, 1};

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    int max_digits = floor(log10(fib[n-1])) + 1;

    for (int i = 0; i < n; i++) {
        printf("%*d\n", max_digits, fib[i]);
        usleep(50000);
        clear_screen();
        print_header();
    }
}