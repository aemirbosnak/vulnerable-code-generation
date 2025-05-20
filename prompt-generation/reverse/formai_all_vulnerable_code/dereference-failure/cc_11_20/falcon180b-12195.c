//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: immersive
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
    char line[1000];
    int num_words = 0;
    struct word *words = (struct word*) malloc(MAX_WORDS * sizeof(struct word));

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");
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
            strcpy(words[num_words].english, word);
            strcpy(words[num_words].alien, "");
            num_words++;
            word = strtok(NULL, " ");
        }
    }

    fclose(input_file);

    int i;
    for (i = 0; i < num_words; i++) {
        printf("Enter translation for '%s': ", words[i].english);
        scanf("%s", words[i].alien);
    }

    fclose(output_file);

    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");

    while (fgets(line, sizeof(line), input_file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int j;
            for (j = 0; j < num_words; j++) {
                if (strcmp(word, words[j].english) == 0) {
                    fprintf(output_file, "%s ", words[j].alien);
                    break;
                }
            }
            if (j == num_words) {
                fprintf(output_file, "%s ", word);
            }
            word = strtok(NULL, " ");
        }
        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);

    free(words);

    return 0;
}