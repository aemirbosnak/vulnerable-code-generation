//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCES 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void initialize_word_counts(WordCount counts[]) {
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        counts[i].word[0] = '\0';
        counts[i].count = 0;
    }
}

bool is_valid_word(char* word) {
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }
    return true;
}

void increment_word_count(WordCount counts[], char* word) {
    int index = 0;
    while (index < MAX_WORD_LENGTH && strcmp(counts[index].word, word)!= 0) {
        index++;
    }
    if (index == MAX_WORD_LENGTH) {
        printf("Error: Maximum number of unique words exceeded.\n");
        exit(1);
    }
    counts[index].count++;
}

void print_word_counts(WordCount counts[]) {
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (counts[i].word[0]!= '\0') {
            printf("%s: %d\n", counts[i].word, counts[i].count);
        }
    }
}

int main() {
    char input_file[100];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    FILE* fp = fopen(input_file, "r");
    if (fp == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    WordCount counts[MAX_WORD_LENGTH];
    initialize_word_counts(counts);

    char sentence[1000];
    while (fgets(sentence, sizeof(sentence), fp)!= NULL) {
        char* token = strtok(sentence, ",.?!;:");
        while (token!= NULL) {
            if (is_valid_word(token)) {
                increment_word_count(counts, token);
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(fp);

    print_word_counts(counts);

    return 0;
}