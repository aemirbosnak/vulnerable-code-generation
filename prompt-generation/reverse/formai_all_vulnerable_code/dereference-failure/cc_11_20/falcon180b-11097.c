//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
};

int main() {
    FILE *dictionary;
    char line[MAX_WORD_LENGTH];
    struct word words[MAX_WORDS];
    int num_words = 0;

    dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error opening dictionary file!\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, dictionary)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Dictionary is too large!\n");
            return 2;
        }

        char *token = strtok(line, " ");
        strcpy(words[num_words].english, token);

        token = strtok(NULL, " ");
        strcpy(words[num_words].alien, token);

        num_words++;
    }

    fclose(dictionary);

    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    int i = 0;
    while (i < strlen(input)) {
        char word[MAX_WORD_LENGTH];
        int j = 0;

        while (isspace(input[i]) && i < strlen(input)) {
            i++;
        }

        while (!isspace(input[i]) && i < strlen(input)) {
            word[j++] = input[i++];
        }

        word[j] = '\0';

        for (int k = 0; k < num_words; k++) {
            if (strcmp(word, words[k].english) == 0) {
                printf("%s ", words[k].alien);
                break;
            }
        }

        i++;
    }

    return 0;
}