//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define SPAM_THRESHOLD 0.5

typedef struct {
    char *word;
    double frequency;
} WordFrequency;

void loadWords(FILE *file, WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (int j = 0; j < MAX_WORDS; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            if (strlen(word) > MAX_WORD_LENGTH) {
                printf("Error: Word '%s' is too long.\n", word);
            } else {
                strncpy(words[MAX_WORDS - 1].word, word, MAX_WORD_LENGTH);
                words[MAX_WORDS - 1].frequency = 1;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <spam_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    loadWords(file, words);

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %.2f\n", words[i].word, words[i].frequency / words[0].frequency);
        }
    }

    fclose(file);
    return 0;
}