//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(char* filename, WordFrequency words[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int index = -1;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            if (strcmp(word, "")!= 0) {
                strcpy(words[MAX_WORDS - 1].word, word);
                words[MAX_WORDS - 1].frequency = 1;
            }
        } else {
            words[index].frequency++;
        }
    }

    fclose(file);
}

void sortWords(WordFrequency words[]) {
    for (int i = 0; i < MAX_WORDS - 1; i++) {
        for (int j = i + 1; j < MAX_WORDS; j++) {
            if (words[j].frequency > words[i].frequency) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void printWords(WordFrequency words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    WordFrequency words[MAX_WORDS];
    readWords(argv[1], words);
    sortWords(words);
    printWords(words);

    return 0;
}