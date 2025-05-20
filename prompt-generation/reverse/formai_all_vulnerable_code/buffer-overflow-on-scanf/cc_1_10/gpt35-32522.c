//FormAI DATASET v1.0 Category: Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void play_game();
int generate_random_number(int min, int max);
bool is_guess_correct(int guess, int answer);
void print_state(int num_guesses, int guesses[], int answer);

int main() {
    printf("Welcome to the futuristic guessing game!\n");
    printf("You have seven guesses to guess the randomly generated number between 1 and 100.\n");
    printf("Good luck!\n\n");

    play_game();

    return 0;
}

void play_game() {
    const int MIN = 1;
    const int MAX = 100;
    int answer = generate_random_number(MIN, MAX);
    int guesses[7];
    int num_guesses = 0;
    bool correct_guess = false;

    do {
        int guess;
        printf("Guess a number between %d and %d: ", MIN, MAX);
        scanf("%d", &guess);

        if (is_guess_correct(guess, answer)) {
            correct_guess = true;
        } else {
            printf("Incorrect. Try again.\n");
            guesses[num_guesses] = guess;
            num_guesses++;
        }

        print_state(num_guesses, guesses, answer);
    } while(!correct_guess && num_guesses < 7);

    if (correct_guess) {
        printf("Congratulations! You guessed the correct number!\n");
    } else {
        printf("Sorry, you ran out of guesses. The correct number was %d.\n", answer);
    }
}

int generate_random_number(int min, int max) {
    srand(time(NULL));
    int range = max - min + 1;
    return (rand() % range) + min;
}

bool is_guess_correct(int guess, int answer) {
    return guess == answer;
}

void print_state(int num_guesses, int guesses[], int answer) {
    int num_remaining = 7 - num_guesses;
    printf("Number of guesses remaining: %d\n", num_remaining);

    if (num_guesses > 0) {
        printf("Previous guesses: ");
        for (int i = 0; i < num_guesses; i++) {
            printf("%d ", guesses[i]);
        }
        printf("\n");
    }

    if (num_guesses == 7) {
        printf("Sorry, you've used all your guesses. The correct number was %d.\n", answer);
    }
}