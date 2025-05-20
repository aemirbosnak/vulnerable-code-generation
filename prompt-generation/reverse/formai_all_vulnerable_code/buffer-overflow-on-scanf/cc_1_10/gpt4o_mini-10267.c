//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to print colors
void print_color(const char* color, const char* text) {
    printf("%s%s\033[0m", color, text);
}

// Colors for romantic effect
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

void print_fibonacci(int n) {
    long long int t1 = 0, t2 = 1, nextTerm = 0;

    printf("\n\n");
    print_color(RED, "  Each number, like a heartbeat, flows,\n");
    print_color(GREEN, "  In the Golden Ratio, love's sequence grows.\n\n");
    print_color(YELLOW, "  Behold the Fibonacci, a dance of souls,\n");
    print_color(BLUE, "  Connecting us all, as the universe extols.\n\n");

    int spaces = 4;
    for (int i = 1; i <= n; ++i) {
        print_color(CYAN, "  ");
        if (i == 1) {
            printf("%lld", t1);
            nextTerm = t1;
        } else if (i == 2) {
            printf("%lld", t2);
            nextTerm = t2;
        } else {
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            printf("%lld", nextTerm);
        }

        for (int j = 1; j <= spaces; ++j) {
            print_color(RED, "  ");
        }
        
        // New lines to break the rhythm
        if (i % 10 == 0) {
            printf("\n");
        }
        
        sleep(1); // Slow down the display for a romantic feel
    }
    
    printf("\n\n");
    print_color(MAGENTA, "With each step higher, a delicate tease,\n");
    print_color(CYAN, "Fibonacci whispers in the autumn breeze.\n");
    print_color(RED, "  Thus in nature her patterns align,\n");
    print_color(GREEN, "  The secrets of love, in each line we find.\n");
}

int main() {
    int n;

    print_color(RED, "Welcome to the Fibonacci Sequence Visualizer!\n");
    print_color(GREEN, "Let us embark on a journey of love and numbers...\n");
    
    printf("\nHow many terms of the Fibonacci sequence do you desire? (Enter a number): ");
    scanf("%d", &n);
    
    if (n <= 0) {
        print_color(YELLOW, "Ah, my dear, such a choice is impossible, let’s cherish some terms.\n");
        return 0;
    }

    print_fibonacci(n);
    print_color(BLUE, "As we conclude this dance of numbers, remember:\n");
    print_color(MAGENTA, "Every Fibonacci number is a gentle reminder that love grows infinitely.\n");

    return 0;
}