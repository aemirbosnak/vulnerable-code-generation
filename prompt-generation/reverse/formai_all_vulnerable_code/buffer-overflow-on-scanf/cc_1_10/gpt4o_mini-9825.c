//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: shape shifting
#include <stdio.h>

void print_shape(int n, int shape_type) {
    if (shape_type == 1) {
        for (int i = 0; i < n; i++)
            printf("* ");
        printf("\n");
    } else if (shape_type == 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++)
                printf("* ");
            printf("\n");
        }
    } else if (shape_type == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = n - i; j > 1; j--)
                printf(" ");
            for (int j = 0; j <= i; j++)
                printf("* ");
            printf("\n");
        }
    } else if (shape_type == 4) {
        for (int i = 0; i < n; i++)
            printf("  *   \n");
        printf(" * * * \n");
        printf("* * * * *\n");
    }
}

int main() {
    int n, f0 = 0, f1 = 1, fn;
    
    printf("Enter the number of Fibonacci numbers to visualize: ");
    scanf("%d", &n);

    printf("\nFibonacci Sequence Visualizer\n");
    printf("Generating Fibonacci numbers...\n");

    // Visualize Fibonacci numbers
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            fn = f0;
        } else if (i == 1) {
            fn = f1;
        } else {
            fn = f0 + f1;
            f0 = f1;
            f1 = fn;
        }
        
        printf("Fibonacci %d: %d\n", i + 1, fn);
        int shape_type = (i % 4) + 1; // Change shape with each Fibonacci number
        print_shape(fn < 5 ? fn : fn % 20, shape_type); // Keep visual manageable
    }

    printf("\nEnjoy the colorful Fibonacci shapes!\n");
    return 0;
}