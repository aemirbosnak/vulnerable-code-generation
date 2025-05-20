//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_TERMS 20 // Maximum number of Fibonacci terms
#define DELAY 200000 // Delay between frames in microseconds

void print_line(const char* str, int width) {
    int len = strlen(str);
    int padding = (width - len) / 2;
    
    for (int i = 0; i < padding; ++i) {
        printf(" ");
    }
    printf("%s\n", str);
}

void visualize_fibonacci(int terms) {
    int fib[MAX_TERMS]; // Array to hold Fibonacci terms
    fib[0] = 0;
    fib[1] = 1;
    
    printf("\nGenerating Fibonacci Sequence:\n\n");
    print_line("FIBONACCI SEQUENCE VISUALIZER", 50);
    printf("\n");
    usleep(DELAY);
    
    for (int i = 2; i < terms; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    // Visualize the Fibonacci sequence
    for (int i = 0; i < terms; i++) {
        int num = fib[i];
        char buffer[20];
        sprintf(buffer, "%d", num);
        print_line(buffer, 50);
        usleep(DELAY);
    }
    
    printf("\nDone Visualizing!\n");
}

int main() {
    int terms = 10; // Default number of terms
    
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("How many terms would you like to visualize? (Up to %d): ", MAX_TERMS);
    
    if (scanf("%d", &terms) != 1 || terms < 1 || terms > MAX_TERMS) {
        printf("Invalid input. Using default of %d terms.\n", 10);
        terms = 10;
    }

    visualize_fibonacci(terms);
    
    return 0;
}