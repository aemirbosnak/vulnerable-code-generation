//Falcon-180B DATASET v1.0 Category: Text processing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *input_file;
    char filename[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    char *token;
    int num_words = 0;
    WordCount word_counts[MAX_WORDS];

    printf("Enter the filename: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, input_file)!= NULL) {
        num_words = 0;
        token = strtok(line, ",.?!;:");

        while (token!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Warning: maximum number of words reached\n");
                break;
            }

            strcpy(word_counts[num_words].word, token);
            word_counts[num_words].count = 1;

            token = strtok(NULL, ",.?!;:");
            num_words++;
        }
    }

    fclose(input_file);

    printf("Enter the word to search for: ");
    scanf("%s", line);

    for (int i = 0; i < num_words; i++) {
        if (strcmp(line, word_counts[i].word) == 0) {
            printf("The word '%s' appears %d times\n", word_counts[i].word, word_counts[i].count);
            break;
        }
    }

    return 0;
}