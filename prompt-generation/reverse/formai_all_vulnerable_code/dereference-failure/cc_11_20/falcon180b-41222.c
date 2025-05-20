//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} Word;

int main() {
    FILE *input_file, *output_file;
    char line[MAX_WORD_LEN];
    char *word;
    int num_words = 0;
    Word *dictionary = (Word*)malloc(MAX_WORDS * sizeof(Word));

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open output file\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, input_file)!= NULL) {
        char *p = strtok(line, " ");
        while (p!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: dictionary is full\n");
                exit(1);
            }
            strcpy(dictionary[num_words].word, p);
            printf("Enter translation for %s: ", p);
            scanf("%s", dictionary[num_words].translation);
            num_words++;
            p = strtok(NULL, " ");
        }
    }

    rewind(input_file);

    while (fgets(line, MAX_WORD_LEN, input_file)!= NULL) {
        char *p = strtok(line, " ");
        while (p!= NULL) {
            word = strtok(NULL, " ");
            while (word!= NULL) {
                int i;
                for (i = 0; i < num_words; i++) {
                    if (strcmp(dictionary[i].word, word) == 0) {
                        fprintf(output_file, "%s ", dictionary[i].translation);
                        break;
                    }
                }
                if (i == num_words) {
                    fprintf(output_file, "%s ", word);
                }
                word = strtok(NULL, " ");
            }
            p = strtok(NULL, " ");
        }
        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}