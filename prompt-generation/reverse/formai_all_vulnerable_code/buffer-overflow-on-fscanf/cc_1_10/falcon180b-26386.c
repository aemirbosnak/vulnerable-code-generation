//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    FILE *input_file;
    char input_string[MAX_WORD_LENGTH];
    char *token;
    WordFrequency word_frequencies[MAX_WORDS];
    int num_words = 0;
    int i;

    input_file = fopen("post-apocalyptic.txt", "r");

    if (input_file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    while (fscanf(input_file, "%s", input_string)!= EOF) {
        token = strtok(input_string, ",.?!;");

        while (token!= NULL) {
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, word_frequencies[i].word) == 0) {
                    word_frequencies[i].count++;
                    break;
                }
            }

            if (i == num_words) {
                strcpy(word_frequencies[num_words].word, token);
                word_frequencies[num_words].count = 1;
                num_words++;
            }

            token = strtok(NULL, ",.?!;");
        }
    }

    fclose(input_file);

    printf("Word frequencies:\n");

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].count);
    }

    return 0;
}