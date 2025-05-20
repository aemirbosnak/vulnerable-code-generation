//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ioctl.h>

void clear_screen() {
    printf("\033[H\033[J");
}

void print_fibonacci(int num) {
    unsigned long long fib[num];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < num; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Get the terminal size
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int terminal_width = w.ws_col;

    printf("Fibonacci Sequence:\n\n");
    for (int i = 0; i < num; i++) {
        int len = printf("%llu ", fib[i]);
        
        // New line if the next number goes beyond terminal width
        if ((i + 1 < num) && ((len + 1 + (i > 0 ? 1 : 0)) % terminal_width > 0)) {
            printf("\n");
        }
    }
    printf("\n\n");
}

void visualize_fibonacci(int num) {
    unsigned long long fib[num];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < num; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Visualization
    printf("Visualizing Fibonacci Numbers:\n\n");
    for (int i = 0; i < num; i++) {
        printf("%llu: ", fib[i]);

        int stars = fib[i] / 1000; // Scale down for visualization
        for (int j = 0; j < stars; j++) {
            printf("█");
        }
        printf("\n");
        usleep(500000); // Sleep for half a second for better visibility
    }
}

int main() {
    int num;

    printf("Enter the number of Fibonacci numbers to calculate (up to 100): ");
    scanf("%d", &num);
    
    if (num <= 0 || num > 100) {
        printf("Please enter a number between 1 and 100.\n");
        return 1;
    }

    clear_screen();
    print_fibonacci(num);
    visualize_fibonacci(num);

    return 0;
}