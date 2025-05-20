//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 10

typedef struct {
    int user_guess;
    int computer_number;
} TableElement;

int main() {
    int random_number, user_guess, attempts = 0;
    TableElement *table;

    srand(time(NULL));
    random_number = rand() % 100 + 1;

    table = (TableElement *)calloc(TABLE_SIZE, sizeof(TableElement));

    if (table == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have generated a random number between 1 and 100.\n");
    printf("Your task is to guess the number. You have 10 attempts.\n");

    while (attempts < TABLE_SIZE && user_guess != random_number) {
        printf("\nAttempt %d: ", attempts + 1);
        scanf("%d", &user_guess);

        table[attempts].user_guess = user_guess;
        table[attempts].computer_number = rand() % 100 + 1;

        attempts++;

        if (user_guess < random_number) {
            printf("Too low! Try again.\n");
        } else if (user_guess > random_number) {
            printf("Too high! Try again.\n");
        }
    }

    if (user_guess == random_number) {
        printf("\nCongratulations! You have guessed the number correctly in %d attempts.\n", attempts);
    } else {
        printf("\nSorry, you have used all 10 attempts. The number was %d.\n", random_number);
    }

    free(table);

    return 0;
}