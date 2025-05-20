//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50

typedef struct Word {
    char name[WORD_LENGTH];
    int count;
} Word;

void incrementWordCount(Word words[], char word[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].name, word) == 0) {
            words[i].count++;
            return;
        }
    }

    strcpy(words[MAX_WORDS - 1].name, word);
    words[MAX_WORDS - 1].count = 1;
}

int main() {
    Word myWords[MAX_WORDS];
    char line[256], word[WORD_LENGTH];
    int lineLength, i;

    printf("In the land of Codeland, where words are but treasure,\n");
    printf("I, thy faithful scribe, shall count the frequency rare.\n");

    while (fgets(line, sizeof(line), stdin) != NULL) {
        lineLength = strlen(line);
        for (i = 0; i < lineLength; i++) {
            if (line[i] == ' ') {
                if (i > 0) {
                    word[i - 1] = '\0';
                    incrementWordCount(myWords, word);
                }
                strcpy(word, &line[i + 1]);
                i += strlen(word) - 1;
            }
        }
        if (i > 0) {
            word[i - 1] = '\0';
            incrementWordCount(myWords, word);
        }
    }

    printf("\nIn the vast library of Codeland,\n");
    printf("These are the words, by frequency, they're ranked:\n");

    for (int j = 0; j < MAX_WORDS; j++) {
        if (myWords[j].count > 0) {
            printf("%s: %d\n", myWords[j].name, myWords[j].count);
        }
    }

    return 0;
}