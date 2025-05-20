//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
};

int main() {
    FILE *input_file, *output_file;
    char line[100];
    char english_word[MAX_WORD_LENGTH], alien_word[MAX_WORD_LENGTH];
    struct word words[MAX_WORDS];
    int num_words = 0;

    // Open input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read in English words and their alien translations
    while (fgets(line, 100, input_file)!= NULL) {
        sscanf(line, "%s %s", english_word, alien_word);
        strcpy(words[num_words].english, english_word);
        strcpy(words[num_words].alien, alien_word);
        num_words++;
    }

    // Sort words alphabetically by English translation
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].english, words[j].english) > 0) {
                struct word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Open output file
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    // Write sorted words to output file
    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "%s %s\n", words[i].english, words[i].alien);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Translation complete!\n");

    return 0;
}