//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: surprised
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void add_word(char *str) {
    if (num_words >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        return;
    }
    strcpy(words[num_words].word, str);
    words[num_words].is_correct = true;
    num_words++;
}

void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        add_word(word);
    }
    fclose(file);
}

bool is_correct(char *str) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(str, words[i].word) == 0) {
            return true;
        }
    }
    return false;
}

void correct_word(char *str) {
    if (!is_correct(str)) {
        printf("Error: %s is not in the dictionary.\n", str);
        exit(1);
    }
}

int main() {
    char filename[100];
    printf("Enter dictionary filename: ");
    scanf("%s", filename);
    load_dictionary(filename);

    char sentence[1000];
    printf("Enter sentence to check: ");
    scanf("%s", sentence);

    char word[MAX_WORD_LENGTH];
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        strcpy(word, token);
        correct_word(word);
        token = strtok(NULL, " ");
    }

    printf("No spelling errors found.\n");
    return 0;
}