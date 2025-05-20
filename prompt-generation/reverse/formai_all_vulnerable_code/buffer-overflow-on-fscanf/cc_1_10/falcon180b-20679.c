//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MIN_WORD_LENGTH 3
#define MAX_TRIES 3
#define DELAY 100000

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;
int tries_left;
int score;

void init_words() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) >= MIN_WORD_LENGTH && strlen(word) <= MAX_WORD_LENGTH) {
            strcpy(words[num_words], word);
            num_words++;
        }
    }

    fclose(file);
}

void shuffle_words() {
    for (int i = 0; i < num_words; i++) {
        int j = rand() % num_words;
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }
}

void display_word(int index) {
    int len = strlen(words[index]);
    for (int i = 0; i < len; i++) {
        printf("%c", toupper(words[index][i]));
    }
    printf(" ");
}

bool check_input(char input[MAX_WORD_LENGTH]) {
    int len = strlen(input);
    if (len < MIN_WORD_LENGTH || len > MAX_WORD_LENGTH) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        if (!isalpha(input[i])) {
            return false;
        }
    }

    return true;
}

void game_over() {
    printf("\n");
    printf("Game Over!\n");
    printf("Your final score is: %d\n", score);
}

int main() {
    srand(time(NULL));

    init_words();
    shuffle_words();

    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will have %d tries to type each word correctly.\n", MAX_TRIES);
    printf("Press enter to begin...\n");
    getchar();

    for (int i = 0; i < num_words; i++) {
        printf("\nWord %d:\n", i + 1);
        display_word(i);
        fflush(stdout);

        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (check_input(input)) {
            if (strcmp(input, words[i]) == 0) {
                printf("\nCorrect!\n");
                score++;
            } else {
                printf("\nIncorrect.\n");
            }
        } else {
            printf("\nInvalid input.\n");
        }

        usleep(DELAY);
    }

    game_over();

    return 0;
}