//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 10

typedef struct {
    int number;
    int guessed;
} cell;

void print_table(cell table[TABLE_SIZE]) {
    int i;
    printf("+-----+-----+\n");
    printf("| Number| Guessed |\n");
    printf("+-----+-----+\n");
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("| %2d   | %-8d |\n", table[i].number, table[i].guessed);
        printf("+-----+-----+\n");
    }
}

int random_number() {
    return rand() % 100 + 1;
}

void set_number(cell *cell_ptr) {
    cell_ptr->number = random_number();
}

void guess_number(cell *cell_ptr, int user_guess) {
    cell_ptr->guessed = user_guess;
}

int main() {
    srand(time(NULL));

    cell table[TABLE_SIZE];
    int i, user_guess;

    for (i = 0; i < TABLE_SIZE; i++) {
        set_number(&table[i]);
    }

    print_table(table);

    for (i = 0; i < TABLE_SIZE; i++) {
        printf("\nPlayer %d turn, enter your guess: ", i + 1);
        scanf("%d", &user_guess);

        guess_number(&table[i], user_guess);
        print_table(table);

        if (table[i].number == table[i].guessed) {
            printf("Congratulations! You guessed the number correctly.\n");
            break;
        } else if (i == TABLE_SIZE - 1) {
            printf("Sorry, you have run out of turns. The number was %d.\n", table[i].number);
        }
    }

    return 0;
}