//Falcon-180B DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words = 0;

void read_file(FILE *file) {
    char ch;
    int word_length = 0;
    char *word = malloc(MAX_WORD_LENGTH * sizeof(char));

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[word_length] = tolower(ch);
            word_length++;
            word = realloc(word, MAX_WORD_LENGTH * sizeof(char));
        }
        else if (word_length > 0) {
            strcpy(words[num_words], word);
            num_words++;
            word_length = 0;
            word = malloc(MAX_WORD_LENGTH * sizeof(char));
        }
    }

    if (word_length > 0) {
        strcpy(words[num_words], word);
        num_words++;
    }

    free(word);
}

void process_words() {
    int i, j;

    for (i = 0; i < num_words; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                strcpy(words[j], "");
            }
        }
    }
}

void print_words() {
    int i;

    for (i = 0; i < num_words; i++) {
        if (strcmp(words[i], "")!= 0) {
            printf("%s ", words[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_file(file);
    fclose(file);

    process_words();
    print_words();

    return 0;
}