//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the Fibonacci Sequence Visualizer!\n"
           "Here we show the Fibonacci Sequence with ASCII art!\n");

    int num1 = 0, num2 = 1, next = 0;
    int i, n;

    printf("Enter the number of terms you want in the sequence: ");
    scanf("%d", &n);

    printf("Here's what the sequence looks like!\n");

    // ASCII art time!
    printf(" [92m*\n");
    printf("  \\ \\\n");
    printf(" / \\ \\\n");
    printf("    \\ \\\n");
    printf("     \\ \\         [41m [1mFIZZBUZZ[0m\n");
    printf("      \\ \\\n");
    printf("       \\ \\\n");
    printf("        \\ \\\n");
    printf("         \\ \\\n");
    printf("          \\ \\\n");
    printf("           \\ \\\n");
    printf("            \\ \\\n");
    printf("             \\ \\\n");
    printf("              \\ \\\n");
    printf("               \\ \\\n");
    printf("                \\ \\\n");
    printf("                 \\ \\\n");
    printf("                  \\ \\\n");
    printf("                   \\ \\\n");
    printf("                    \\ \\\n");
    printf("                     \\ \\\n");
    printf("                      \\ \\\n");
    printf("\n");

    for (i = 0; i < n; i++) {
        if (i % 3 == 0) {
            printf("[92m %d ", num1);
        } else if (i % 5 == 0) {
            printf("[41m %d ", num1);
        } else {
            printf(" %d ", num1);
        }

        next = num1 + num2;
        num1 = num2;
        num2 = next;
    }

    printf("\nWow, wasn't that cool? Thanks for playing with me!\n");

    return 0;
}