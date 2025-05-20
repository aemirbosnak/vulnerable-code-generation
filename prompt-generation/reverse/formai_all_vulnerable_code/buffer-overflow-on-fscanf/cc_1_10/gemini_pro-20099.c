//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 1000

typedef struct {
    char alien_word[MAX_WORD_LENGTH];
    char earth_word[MAX_WORD_LENGTH];
} dictionary_entry;

dictionary_entry dictionary[MAX_DICTIONARY_SIZE];
int dictionary_size = 0;

void load_dictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%s %s", dictionary[dictionary_size].alien_word, dictionary[dictionary_size].earth_word) != EOF) {
        dictionary_size++;
    }

    fclose(fp);
}

char *translate_word(char *alien_word) {
    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(alien_word, dictionary[i].alien_word) == 0) {
            return dictionary[i].earth_word;
        }
    }

    return NULL;
}

char *translate_sentence(char *alien_sentence) {
    char *earth_sentence = malloc(strlen(alien_sentence) + 1);
    if (earth_sentence == NULL) {
        perror("Error allocating memory for earth sentence");
        exit(EXIT_FAILURE);
    }

    char *alien_word = strtok(alien_sentence, " ");
    while (alien_word != NULL) {
        char *earth_word = translate_word(alien_word);
        if (earth_word == NULL) {
            earth_word = alien_word;
        }

        strcat(earth_sentence, earth_word);
        strcat(earth_sentence, " ");

        alien_word = strtok(NULL, " ");
    }

    earth_sentence[strlen(earth_sentence) - 1] = '\0';

    return earth_sentence;
}

int main() {
    load_dictionary();

    char alien_sentence[] = "Hola mundo";
    char *earth_sentence = translate_sentence(alien_sentence);

    printf("%s\n", earth_sentence);

    free(earth_sentence);

    return 0;
}