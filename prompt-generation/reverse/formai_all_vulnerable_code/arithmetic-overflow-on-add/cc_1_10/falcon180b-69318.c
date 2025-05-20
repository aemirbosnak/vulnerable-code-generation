//Falcon-180B DATASET v1.0 Category: Educational ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct {
    char word[20];
    int count;
} WordCount;

void read_file(FILE* file, WordCount* word_counts) {
    char line[100];
    char word[20];
    int i = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        char* token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);
            int j = 0;
            while (word_counts[j].word[0]!= '\0' && strcmp(word, word_counts[j].word)!= 0) {
                j++;
            }
            if (word_counts[j].word[0] == '\0') {
                for (int k = 0; k < i; k++) {
                    strcpy(word_counts[k + 1].word, word_counts[k].word);
                    word_counts[k + 1].count = word_counts[k].count;
                }
                strcpy(word_counts[0].word, word);
                word_counts[0].count = 1;
                i++;
            } else {
                word_counts[j].count++;
            }
            token = strtok(NULL, " ");
        }
    }
}

void print_word_counts(WordCount* word_counts) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_counts[i].word[0]!= '\0') {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }
    WordCount word_counts[MAX_WORDS];
    read_file(file, word_counts);
    print_word_counts(word_counts);
    fclose(file);
    return 0;
}