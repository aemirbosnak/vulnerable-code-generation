//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_words(FILE *file, WordCount words[]) {
    char word[MAX_WORD_LENGTH];
    int count = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (count >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }
        strcpy(words[count].word, word);
        words[count].count = 1;
        count++;
    }
}

void search_words(char search_word[], WordCount words[], int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, search_word) == 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *file;
    char filename[20];
    char search_word[20];
    WordCount words[MAX_WORDS];
    int num_words = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    printf("Enter the word to search for: ");
    scanf("%s", search_word);
    read_words(file, words);
    fclose(file);

    search_words(search_word, words, num_words);

    return 0;
}