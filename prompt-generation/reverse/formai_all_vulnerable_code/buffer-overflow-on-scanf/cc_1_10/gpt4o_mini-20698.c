//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: medieval
#include <stdio.h>

void display_fibonacci(int n) {
    int a = 0, b = 1, c, i;
    
    printf("Ye Fibonacci Sequence, noble traveler:\n");
    printf("F(0) = %d\n", a);
    printf("F(1) = %d\n", b);

    for (i = 2; i < n; i++) {
        c = a + b;
        printf("F(%d) = %d\n", i, c);
        a = b; // Update 'a'
        b = c; // Update 'b'
    }
}

void visualize_fibonacci(int n) {
    int a = 0, b = 1, c, i;
    printf("\nVisualizing the Fibonacci Sequence:\n");

    for (i = 0; i < n; i++) {
        if (i == 0) {
            printf(" F(0): *\n");
        }
        else if (i == 1) {
            printf(" F(1): * *\n");
        }
        else {
            c = a + b;
            printf(" F(%d): ", i);
            for (int j = 0; j < c; j++) {
                printf("*");
            }
            printf("\n");
            a = b; 
            b = c; 
        }
    }
}

int main() {
    int length;

    printf("Welcome, Brave Adventurer!\n");
    printf("Enter the number of terms in the Fibonacci Sequence you wish to behold: ");
    scanf("%d", &length);

    if (length <= 0) {
        printf("Alas! The sequence must include at least one term.\n");
        return 1; // Exit the program
    }

    display_fibonacci(length);
    visualize_fibonacci(length);

    printf("\nMay your path be illuminated by the wisdom of the Fibonacci!\n");
    return 0;
}