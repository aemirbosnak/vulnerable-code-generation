//MISTRAL-7B DATASET v1.0 Category: Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUMBER 1
#define MAX_NUMBER 10

void input_number(int* number) {
    int input;

    while (scanf("%d", &input) != 1 || (input < MIN_NUMBER || input > MAX_NUMBER)) {
        printf("Invalid input. Please enter a number between %d and %d: ", MIN_NUMBER, MAX_NUMBER);
        rewind(stdin);
    }

    *number = input;
}

int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int game_logic(int user_number, int computer_number) {
    if (user_number > computer_number) {
        return 1;
    } else if (user_number < computer_number) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));
    int user_number, computer_number, result;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I will generate a random number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
    printf("Your goal is to guess the number I generated.\n");

    computer_number = random_number(MIN_NUMBER, MAX_NUMBER);

    do {
        input_number(&user_number);
        printf("You entered: %d\n", user_number);

        result = game_logic(user_number, computer_number);

        if (result == 1) {
            printf("Congratulations! You guessed the number correctly.\n");
        } else {
            printf("Sorry, your guess is incorrect. Try again.\n");
        }

    } while (result != 0);

    return 0;
}