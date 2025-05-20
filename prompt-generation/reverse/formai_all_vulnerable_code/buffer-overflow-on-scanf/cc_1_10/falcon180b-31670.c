//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} word_pair;

int main() {
    FILE *input_file;
    FILE *output_file;
    char input_filename[50];
    char output_filename[50];
    char line[100];
    int num_words = 0;
    word_pair *word_list = (word_pair*) malloc(MAX_WORDS * sizeof(word_pair));

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), input_file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words in input file.\n");
                exit(1);
            }
            strcpy(word_list[num_words].word, word);
            printf("Enter the translation for %s: ", word);
            scanf("%s", word_list[num_words].translation);
            num_words++;
            word = strtok(NULL, " ");
        }
    }

    fclose(input_file);
    fclose(output_file);

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "%s %s\n", word_list[i].word, word_list[i].translation);
    }

    fclose(output_file);
    printf("Translation complete.\n");
    return 0;
}