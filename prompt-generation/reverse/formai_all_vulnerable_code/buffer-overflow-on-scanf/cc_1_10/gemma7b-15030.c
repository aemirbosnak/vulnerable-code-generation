//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_GUESSES 5

typedef struct Word {
    char *word;
    int guesses;
    int is_correct;
} Word;

Word words[MAX_WORDS];

void initialize_words() {
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i].word = malloc(20);
        words[i].guesses = MAX_GUESSES;
        words[i].is_correct = 0;
    }
}

void guess_word(Word *word) {
    char guess;

    printf("Guess a letter: ");
    scanf(" %c", &guess);

    word->guesses--;

    if (guess == word->word[0]) {
        word->is_correct = 1;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The letter is: %c\n", word->word[0]);
    }
}

int main() {
    initialize_words();

    srand(time(NULL));
    int random_word_index = rand() % MAX_WORDS;

    Word *word = &words[random_word_index];

    guess_word(word);

    if (word->is_correct) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Sorry, you lost. The answer was: %s\n", word->word);
    }

    return 0;
}