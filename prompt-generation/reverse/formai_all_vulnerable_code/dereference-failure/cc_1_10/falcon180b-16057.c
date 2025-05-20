//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} word_translation_t;

word_translation_t dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char* word = strtok(line, " \t\n");
        char* translation = strtok(NULL, " \t\n");

        if (word == NULL || translation == NULL) {
            printf("Error: malformed line in dictionary file.\n");
            exit(1);
        }

        strcpy(dictionary[num_words].word, word);
        strcpy(dictionary[num_words].translation, translation);
        num_words++;
    }

    fclose(fp);
}

int find_word(const char* word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    load_dictionary("dictionary.txt");

    char sentence[MAX_WORD_LENGTH * 10];
    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin);

    char* token = strtok(sentence, " \t\n");
    while (token!= NULL) {
        int word_index = find_word(token);
        if (word_index!= -1) {
            printf("%s -> %s", token, dictionary[word_index].translation);
        } else {
            printf("%s", token);
        }
        printf(" ");
        token = strtok(NULL, " \t\n");
    }

    return 0;
}