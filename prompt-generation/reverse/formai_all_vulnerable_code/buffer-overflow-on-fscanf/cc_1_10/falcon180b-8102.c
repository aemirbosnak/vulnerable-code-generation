//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char *english;
    char *alien;
};

int main() {
    struct word dictionary[MAX_WORDS];
    int num_words = 0;
    char input_word[MAX_WORD_LENGTH];
    char output_word[MAX_WORD_LENGTH];
    FILE *dictionary_file;

    // Open dictionary file
    dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    // Read dictionary words from file
    while (fscanf(dictionary_file, "%s %s", dictionary[num_words].english, dictionary[num_words].alien)!= EOF) {
        num_words++;
    }
    fclose(dictionary_file);

    // Prompt user for input word
    printf("Enter an English word to translate to Alien:\n");
    scanf("%s", input_word);

    // Convert input word to lowercase
    for (int i = 0; i < strlen(input_word); i++) {
        input_word[i] = tolower(input_word[i]);
    }

    // Search dictionary for input word
    int found_word = 0;
    for (int i = 0; i < num_words; i++) {
        if (strcmp(input_word, dictionary[i].english) == 0) {
            strcpy(output_word, dictionary[i].alien);
            found_word = 1;
            break;
        }
    }

    // Output translation result
    if (found_word) {
        printf("Translation: %s\n", output_word);
    } else {
        printf("Word not found in dictionary.\n");
    }

    return 0;
}