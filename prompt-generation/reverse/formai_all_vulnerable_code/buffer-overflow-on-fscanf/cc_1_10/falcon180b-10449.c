//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

char *words[MAX_WORDS];
int word_counts[MAX_WORDS];

char *read_word(FILE *file) {
    char *word = malloc(MAX_WORD_LENGTH * sizeof(char));
    int word_length = 0;

    while (fscanf(file, "%c", &word[word_length])!= EOF) {
        if (isalpha(word[word_length])) {
            word_length++;
        } else {
            word[word_length] = '\0';
            break;
        }
    }

    return word;
}

void count_words(FILE *file) {
    char *word;

    while ((word = read_word(file))!= NULL) {
        int index = 0;

        while (index < MAX_WORDS && words[index]!= NULL) {
            if (strcmp(word, words[index]) == 0) {
                word_counts[index]++;
                break;
            }

            index++;
        }

        if (index == MAX_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            exit(1);
        } else if (words[index] == NULL) {
            words[index] = word;
            word_counts[index] = 1;
        }

        free(word);
    }
}

void print_results() {
    printf("Word\tFrequency\n");

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i]!= NULL) {
            printf("%s\t%d\n", words[i], word_counts[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    count_words(file);

    fclose(file);
    print_results();

    return 0;
}