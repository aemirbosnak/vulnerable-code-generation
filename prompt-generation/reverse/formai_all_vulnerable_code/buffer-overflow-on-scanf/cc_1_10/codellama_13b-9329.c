//Code Llama-13B DATASET v1.0 Category: Terminal Based Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 6

void print_welcome() {
    printf("Welcome to the Sherlock Holmes Game!\n");
    printf("You are a detective and you have to solve a mystery.\n");
    printf("You have %d guesses to solve the mystery.\n", MAX_GUESSES);
}

void print_hint() {
    printf("Here's a hint: the mystery is related to a famous quote from Sherlock Holmes.\n");
    printf("You can guess the quote or the answer to the mystery.\n");
}

void print_guess_count(int guesses_left) {
    printf("You have %d guesses left.\n", guesses_left);
}

void print_guess_prompt() {
    printf("Enter your guess: ");
}

void print_guess_result(int guesses_left, int correct) {
    if (correct) {
        printf("Congratulations! You have solved the mystery!\n");
    } else {
        printf("Sorry, that is not correct.\n");
    }
}

int main() {
    srand(time(NULL));
    int guesses_left = MAX_GUESSES;
    int correct = 0;

    print_welcome();
    print_hint();

    while (guesses_left > 0) {
        print_guess_count(guesses_left);
        print_guess_prompt();

        char guess[100];
        scanf("%s", guess);

        if (strcmp(guess, "elementary, my dear") == 0) {
            correct = 1;
            break;
        }

        guesses_left--;
    }

    print_guess_result(guesses_left, correct);

    if (correct) {
        printf("You have solved the mystery!\n");
    } else {
        printf("Sorry, you have used all your guesses and have not solved the mystery.\n");
    }

    return 0;
}