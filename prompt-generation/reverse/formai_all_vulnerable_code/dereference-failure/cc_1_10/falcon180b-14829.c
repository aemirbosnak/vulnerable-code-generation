//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_word(Word *word) {
    int i;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        word->word[i] = (char) ('a' + rand() % 26);
    }
    word->length = rand() % (MAX_WORD_LENGTH + 1);
}

int main() {
    int num_words, i;
    Word *words = malloc(MAX_WORDS * sizeof(Word));
    char input[MAX_WORD_LENGTH];
    srand(time(NULL));

    printf("Welcome to the Hangman game!\n");
    printf("How many words do you want to guess? ");
    scanf("%d", &num_words);

    printf("Enter %d words:\n", num_words);
    for (i = 0; i < num_words; i++) {
        printf("Word %d: ", i + 1);
        scanf("%s", input);
        strcpy(words[i].word, input);
        words[i].length = strlen(input);
    }

    int lives = 5;
    char guessed_word[MAX_WORD_LENGTH];
    memset(guessed_word, '_', words[0].length);

    while (lives > 0) {
        printf("Guessed letters: %s\n", guessed_word);
        printf("Lives remaining: %d\n", lives);
        printf("Current word: ");
        for (i = 0; i < words[0].length; i++) {
            if (guessed_word[i] == words[0].word[i]) {
                printf("%c ", words[0].word[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        char letter;
        printf("Guess a letter: ");
        scanf(" %c", &letter);
        letter = toupper(letter);

        int found = 0;
        for (i = 0; i < words[0].length; i++) {
            if (words[0].word[i] == letter) {
                guessed_word[i] = letter;
                found = 1;
            }
        }

        if (!found) {
            lives--;
        }

        if (lives == 0) {
            printf("You lose! The word was: %s\n", words[0].word);
            break;
        } else if (memcmp(guessed_word, words[0].word, words[0].length) == 0) {
            printf("You win! The word was: %s\n", words[0].word);
            break;
        }

        if (i == num_words - 1) {
            i = 0;
        } else {
            i++;
        }
    }

    free(words);
    return 0;
}