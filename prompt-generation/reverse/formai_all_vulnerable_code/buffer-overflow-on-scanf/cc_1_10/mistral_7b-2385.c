//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char *word;
    int count;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void add_word(char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcasecmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }

    if (num_words == MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }

    words[num_words].word = malloc(strlen(word) + 1);
    strcpy(words[num_words].word, word);
    words[num_words].count = 1;
    num_words++;
}

void process_line(char *line) {
    char *token = strtok(line, " ,.!?:;()\"'");

    while (token != NULL) {
        for (int i = 0; i < num_words; i++) {
            if (strcasecmp(words[i].word, token) == 0) {
                words[i].count++;
                break;
            }
        }

        if (num_words < MAX_WORDS) {
            add_word(token);
        }

        token = strtok(NULL, " ,.!?:;()\"'");
    }
}

int main() {
    char filename[100];
    FILE *file;

    printf("Enter file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[1024];

    while (fgets(line, sizeof(line), file) != NULL) {
        process_line(line);
    }

    fclose(file);

    printf("\nWord frequencies:\n");

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
        free(words[i].word);
    }

    return 0;
}