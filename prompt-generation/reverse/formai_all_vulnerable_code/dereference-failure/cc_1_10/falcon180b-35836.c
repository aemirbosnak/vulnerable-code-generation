//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word_t {
    char *word;
    int count;
};

int main() {
    char input[MAX_WORD_LENGTH];
    char *word;
    struct word_t words[MAX_WORDS];
    int num_words = 0;
    int i;

    printf("Enter a sentence: ");
    fgets(input, MAX_WORD_LENGTH, stdin);

    // Remove newline character
    input[strcspn(input, "\n")] = '\0';

    // Tokenize input
    word = strtok(input, " ");
    while (word!= NULL) {
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == num_words) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many words\n");
                exit(1);
            }
            words[num_words].word = strdup(word);
            words[num_words].count = 1;
            num_words++;
        }
        word = strtok(NULL, " ");
    }

    // Sort words by frequency
    for (i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (words[j].count > words[i].count) {
                struct word_t temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print word counts
    printf("Word counts:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}