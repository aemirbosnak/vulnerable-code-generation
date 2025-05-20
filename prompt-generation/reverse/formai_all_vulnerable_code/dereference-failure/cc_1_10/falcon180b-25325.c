//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void read_words(char *filename, WordFrequency words[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (i = 0; i < MAX_WORDS &&!found; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                found = 1;
            }
        }
        if (!found) {
            if (i < MAX_WORDS) {
                strcpy(words[i].word, word);
                words[i].frequency = 1;
            }
        }
    }

    fclose(file);
}

void print_frequencies(WordFrequency words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char filename[MAX_WORD_LENGTH];
    strcpy(filename, argv[1]);

    WordFrequency words[MAX_WORDS];
    read_words(filename, words);

    printf("Word frequencies:\n");
    print_frequencies(words);

    return 0;
}