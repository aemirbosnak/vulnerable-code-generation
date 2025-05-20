//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000 // maximum number of words
#define MAX_WORD_LENGTH 100 // maximum length of a word

typedef struct {
    char word[MAX_WORD_LENGTH]; // the word
    int count; // the frequency count
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* w1 = a;
    const WordFrequency* w2 = b;
    return strcmp(w1->word, w2->word);
}

void readWords(FILE* file, WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            if (i < MAX_WORDS) {
                strcpy(words[i].word, word);
                words[i].count = 1;
            } else {
                printf("Error: maximum number of words (%d) reached\n", MAX_WORDS);
            }
        }
    }
}

void writeWords(FILE* file, WordFrequency words[]) {
    qsort(words, MAX_WORDS, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            fprintf(file, "%s %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }
    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file\n");
        fclose(input_file);
        return 1;
    }
    WordFrequency words[MAX_WORDS];
    readWords(input_file, words);
    fclose(input_file);
    writeWords(output_file, words);
    fclose(output_file);
    return 0;
}