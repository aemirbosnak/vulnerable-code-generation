//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define WORD_LENGTH 5
#define MAX_ATTEMPTS 3
#define DELAY 200000

typedef struct {
    char word[WORD_LENGTH + 1];
    int length;
} Word;

void generate_words(Word words[], int num_words) {
    FILE *dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    for (int i = 0; i < num_words; i++) {
        fscanf(dict, "%s", words[i].word);
        words[i].length = strlen(words[i].word);
    }

    fclose(dict);
}

void shuffle_words(Word words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        int j = rand() % num_words;
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }
}

int main() {
    Word words[MAX_WORDS];
    int num_words = 0;

    printf("Loading dictionary...\n");
    generate_words(words, MAX_WORDS);
    printf("Shuffling words...\n");
    shuffle_words(words, num_words);

    int score = 0;
    int attempts = 0;

    for (int i = 0; i < num_words; i++) {
        printf("Word %d: ", i + 1);
        for (int j = 0; j < WORD_LENGTH; j++) {
            printf("_");
        }
        printf("\n");

        char input[WORD_LENGTH + 1];
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, words[i].word) == 0) {
            score++;
        } else {
            printf("Incorrect.\n");
        }

        attempts++;
        if (attempts >= MAX_ATTEMPTS) {
            break;
        }

        usleep(DELAY);
    }

    printf("Your final score is: %d/%d\n", score, num_words);

    return 0;
}