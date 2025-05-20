//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_random_word(Word *word) {
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int word_length = rand() % MAX_WORD_LENGTH + 1;
    for (int i = 0; i < word_length; i++) {
        word->word[i] = letters[rand() % strlen(letters)];
    }
    word->length = word_length;
}

int main() {
    srand(time(NULL));

    int num_words;
    printf("Enter number of words: ");
    scanf("%d", &num_words);

    Word words[MAX_WORDS];
    for (int i = 0; i < num_words; i++) {
        generate_random_word(&words[i]);
        printf("Word %d: %s\n", i+1, words[i].word);
    }

    int num_correct = 0;
    int num_incorrect = 0;
    int num_skipped = 0;

    for (int i = 0; i < num_words; i++) {
        printf("Word %d: ", i+1);
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);

        if (strcmp(input, words[i].word) == 0) {
            num_correct++;
        } else if (strcmp(input, "")!= 0) {
            num_incorrect++;
        } else {
            num_skipped++;
        }
    }

    printf("Correct: %d\n", num_correct);
    printf("Incorrect: %d\n", num_incorrect);
    printf("Skipped: %d\n", num_skipped);

    return 0;
}