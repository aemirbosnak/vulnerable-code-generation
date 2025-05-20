//MISTRAL-7B DATASET v1.0 Category: Memory Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LEN 4
#define MAX_LEN 10

void generate_sequence(int *seq, int len);
void print_sequence(int *seq, int len);
int user_input(int *seq, int len);

int main() {
    int seq[MAX_LEN];
    int len, user_guess;

    printf("Welcome to the Memory Game!\n");
    printf("This game will ask you to remember a sequence of numbers.\n");
    printf("You will then be asked to repeat the sequence in the same order.\n");
    printf("Let's begin!\n");

    len = rand() % (MAX_LEN - MIN_LEN + 1) + MIN_LEN;

    generate_sequence(seq, len);
    print_sequence(seq, len);

    do {
        user_guess = user_input(seq, len);
        if (user_guess != seq[0]) {
            printf("Sorry, that's incorrect. Please try again.\n");
            print_sequence(seq, len);
        }
    } while (user_guess != seq[0]);

    printf("Congratulations! You have successfully remembered and repeated the sequence.\n");

    return 0;
}

void generate_sequence(int *seq, int len) {
    int i;

    srand(time(NULL));

    for (i = 0; i < len; i++) {
        seq[i] = rand() % 10 + 1;
    }
}

void print_sequence(int *seq, int len) {
    int i;

    printf("The sequence is: ");

    for (i = 0; i < len; i++) {
        printf("%d ", seq[i]);
    }

    printf("\n");
}

int user_input(int *seq, int len) {
    int i, guess, index = 0;

    for (i = 0; i < len; i++) {
        scanf("%d", &guess);

        if (guess != seq[i]) {
            printf("Invalid input. Please try again.\n");
            i--;
            continue;
        }

        index++;

        if (index == len) {
            return seq[0];
        }

        printf("Next number: ");
        i--;
    }

    return -1;
}