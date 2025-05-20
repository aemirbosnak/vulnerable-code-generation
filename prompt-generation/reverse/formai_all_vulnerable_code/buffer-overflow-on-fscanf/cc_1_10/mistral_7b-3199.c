//MISTRAL-7B DATASET v1.0 Category: Terminal Based Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_TRIES 3
#define WORD_LENGTH 5

char word[WORD_LENGTH];
char guess[WORD_LENGTH];
char letters_guessed[WORD_LENGTH];
int num_correct_guesses = 0;
int num_incorrect_guesses = 0;
int num_tries_left = MAX_TRIES;
int i;
int j;
int k;

void generate_word() {
    FILE *fp;
    char file_name[20] = "words.txt";
    fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(fp, "%s", word);

    while (feof(fp)) {
        fscanf(fp, "%s", word);
    }

    fclose(fp);
}

void print_word() {
    for (i = 0; i < WORD_LENGTH; i++) {
        printf("%c ", word[i]);
        letters_guessed[i] = word[i];
    }

    printf("\n");
}

void check_guess() {
    for (i = 0; i < WORD_LENGTH; i++) {
        if (guess[i] == word[i]) {
            num_correct_guesses++;
            letters_guessed[i] = guess[i];
        } else {
            num_incorrect_guesses++;
        }
    }
}

void print_status() {
    printf("Correct guesses: ");
    for (i = 0; i < WORD_LENGTH; i++) {
        if (letters_guessed[i] != '_') {
            printf("%c ", letters_guessed[i]);
        } else {
            printf("_ ");
        }
    }

    printf("\n");
    printf("Incorrect guesses: %d\n", num_incorrect_guesses);
    printf("Tries left: %d\n", num_tries_left);
}

int main() {
    int c;
    int correct_guess;

    srand(time(NULL));

    generate_word();

    print_word();

    while (num_correct_guesses < WORD_LENGTH && num_tries_left > 0) {
        printf("Enter your guess: ");
        scanf("%s", guess);

        check_guess();
        print_status();

        if (num_incorrect_guesses > 0) {
            printf("Incorrect guesses: ");
            for (i = 0; i < num_incorrect_guesses; i++) {
                printf("%c ", letters_guessed[i]);
            }

            printf("\n");
        }

        num_incorrect_guesses = 0;

        if (num_correct_guesses < WORD_LENGTH) {
            printf("Sorry, that is not a correct guess. Try again.\n");
            num_tries_left--;
        } else {
            printf("Congratulations! You have guessed the word: %s\n", word);
        }
    }

    if (num_tries_left == 0) {
        printf("Sorry, you have run out of tries. The word was: %s\n", word);
    }

    return 0;
}