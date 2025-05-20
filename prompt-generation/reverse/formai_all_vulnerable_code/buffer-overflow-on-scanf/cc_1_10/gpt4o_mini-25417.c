//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void draw_fibonacci(int max_terms);
void draw_bar(int value, int max_value);
void clear_screen();

int main() {
    int num_terms;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    
    printf("Enter the number of terms to visualize (1-20): ");
    scanf("%d", &num_terms);
    
    if (num_terms < 1 || num_terms > 20) {
        printf("Please enter a number between 1 and 20.\n");
        return 1;
    }
    
    clear_screen();
    draw_fibonacci(num_terms);
    
    return 0;
}

void draw_fibonacci(int max_terms) {
    long long fib[max_terms];
    fib[0] = 0;
    if(max_terms > 1) {
        fib[1] = 1;
    }

    for (int i = 2; i < max_terms; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    long long max_value = fib[max_terms - 1];
    printf("Fibonacci Sequence Visualization:\n\n");

    for (int i = 0; i < max_terms; i++) {
        printf("Term %2d: ", i + 1);
        draw_bar(fib[i], max_value);
        printf(" (%lld)\n", fib[i]);
    }
}

void draw_bar(int value, int max_value) {
    int width = 50; // Width of the bar in characters
    int bar_length = (int)((double)value / max_value * width);
    
    printf("[");
    for (int j = 0; j < bar_length; j++) {
        printf("#");
    }
    
    for (int j = bar_length; j < width; j++) {
        printf(" ");
    }
    printf("]");
}

void clear_screen() {
    // UNIX/Linux system command to clear the terminal
    const char *CLEAR_SCREEN = "clear";
    system(CLEAR_SCREEN);
}