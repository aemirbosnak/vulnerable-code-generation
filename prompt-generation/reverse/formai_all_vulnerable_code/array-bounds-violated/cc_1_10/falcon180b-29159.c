//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE* file, WordCount* word_counts) {
    char line[1024];
    char* word = NULL;
    int len = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        len = strlen(line);
        if (line[len - 1] == '\n') {
            line[--len] = '\0';
        }
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (len >= MAX_WORD_LEN) {
                break;
            }
            strcpy(word_counts->word, word);
            word_counts->count++;
            word_counts++;
            word = strtok(NULL, ",.?!;:");
        }
    }
}

void print_word_counts(WordCount* word_counts) {
    printf("Word\tCount\n");
    for (int i = 0; i < sizeof(word_counts) / sizeof(word_counts[0]); i++) {
        if (word_counts[i].count > 0) {
            printf("%s\t%d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    WordCount word_counts[1000];
    int num_words = 0;

    read_file(file, word_counts);
    fclose(file);

    print_word_counts(word_counts);

    return 0;
}