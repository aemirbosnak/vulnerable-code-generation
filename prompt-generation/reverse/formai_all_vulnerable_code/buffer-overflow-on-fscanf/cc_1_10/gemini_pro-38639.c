//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_SIZE 5000

// Alien language dictionary
char dict_alien[MAX_DICT_SIZE][MAX_WORD_LEN];
char dict_english[MAX_DICT_SIZE][MAX_WORD_LEN];
int dict_size = 0;

// Function to load the alien language dictionary from a file
void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    while (fscanf(fp, "%s %s", dict_alien[dict_size], dict_english[dict_size]) != EOF) {
        dict_size++;
    }

    fclose(fp);
}

// Function to translate a word from alien language to English
char *translate_word(char *word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dict_alien[i], word) == 0) {
            return dict_english[i];
        }
    }

    return "Unknown word";
}

// Function to translate a sentence from alien language to English
char *translate_sentence(char *sentence) {
    char *translated_sentence = malloc(strlen(sentence) * MAX_WORD_LEN);
    char *word = strtok(sentence, " ");

    while (word != NULL) {
        strcat(translated_sentence, translate_word(word));
        strcat(translated_sentence, " ");
        word = strtok(NULL, " ");
    }

    return translated_sentence;
}

int main() {
    // Load the alien language dictionary
    load_dictionary("dictionary.txt");

    // Get the sentence to be translated from the user
    char sentence[1000];
    printf("Enter a sentence in alien language: ");
    gets(sentence);

    // Translate the sentence and print the result
    char *translated_sentence = translate_sentence(sentence);
    printf("Translated sentence in English: %s\n", translated_sentence);

    return 0;
}