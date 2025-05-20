//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    FILE *input_file;
    char input_buffer[MAX_WORD_LENGTH];
    char word_buffer[MAX_WORD_LENGTH];
    int i, j;
    Word words[MAX_WORDS];
    int num_words = 0;
    int num_misspelled_words = 0;

    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fscanf(input_file, "%s", input_buffer)!= EOF) {
        if (strlen(input_buffer) > MAX_WORD_LENGTH) {
            printf("Error: Word is too long.\n");
            exit(1);
        }

        for (i = 0; i < strlen(input_buffer); i++) {
            input_buffer[i] = tolower(input_buffer[i]);
        }

        for (i = 0; i < num_words; i++) {
            if (strcmp(input_buffer, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == num_words) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many words.\n");
                exit(1);
            }

            strcpy(words[num_words].word, input_buffer);
            words[num_words].count = 1;
            num_words++;
        }
    }

    fclose(input_file);

    for (i = 0; i < num_words; i++) {
        if (words[i].count == 1) {
            printf("Misspelled word: %s\n", words[i].word);
            num_misspelled_words++;
        }
    }

    if (num_misspelled_words == 0) {
        printf("No misspelled words found.\n");
    } else {
        printf("%d misspelled words found.\n", num_misspelled_words);
    }

    return 0;
}