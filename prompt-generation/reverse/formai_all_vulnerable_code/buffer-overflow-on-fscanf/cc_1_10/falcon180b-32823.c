//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20
#define TRAINING_SET_SIZE 5000
#define THRESHOLD 0.5

typedef struct {
    char word[MAX_WORD_LENGTH];
    int is_spam;
} Word;

void load_training_set(Word *training_set) {
    FILE *file = fopen("training_set.txt", "r");
    if (file == NULL) {
        printf("Error: could not open training set file.\n");
        exit(1);
    }

    int count = 0;
    while (count < TRAINING_SET_SIZE && fscanf(file, "%s %d", training_set[count].word, &training_set[count].is_spam) == 2) {
        count++;
    }

    fclose(file);
}

int is_spam(char *message, Word *training_set) {
    int num_spam_words = 0;
    int num_words = 0;
    char *word = strtok(message, " ");
    while (word!= NULL) {
        num_words++;

        Word *match = NULL;
        for (int i = 0; i < TRAINING_SET_SIZE; i++) {
            if (strcmp(training_set[i].word, word) == 0) {
                match = &training_set[i];
                break;
            }
        }

        if (match!= NULL && match->is_spam) {
            num_spam_words++;
        }

        word = strtok(NULL, " ");
    }

    if (num_words == 0) {
        return 0;
    }

    double spam_ratio = (double)num_spam_words / num_words;
    return spam_ratio >= THRESHOLD;
}

int main() {
    Word training_set[TRAINING_SET_SIZE];
    load_training_set(training_set);

    char message[1000];
    while (fgets(message, sizeof(message), stdin)!= NULL) {
        if (is_spam(message, training_set)) {
            printf("Spam\n");
        } else {
            printf("Not spam\n");
        }
    }

    return 0;
}