//FormAI DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_SIZE 50
#define MAX_DICTIONARY_SIZE 100

char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_SIZE];
int dictionary_size;

void load_dictionary();
void check_spelling(char *word);
int is_valid_word(char *word);
void print_suggestions(char *word);

int main() {
    load_dictionary();

    char word[MAX_WORD_SIZE];
    printf("Enter a word: ");
    scanf("%s", word);

    check_spelling(word);

    return 0;
}

void load_dictionary() {
    FILE *fp;
    char filename[] = "dictionary.txt";
    char line[MAX_WORD_SIZE];

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error: Failed to open dictionary file.\n");
        return;
    }

    while(fscanf(fp, "%s", line) != EOF && dictionary_size < MAX_DICTIONARY_SIZE) {
        strncpy(dictionary[dictionary_size], line, MAX_WORD_SIZE - 1);
        dictionary[dictionary_size][MAX_WORD_SIZE - 1] = '\0';
        dictionary_size++;
    }

    fclose(fp);

    printf("Dictionary loaded with %d words.\n", dictionary_size);
}

void check_spelling(char *word) {
    if(is_valid_word(word)) {
        printf("%s is a valid word.\n", word);
    } else {
        printf("%s is not a valid word.\n", word);
        printf("Suggestions: ");
        print_suggestions(word);
    }
}

int is_valid_word(char *word) {
    int i;

    for(i = 0; i < dictionary_size; i++) {
        if(strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

void print_suggestions(char *word) {
    int i, j;
    char temp[MAX_WORD_SIZE];
    int len = strlen(word);

    for(i = 0; i < dictionary_size; i++) {
        memcpy(temp, word, len);
        temp[len] = '\0';

        for(j = 0; j < strlen(dictionary[i]); j++) {
            temp[len + j] = dictionary[i][j];
            temp[len + j + 1] = '\0';

            if(is_valid_word(temp)) {
                printf("%s ", temp);
            }
        }
    }

    printf("\n");
}