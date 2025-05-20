//Falcon-180B DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
    int row;
    int col;
} Word;

void generate_word(char *word, int length) {
    for (int i = 0; i < length; i++) {
        word[i] = toupper(rand() % 26 + 'A');
    }
    word[length] = '\0';
}

void generate_words(Word *words, int num_words) {
    srand(time(NULL));
    for (int i = 0; i < num_words; i++) {
        generate_word(words[i].word, rand() % 10 + 3);
        words[i].length = strlen(words[i].word);
        words[i].row = rand() % 3;
        words[i].col = rand() % 10;
    }
}

void print_word(const Word *word) {
    for (int i = 0; i < word->length; i++) {
        printf("%c", word->word[i]);
    }
    printf(" ");
}

void print_words(const Word *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        print_word(words + i);
    }
    printf("\n");
}

int main() {
    Word words[MAX_WORDS];
    int num_words;

    printf("Enter the number of words: ");
    scanf("%d", &num_words);

    if (num_words > MAX_WORDS) {
        printf("Too many words!\n");
        return 1;
    }

    generate_words(words, num_words);

    int score = 0;
    int lives = 5;

    while (lives > 0) {
        printf("Guess the words:\n");
        print_words(words, num_words);

        char guess[MAX_WORD_LENGTH];
        printf("Enter your guess: ");
        scanf("%s", guess);

        for (int i = 0; i < num_words; i++) {
            if (strcmp(guess, words[i].word) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect.\n");
            }
        }

        if (score == num_words) {
            printf("You win!\n");
            break;
        } else {
            lives--;
            if (lives == 0) {
                printf("You lose!\n");
                break;
            }
        }
    }

    return 0;
}