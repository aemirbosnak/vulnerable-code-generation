//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char text[MAX_WORD_LENGTH];
    int count;
};

int main() {
    FILE *input_file, *output_file;
    char line[MAX_WORD_LENGTH];
    struct word words[MAX_WORDS];
    int num_words = 0;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        int word_length = strlen(line);
        if (word_length > MAX_WORD_LENGTH) {
            printf("Error: word is too long.\n");
            exit(1);
        }

        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(words[i].text, line) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == num_words) {
            if (num_words == MAX_WORDS) {
                printf("Error: too many words.\n");
                exit(1);
            }

            strcpy(words[num_words].text, line);
            words[num_words].count = 1;
            num_words++;
        }
    }

    fprintf(output_file, "Word count:\n");
    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "%s: %d\n", words[i].text, words[i].count);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}