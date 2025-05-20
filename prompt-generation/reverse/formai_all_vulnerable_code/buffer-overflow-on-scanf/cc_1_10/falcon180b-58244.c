//Falcon-180B DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void read_file(char *filename, char *text) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            text[strlen(text) - 1] = '\0'; // remove trailing space
        } else {
            strcat(text, &ch);
        }
    }

    fclose(file);
}

void count_words(char *text, Word words[MAX_WORDS]) {
    char *token = strtok(text, ",.?!;:");
    int i = 0;

    while (token!= NULL) {
        if (i >= MAX_WORDS) {
            printf("Error: too many words in the text\n");
            exit(1);
        }

        strcpy(words[i].word, token);
        words[i].count = 1;

        token = strtok(NULL, ",.?!;:");
        i++;
    }
}

void print_frequencies(Word words[MAX_WORDS], int num_words) {
    printf("Word frequencies:\n");

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    char text[1000000];
    read_file(filename, text);

    Word words[MAX_WORDS];
    count_words(text, words);

    int num_words = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            num_words++;
        }
    }

    print_frequencies(words, num_words);

    return 0;
}