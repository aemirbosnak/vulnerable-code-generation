//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(char* filename, WordCount words[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                break;
            }
        }
    }

    fclose(file);
}

void print_word_counts(WordCount words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    char filename[MAX_WORD_LEN];
    printf("Enter filename: ");
    scanf("%s", filename);

    WordCount words[MAX_WORDS];
    memset(words, 0, sizeof(WordCount) * MAX_WORDS);

    read_file(filename, words);
    print_word_counts(words);

    return 0;
}