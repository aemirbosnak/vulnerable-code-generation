//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Word;

int main() {
    FILE *dictionary;
    char line[100];
    int num_words = 0;
    Word words[MAX_WORDS];

    dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), dictionary)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in dictionary.\n");
            exit(1);
        }
        char *english_word = strtok(line, " ");
        char *alien_word = strtok(NULL, " ");
        if (english_word == NULL || alien_word == NULL) {
            printf("Error: invalid line in dictionary file.\n");
            exit(1);
        }
        strcpy(words[num_words].english, english_word);
        strcpy(words[num_words].alien, alien_word);
        num_words++;
    }

    fclose(dictionary);

    char input_sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(input_sentence, sizeof(input_sentence), stdin);

    char *token = strtok(input_sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                break;
            }
        }
        if (i == num_words) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}