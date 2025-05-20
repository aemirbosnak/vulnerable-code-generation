//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(dictionary[num_words].word, word);
        dictionary[num_words].is_correct = true;
        num_words++;
    }

    fclose(fp);
}

void add_word(char* word) {
    strcpy(dictionary[num_words].word, word);
    dictionary[num_words].is_correct = true;
    num_words++;
}

bool is_correct_word(char* word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return dictionary[i].is_correct;
        }
    }
    return false;
}

void print_suggestions(char* word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            printf("%s\n", dictionary[i].word);
            break;
        } else if (i == num_words - 1) {
            printf("No suggestions found.\n");
        }
    }
}

int main() {
    load_dictionary("dictionary.txt");

    char sentence[1000];
    printf("Enter a sentence to check:\n");
    fgets(sentence, sizeof(sentence), stdin);

    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        if (!isalpha(word[0])) {
            printf("%s\n", word);
            word = strtok(NULL, " ");
            continue;
        }

        if (is_correct_word(word)) {
            printf("%s\n", word);
        } else {
            print_suggestions(word);
        }

        word = strtok(NULL, " ");
    }

    return 0;
}