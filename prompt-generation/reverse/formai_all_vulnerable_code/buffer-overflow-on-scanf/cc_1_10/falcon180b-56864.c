//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word {
    char *english;
    char *alien;
};

int main() {
    int num_words;
    char input_file[100], output_file[100];
    FILE *input_fp, *output_fp;
    struct word words[MAX_WORDS];
    int i, j, found;

    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    num_words = 0;
    while (fscanf(input_fp, "%s", words[num_words].english)!= EOF) {
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in input file.\n");
            exit(1);
        }
    }

    fclose(input_fp);

    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    for (i = 0; i < num_words; i++) {
        found = 0;
        for (j = 0; j < i; j++) {
            if (strcmp(words[i].english, words[j].english) == 0) {
                strcpy(words[i].alien, words[j].alien);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Enter the alien translation for '%s': ", words[i].english);
            fgets(words[i].alien, MAX_WORD_LEN, stdin);
            words[i].alien[strcspn(words[i].alien, "\n")] = '\0';
        }
        fprintf(output_fp, "%s %s\n", words[i].english, words[i].alien);
    }

    fclose(output_fp);

    printf("Translation complete.\n");

    return 0;
}