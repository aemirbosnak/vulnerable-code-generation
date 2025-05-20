//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_WORD_LENGTH], output_filename[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    int num_words = 0;
    WordTranslation *word_translations = NULL;

    // Get input and output file names from user
    printf("Enter input file name: ");
    scanf("%s", input_filename);
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    // Open input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Read words from input file and store in array
    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words in input file.\n");
                exit(1);
            }
            strcpy(word_translations[num_words].word, word);
            num_words++;
            word = strtok(NULL, " ");
        }
    }

    // Close input file
    fclose(input_file);

    // Translate words to alien language
    for (int i = 0; i < num_words; i++) {
        strcpy(word_translations[i].translation, "GLORP");
    }

    // Open output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    // Write translations to output file
    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "%s %s\n", word_translations[i].word, word_translations[i].translation);
    }

    // Close output file
    fclose(output_file);

    printf("Translation complete!\n");
    return 0;
}