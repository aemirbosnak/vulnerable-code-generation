//Falcon-180B DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

typedef struct {
    char *word;
    int count;
} WordCount;

void read_file(FILE *file, WordCount *word_counts, int num_word_counts) {
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int i;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int word_length = 0;

        // Convert line to lowercase
        for (i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Count words in line
        char *token = strtok(line, ",.?!-");
        while (token!= NULL) {
            strcpy(word, token);
            word_length = strlen(word);

            // Ignore words shorter than 2 characters
            if (word_length >= 2) {
                int j;
                for (j = 0; j < num_word_counts; j++) {
                    if (strcmp(word_counts[j].word, word) == 0) {
                        word_counts[j].count++;
                        break;
                    }
                }
            }

            token = strtok(NULL, ",.?!-");
        }
    }
}

void write_word_counts(WordCount *word_counts, int num_word_counts) {
    int i;

    for (i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    WordCount word_counts[MAX_LINE_LENGTH];
    int num_word_counts = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    read_file(file, word_counts, num_word_counts);

    fclose(file);

    write_word_counts(word_counts, num_word_counts);

    return 0;
}