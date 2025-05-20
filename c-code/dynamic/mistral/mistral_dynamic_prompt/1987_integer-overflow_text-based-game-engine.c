#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 10
#define MAX_GUESSES 3

void print_intro() {
    printf("Welcome to Mystic's Number Game!\n");
    printf("Guess a number between 1 and 100 within 3 attempts.\n");
}

int generate_number() {
    return rand() % 100 + 1;
}

void get_user_input(char* name, int* number) {
    printf("What's your name, adventurer? (Max 10 chars)\n");
    fgets(name, MAX_NAME_LENGTH + 1, stdin);
    *number = strtol(name, NULL, 10);
}

int main() {
    char name[MAX_NAME_LENGTH + 1];
    int secret_number, guess;
    secret_number = generate_number();

    print_intro();
    get_user_input(name, &guess);

    for (int i = 0; i < MAX_GUESSES; ++i) {
        if (guess == secret_number) {
            printf("Congratulations, %s! You've found the number in %d tries!\n", name, i + 1);
            return 0;
        } else {
            printf("Sorry, %s, your guess is incorrect. Try again.\n", name);
            get_user_input(name, &guess);
        }
    }

    printf("Game over, %s. Better luck next time!\n", name);
    return 0;
}
