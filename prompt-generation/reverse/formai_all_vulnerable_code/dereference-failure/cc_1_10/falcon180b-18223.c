//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

// structure to hold each word and its translation
typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Word;

int main() {
    FILE *dictionary;
    char line[MAX_WORD_LENGTH];
    int num_words = 0;
    Word words[MAX_WORDS];

    // open the dictionary file
    dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    // read in each line of the dictionary file
    while (fgets(line, MAX_WORD_LENGTH, dictionary)!= NULL) {
        // split the line into two words (English and alien)
        char *token = strtok(line, " ");
        if (token == NULL) {
            printf("Error: invalid line in dictionary file.\n");
            exit(1);
        }
        strcpy(words[num_words].english, token);
        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("Error: invalid line in dictionary file.\n");
            exit(1);
        }
        strcpy(words[num_words].alien, token);
        num_words++;
    }

    // close the dictionary file
    fclose(dictionary);

    // prompt the user for a sentence to translate
    printf("Enter a sentence to translate: ");
    fgets(line, MAX_WORD_LENGTH, stdin);

    // tokenize the sentence into words
    char *token = strtok(line, " ");
    while (token!= NULL) {
        // search the dictionary for each word
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                // found a match, print the alien translation
                printf("%s ", words[i].alien);
                break;
            }
        }
        // if no match was found, print the original word
        if (i == num_words) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}