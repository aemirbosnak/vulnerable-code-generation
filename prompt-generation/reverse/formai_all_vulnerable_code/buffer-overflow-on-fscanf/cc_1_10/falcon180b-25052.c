//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char *english;
    char *alien;
};

int main() {
    FILE *dictionary;
    char line[MAX_WORD_LENGTH];
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
    int num_words = 0;
    struct word words[MAX_WORDS];

    // Open the dictionary file
    dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    // Read the words from the dictionary
    while (fscanf(dictionary, "%s %s\n", english, alien) == 2) {
        words[num_words].english = strdup(english);
        words[num_words].alien = strdup(alien);
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary is too large.\n");
            return 1;
        }
    }
    fclose(dictionary);

    // Translate the input text
    char input_text[MAX_WORD_LENGTH];
    printf("Enter the text to translate:\n");
    fgets(input_text, MAX_WORD_LENGTH, stdin);
    input_text[strcspn(input_text, "\n")] = '\0';

    // Split the input text into words
    char *word = strtok(input_text, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                break;
            }
        }
        if (i == num_words) {
            printf("unknown word: %s\n", word);
        }
        word = strtok(NULL, " ");
    }

    return 0;
}