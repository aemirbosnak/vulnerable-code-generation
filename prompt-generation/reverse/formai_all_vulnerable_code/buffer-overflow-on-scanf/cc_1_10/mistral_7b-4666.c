//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char word[WORD_LENGTH];
    int count;
} Word;

Word word_list[MAX_WORDS];
int num_words = 0;

bool is_alpha(char c) {
    return isalpha(c);
}

void process_word(char* word) {
    bool word_exists = false;
    int i;

    for (i = 0; i < num_words; i++) {
        if (strcasecmp(word_list[i].word, word) == 0) {
            word_list[i].count++;
            word_exists = true;
            break;
        }
    }

    if (!word_exists) {
        strcpy(word_list[num_words].word, word);
        word_list[num_words].count = 1;
        num_words++;
    }
}

void process_line(char* line) {
    char word[WORD_LENGTH];
    char* token;
    bool processing_word = false;

    for (token = strtok(line, " ,.-"); token != NULL; token = strtok(NULL, " ,.-")) {
        if (processing_word) {
            process_word(word);
            memset(word, 0, WORD_LENGTH);
            processing_word = false;
        }

        int i, len = strlen(token);

        for (i = 0; i < len; i++) {
            word[i] = tolower(token[i]);
        }

        word[len] = '\0';
        processing_word = true;
    }

    if (processing_word) {
        process_word(word);
    }
}

int main() {
    FILE* fp;
    char filename[100], line[1024];

    printf("Surprised C Word Frequency Counter!\n");
    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error opening file.");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        process_line(line);
    }

    fclose(fp);

    printf("\nWord Frequency Table:\n");

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_list[i].word, word_list[i].count);
    }

    return 0;
}