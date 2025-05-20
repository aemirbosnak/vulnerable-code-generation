//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000 // maximum number of words
#define MAX_WORD_LENGTH 50 // maximum length of a word

typedef struct {
    char *english; // English word
    char *cat; // Cat word
} Word;

Word dictionary[MAX_WORDS]; // dictionary of English-Cat word pairs
int num_words = 0; // number of words in the dictionary

void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, MAX_WORD_LENGTH + 1, file)!= NULL) {
        char *english_word = strtok(line, " \t\n\r");
        char *cat_word = strtok(NULL, " \t\n\r");

        if (english_word == NULL || cat_word == NULL) {
            printf("Error: invalid dictionary entry.\n");
            exit(1);
        }

        dictionary[num_words].english = strdup(english_word);
        dictionary[num_words].cat = strdup(cat_word);
        num_words++;
    }

    fclose(file);
}

void translate_sentence(char *sentence) {
    char *token = strtok(sentence, " \t\n\r");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                printf("%s ", dictionary[i].cat);
                break;
            }
        }

        if (i == num_words) {
            printf("unknown word: %s\n", token);
        }

        token = strtok(NULL, " \t\n\r");
    }
    printf("\n");
}

int main() {
    load_dictionary("dictionary.txt");

    char sentence[MAX_WORD_LENGTH * 10]; // maximum sentence length of 10 words
    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_WORD_LENGTH * 10, stdin);

    translate_sentence(sentence);

    return 0;
}