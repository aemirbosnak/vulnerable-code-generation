//Falcon-180B DATASET v1.0 Category: Error handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 3
#define DELAY_MS 1000

// Function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to prompt the user for input and validate it
int get_input(const char* prompt) {
    int input;
    printf("%s", prompt);
    if (scanf("%d", &input)!= 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        exit(1);
    }
    return input;
}

int main() {
    srand(time(NULL));

    int secret_number = rand_int(1, 100);
    int num_tries = 0;

    while (num_tries < MAX_TRIES) {
        int guess = get_input("Guess the number (1-100): ");

        if (guess == secret_number) {
            printf("Congratulations! You guessed the number in %d tries.\n", num_tries + 1);
            break;
        } else if (guess < secret_number) {
            printf("Too low. Try again.\n");
        } else {
            printf("Too high. Try again.\n");
        }

        num_tries++;
        usleep(DELAY_MS * 1000); // Delay for a second
    }

    if (num_tries == MAX_TRIES) {
        printf("Sorry, you ran out of tries. The number was %d.\n", secret_number);
    }

    return 0;
}