//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clearScreen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    clearScreen();
    printf("Welcome to Fibonacci Sequence Visualizer!\n\n");

    int n;
    printf("Enter the number of terms of Fibonacci Sequence you want to see: ");
    scanf("%i", &n);

    clearScreen();
    printf("Generating Fibonacci Sequence visual...\n");
    printf("Please wait while we prepare your visual...\n");

    sleep(2); // Pause for 2 seconds for effect

    clearScreen();

    for (int i = 0; i < n; i++) {
        int f = fibonacci(i);
        printf("Fibonacci Term %i : ", i);
        for (int j = 0; j < f; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\nThank you for using Fibonacci Sequence Visualizer!");

    return 0;
}