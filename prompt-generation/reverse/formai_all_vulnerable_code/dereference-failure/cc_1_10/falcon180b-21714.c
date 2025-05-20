//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    int num_words = 0;
    WordPair *word_pairs = malloc(MAX_WORDS * sizeof(WordPair));
    if (word_pairs == NULL) {
        printf("Error allocating memory.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words.\n");
                fclose(input_file);
                fclose(output_file);
                free(word_pairs);
                return 1;
            }

            strcpy(word_pairs[num_words].word, word);
            word_pairs[num_words].translation[0] = '\0';

            num_words++;
            word_pairs = realloc(word_pairs, num_words * sizeof(WordPair));

            word = strtok(NULL, " ");
        }
    }

    fclose(input_file);
    fclose(output_file);

    for (int i = 0; i < num_words; i++) {
        char *word = word_pairs[i].word;
        char *translation = word_pairs[i].translation;

        if (translation[0] == '\0') {
            printf("English: %s\n", word);
            printf("Cat: %s\n\n", word);
        } else {
            printf("English: %s\n", word);
            printf("Cat: %s\n\n", translation);
        }
    }

    free(word_pairs);
    return 0;
}