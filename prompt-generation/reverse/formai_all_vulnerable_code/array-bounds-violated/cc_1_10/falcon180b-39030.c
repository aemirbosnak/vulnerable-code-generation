//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

struct word_t {
    char *english;
    char *alien;
};

int main() {
    FILE *dict_file;
    struct word_t words[MAX_WORDS];
    int num_words = 0;
    char line[MAX_WORD_LEN];
    char *token;

    // Open dictionary file
    dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    // Read words from file
    while (fgets(line, MAX_WORD_LEN, dict_file)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary is too large.\n");
            return 1;
        }

        // Remove newline character
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        // Split line into English and alien words
        token = strtok(line, " ");
        words[num_words].english = strdup(token);
        token = strtok(NULL, " ");
        words[num_words].alien = strdup(token);

        num_words++;
    }

    // Close dictionary file
    fclose(dict_file);

    // Translate sentence
    char sentence[MAX_WORD_LEN];
    printf("Enter a sentence to translate: ");
    fgets(sentence, MAX_WORD_LEN, stdin);

    // Split sentence into words
    char *sentence_token = strtok(sentence, " ");
    while (sentence_token!= NULL) {
        // Convert word to lowercase
        char *lowercase_word = malloc(strlen(sentence_token) + 1);
        strcpy(lowercase_word, sentence_token);
        for (int i = 0; i < strlen(lowercase_word); i++) {
            lowercase_word[i] = tolower(lowercase_word[i]);
        }

        // Search for word in dictionary
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(lowercase_word, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("unknown ");
        }

        sentence_token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}