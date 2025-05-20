//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main() {
    char input_file[MAX_WORD_LENGTH];
    char output_file[MAX_WORD_LENGTH];
    FILE *input, *output;
    WordTranslation words[MAX_WORDS];
    int num_words = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", input_file);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input);
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, input)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words in input file.\n");
                fclose(input);
                fclose(output);
                exit(1);
            }
            strcpy(words[num_words].word, word);
            printf("Enter the translation for '%s': ", word);
            scanf("%s", words[num_words].translation);
            num_words++;
            word = strtok(NULL, " ");
        }
    }

    fclose(input);
    fclose(output);

    printf("Translating words...\n");
    for (int i = 0; i < num_words; i++) {
        fprintf(output, "%s %s\n", words[i].word, words[i].translation);
    }

    printf("Translation complete.\n");

    return 0;
}