//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#define MAX_INPUT_SIZE 100

void sanitize_input(char *input) {
    int i, j;
    for (i = 0; i < strlen(input); i++) {
        if (isalnum(input[i]) || input[i] == ' ' || input[i] == '\'' || input[i] == '\\' || input[i] == '&' || input[i] == '|' || input[i] == ';') {
            continue;
        } else {
            for (j = i; j < strlen(input); j++) {
                if (isalnum(input[j])) {
                    input[i] = input[j];
                    i--;
                    memmove(&input[j], &input[j + 1], strlen(&input[j + 1]) + 1 - (strlen(&input[j]) + 1));
                    break;
                }
            }
        }
    }
    input[strlen(input)] = '\0';
}

int main() {
    char user_input[MAX_INPUT_SIZE];
    int number_to_guess, guess;
    int flag = 0;

    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

    while (!flag) {
        printf("Enter your guess: ");
        fgets(user_input, MAX_INPUT_SIZE, stdin);

        sanitize_input(user_input);

        sscanf(user_input, "%d", &guess);

        if (guess < 1 || guess > 100) {
            printf("Invalid input! Please enter a number between 1 and 100.\n");
        } else {
            number_to_guess = rand() % 100 + 1;

            if (guess > number_to_guess) {
                printf("Too high! Try again.\n");
            } else if (guess < number_to_guess) {
                printf("Too low! Try again.\n");
            } else {
                printf("Congratulations! You guessed the number correctly.\n");
                flag = 1;
            }
        }
    }

    return 0;
}