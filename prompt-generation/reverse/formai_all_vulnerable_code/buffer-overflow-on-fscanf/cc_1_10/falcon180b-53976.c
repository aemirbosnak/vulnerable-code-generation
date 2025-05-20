//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct Word {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

struct WordIndex {
    char word[MAX_WORD_LENGTH];
    int index;
};

void readWords(FILE* file, struct Word* words) {
    int numWords = 0;
    while (fscanf(file, "%s", words[numWords].word) == 1) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            break;
        }
    }
    printf("Read %d words\n", numWords);
}

void countWords(struct Word* words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        words[i].frequency = 0;
    }
    FILE* file = fopen("text.txt", "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        for (int i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                break;
            }
        }
    }
    fclose(file);
}

void sortWords(struct Word* words, int numWords) {
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (words[j].frequency > words[i].frequency) {
                struct Word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void writeIndex(FILE* file, struct Word* words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        fprintf(file, "%s\n", words[i].word);
    }
}

int main() {
    struct Word words[MAX_WORDS];
    int numWords;
    readWords("text.txt", words);
    countWords(words, numWords);
    sortWords(words, numWords);
    writeIndex("index.txt", words, numWords);
    return 0;
}