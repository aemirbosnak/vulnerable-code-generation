//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQ_LENGTH 5
#define MAX_TRIES 3

typedef enum { WATER, FOOD, MEDICINE, EMPTY } Symbol;

void generate_sequence(Symbol sequence[], int length);
void print_sequence(Symbol sequence[], int length);
int check_sequence(Symbol player_sequence[], Symbol sequence[], int length);
void game_over(int tries);

int main() {
    Symbol player_sequence[SEQ_LENGTH];
    Symbol sequence[SEQ_LENGTH];
    int tries = 0;

    printf("\n*** WELCOME TO THE RADIOACTIVE WASTELAND MEMORY GAME ***\n");
    printf("In this post-apocalyptic world, you are a scavenger.\n");
    printf("Your objective is to memorize and recall sequences of valuable resources.\n");
    printf("Press ENTER to start.\n");
    getchar();

    srand(time(NULL));

    while (tries < MAX_TRIES) {
        generate_sequence(sequence, SEQ_LENGTH);
        print_sequence(sequence, SEQ_LENGTH);

        int i;
        for (i = 0; i < SEQ_LENGTH; i++) {
            player_sequence[i] = EMPTY;
        }

        printf("Now remember the sequence and input it when ready.\n");

        Symbol input;
        for (i = 0; i < SEQ_LENGTH; i++) {
            scanf("%d", &input);

            if (input != sequence[i]) {
                printf("Incorrect. Try again.\n");
                i--;
                break;
            }
        }

        if (check_sequence(player_sequence, sequence, SEQ_LENGTH)) {
            printf("Correct! You have successfully recalled the sequence.\n");
            printf("You have found valuable resources: water, food, and medicine.\n");
            printf("Press ENTER to continue.\n");
            getchar();
            tries++;
        } else {
            printf("Incorrect. You have used all your tries.\n");
            game_over(tries);
        }
    }

    printf("Game Over.\n");
    return 0;
}

void generate_sequence(Symbol sequence[], int length) {
    int i;

    for (i = 0; i < length; i++) {
        sequence[i] = (Symbol)(rand() % 3);
    }
}

void print_sequence(Symbol sequence[], int length) {
    int i;

    printf("The sequence is: ");

    for (i = 0; i < length; i++) {
        switch (sequence[i]) {
            case WATER:
                printf("Water ");
                break;
            case FOOD:
                printf("Food ");
                break;
            case MEDICINE:
                printf("Medicine ");
                break;
            case EMPTY:
                printf("Empty ");
                break;
        }
    }

    printf("\n");
}

int check_sequence(Symbol player_sequence[], Symbol sequence[], int length) {
    int i;

    for (i = 0; i < length; i++) {
        if (player_sequence[i] != sequence[i]) {
            return 0;
        }
    }

    return 1;
}

void game_over(int tries) {
    printf("You have used all your tries.\n");
    printf("You have lost access to the valuable resources.\n");
    printf("Press ENTER to exit.\n");
    getchar();
    exit(EXIT_FAILURE);
}