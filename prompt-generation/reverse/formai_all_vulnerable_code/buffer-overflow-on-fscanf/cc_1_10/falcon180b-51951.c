//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000000
#define WORD_LEN 20

typedef struct {
    char word[WORD_LEN];
    int frequency;
} WordFrequency;

void read_words(FILE *file, WordFrequency *words) {
    char buffer[WORD_LEN];
    while (fscanf(file, "%s", buffer)!= EOF) {
        int i;
        for (i = 0; i < strlen(buffer); i++) {
            buffer[i] = tolower(buffer[i]);
        }
        if (strlen(buffer) > 0) {
            WordFrequency *word = (WordFrequency *)malloc(sizeof(WordFrequency));
            strcpy(word->word, buffer);
            word->frequency = 1;
            words[i] = *word;
        }
    }
}

void print_words(WordFrequency *words, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strlen(words[i].word) > 0) {
            printf("%s %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main() {
    FILE *file;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    WordFrequency *words = (WordFrequency *)malloc(MAX_WORDS * sizeof(WordFrequency));
    int num_words = 0;
    read_words(file, words);
    fclose(file);
    printf("Enter number of words to display: ");
    scanf("%d", &num_words);
    print_words(words, num_words);
    free(words);
    return 0;
}