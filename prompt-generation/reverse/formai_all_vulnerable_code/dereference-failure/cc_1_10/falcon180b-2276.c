//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100
#define MAX_FILE_NAME 256

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void readWords(FILE *file, struct WordFrequency *words) {
    char line[MAX_FILE_NAME];
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fgets(line, MAX_FILE_NAME, file)) {
        char *p = line;
        while ((p = strtok(p, " \n\t\r\f\v"))!= NULL) {
            strcpy(word, p);
            struct WordFrequency *found = NULL;
            for (int j = 0; j < i; j++) {
                if (strcmp(word, words[j].word) == 0) {
                    found = &words[j];
                    break;
                }
            }
            if (found == NULL) {
                if (i >= MAX_WORDS) {
                    printf("Error: Maximum number of words reached.\n");
                    exit(1);
                }
                strcpy(found->word, word);
                found->frequency = 1;
                i++;
            } else {
                found->frequency++;
            }
        }
    }
}

void writeWords(FILE *file, struct WordFrequency *words) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency > 0) {
            fprintf(file, "%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    if (input == NULL || output == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    struct WordFrequency words[MAX_WORDS];
    readWords(input, words);

    writeWords(output, words);

    fclose(input);
    fclose(output);

    return 0;
}