//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARRAY_SIZE 5
#define MAX_ATTEMPTS 3
#define MAX_DIGITS 5

void welcome_message() {
    printf("****************************************\n");
    printf("          WELCOME TO LUCKY GUESS!      \n");
    printf("****************************************\n");
    printf("Can you guess the lucky number? You have %d attempts!\n", MAX_ATTEMPTS);
    printf("The lucky number is a %d-digit number formed randomly.\n", MAX_DIGITS);
    printf("****************************************\n\n");
}

void generate_lucky_number(char lucky_number[]) {
    for (int i = 0; i < MAX_DIGITS; i++) {
        lucky_number[i] = '0' + (rand() % 10);
    }
    lucky_number[MAX_DIGITS] = '\0'; // Null-terminate the string
}

int get_user_input(char guess[]) {
    printf("Enter your guess (%d digits): ", MAX_DIGITS);
    scanf("%s", guess);

    if (strlen(guess) != MAX_DIGITS) {
        printf("Invalid input! Please enter exactly %d digits.\n", MAX_DIGITS);
        return 0;
    }
    return 1;
}

int compare_guess(const char lucky_number[], const char guess[]) {
    int matches = 0;

    for (int i = 0; i < MAX_DIGITS; i++) {
        if (lucky_number[i] == guess[i]) {
            matches++;
        }
    }

    return matches;
}

void play_game() {
    char lucky_number[MAX_DIGITS + 1];
    char user_guess[MAX_DIGITS + 1];
    int attempts = 0;
    int correct_matches = 0;

    generate_lucky_number(lucky_number);

    while (attempts < MAX_ATTEMPTS) {
        if (!get_user_input(user_guess)) {
            continue; // Repeat the input step if invalid
        }

        correct_matches = compare_guess(lucky_number, user_guess);

        if (correct_matches == MAX_DIGITS) {
            printf("Congratulations! You guessed the lucky number: %s\n", lucky_number);
            return; // Exit the game on winning
        } else {
            printf("You have %d correct digit(s).\n", correct_matches);
        }

        attempts++;
        printf("You have %d attempts left.\n\n", MAX_ATTEMPTS - attempts);
    }

    printf("Sorry! You've used all your attempts. The lucky number was: %s\n", lucky_number);
}

int main() {
    srand(time(0)); // Seed the random number generator

    welcome_message();
    play_game();

    printf("\nThank you for playing Lucky Guess! Goodbye!\n");
    return 0;
}