//LLAMA2-13B DATASET v1.0 Category: Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 100
#define MAGIC_NUMBER 42

void print_fibonacci(int n) {
    if (n == 0 || n == 1) {
        printf("%d\n", n);
        return;
    }

    int prev = 0, curr = 1, next = 0;

    for (int i = 0; i < n - 2; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }

    printf("%d\n", curr);
}

int main() {
    srand(time(NULL));

    int num_guesses = 10;
    int guess = 0;
    int correct = 0;

    for (int i = 0; i < num_guesses; i++) {
        int random_number = rand() % MAX_LENGTH;

        printf("Guess a number between 0 and %d: ", MAX_LENGTH);
        scanf("%d", &guess);

        if (guess == random_number) {
            correct++;
            printf("Correct! You guessed %d\n", random_number);
        } else {
            printf("Incorrect. The correct answer was %d\n", random_number);
        }
    }

    printf("You guessed %d out of %d correctly\n", correct, num_guesses);

    print_fibonacci(MAGIC_NUMBER);

    return 0;
}