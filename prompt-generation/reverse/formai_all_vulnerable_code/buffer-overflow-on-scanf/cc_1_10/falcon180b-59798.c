//Falcon-180B DATASET v1.0 Category: Data mining ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_frequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void read_file(FILE *file, struct word_frequency *words, int word_count) {
    char line[MAX_WORD_LENGTH];
    char *word;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        for (word = strtok(line, " "); word!= NULL; word = strtok(NULL, " ")) {
            if (strlen(word) > 0) {
                if (isalpha(word[0])) {
                    int i;
                    for (i = 0; i < word_count; i++) {
                        if (strcmp(words[i].word, word) == 0) {
                            words[i].frequency++;
                            break;
                        }
                    }
                    if (i == word_count) {
                        if (word_count < MAX_WORDS) {
                            strncpy(words[word_count].word, word, MAX_WORD_LENGTH - 1);
                            words[word_count].word[MAX_WORD_LENGTH - 1] = '\0';
                            words[word_count].frequency = 1;
                            word_count++;
                        }
                    }
                }
            }
        }
    }
}

void write_file(FILE *file, struct word_frequency *words, int word_count) {
    int i;

    for (i = 0; i < word_count; i++) {
        fprintf(file, "%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    FILE *input_file, *output_file;
    struct word_frequency words[MAX_WORDS];
    int word_count = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    read_file(input_file, words, word_count);

    fclose(input_file);

    printf("Enter the name of the output file: ");
    scanf("%s", filename);

    output_file = fopen(filename, "w");

    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    write_file(output_file, words, word_count);

    fclose(output_file);

    printf("Done.\n");

    return 0;
}