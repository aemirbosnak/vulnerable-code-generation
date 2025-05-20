//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000

int main() {
    int numbers[MAX_NUMBERS];
    int count = 0;
    int i;
    int input;

    srand(time(NULL));
    printf("Welcome to the Fibonacci Sequence Visualizer!\n\n");

    for (i = 0; i < MAX_NUMBERS; i++) {
        printf("Enter a number (0 to stop): ");
        scanf("%d", &input);

        if (input == 0) {
            break;
        }

        if (count >= MAX_NUMBERS) {
            printf("Sorry, you've reached the maximum number of inputs.\n");
            break;
        }

        numbers[count++] = input;
    }

    printf("\nYour input numbers are:\n");
    for (i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");

    printf("The Fibonacci sequence up to %d is:\n", numbers[count - 1]);

    for (i = 0; i <= numbers[count - 1]; i++) {
        if (i == 0 || i == 1) {
            printf("%d ", i);
        } else {
            printf("%d ", fibonacci(i));
        }
    }

    return 0;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}