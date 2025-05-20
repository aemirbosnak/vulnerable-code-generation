//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_dictionary(Word dictionary[MAX_WORDS]) {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error loading dictionary.\n");
        exit(1);
    }

    int word_count = 0;
    while (fscanf(fp, "%s", dictionary[word_count].word)!= EOF) {
        dictionary[word_count].is_correct = true;
        word_count++;
    }

    fclose(fp);
}

bool is_correct_word(Word dictionary[MAX_WORDS], char word[MAX_WORD_LENGTH]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return dictionary[i].is_correct;
        }
    }

    return false;
}

int main() {
    Word dictionary[MAX_WORDS];
    load_dictionary(dictionary);

    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    char word[MAX_WORD_LENGTH];
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        strcpy(word, token);
        if (!is_correct_word(dictionary, word)) {
            printf("%s may be spelled incorrectly.\n", word);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}