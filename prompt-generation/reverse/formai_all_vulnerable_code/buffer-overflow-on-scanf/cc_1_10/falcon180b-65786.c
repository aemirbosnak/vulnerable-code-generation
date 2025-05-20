//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

char *words[MAX_WORDS];
int num_words = 0;

void read_file(FILE *file) {
    char ch;
    int in_word = 0;
    char word[MAX_WORD_LENGTH];
    int word_length = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            in_word = 1;
            word[word_length++] = tolower(ch);
        } else if (in_word) {
            in_word = 0;
            words[num_words++] = strdup(word);
            word_length = 0;
        }
    }

    if (in_word) {
        words[num_words++] = strdup(word);
    }
}

void count_words(char *word) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i]) == 0) {
            printf("%s: %d\n", word, i+1);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[MAX_WORD_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(file);

    fclose(file);

    printf("Enter word to count: ");
    scanf("%s", filename);

    count_words(filename);

    return 0;
}