//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare_strings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void read_words(FILE *file, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (i = 0; i < MAX_WORDS &&!found; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                found = 1;
            }
        }
        if (!found) {
            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;
            if (i >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }
        }
    }
}

void print_word_counts(WordCount words[]) {
    qsort(words, MAX_WORDS, sizeof(WordCount), compare_strings);
    printf("Word\t\tCount\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s\t\t%d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    WordCount words[MAX_WORDS];
    read_words(input_file, words);
    print_word_counts(words);
    fclose(input_file);
    fclose(output_file);
    return 0;
}