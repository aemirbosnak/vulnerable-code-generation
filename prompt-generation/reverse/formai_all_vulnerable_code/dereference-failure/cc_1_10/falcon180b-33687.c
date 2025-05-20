//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000 // maximum number of words in the dictionary
#define MAX_WORD_LENGTH 50 // maximum length of a word

typedef struct {
    char *english; // English word
    char *alien; // Alien word
} Word;

int main() {
    FILE *dictionary;
    char line[100];
    int num_words = 0;
    Word words[MAX_WORDS];

    // Open the dictionary file
    dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    // Read the words from the dictionary file
    while (fgets(line, sizeof(line), dictionary)!= NULL) {
        char *english = strtok(line, " ");
        char *alien = strtok(NULL, " ");

        if (english == NULL || alien == NULL) {
            printf("Error: invalid line in dictionary file.\n");
            exit(1);
        }

        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary is too large.\n");
            exit(1);
        }

        words[num_words].english = strdup(english);
        words[num_words].alien = strdup(alien);
        num_words++;
    }

    // Close the dictionary file
    fclose(dictionary);

    // Translate the sentence
    char sentence[1000];
    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Split the sentence into words
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                break;
            }
        }
        if (i == num_words) {
            printf("unknown ");
        }
        word = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}