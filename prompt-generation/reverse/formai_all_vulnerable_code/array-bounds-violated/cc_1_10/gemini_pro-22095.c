//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

int compare_words(const void* a, const void* b) {
    return strcmp(((Word*)a)->word, ((Word*)b)->word);
}

void load_dictionary(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    char line[MAX_WORD_LEN];
    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strlen(line) - 1] = '\0';  // Remove newline character
        strcpy(dictionary[num_words].word, line);
        dictionary[num_words].count = 0;
        num_words++;
    }

    fclose(fp);
}

int is_valid_word(const char* word) {
    int left = 0;
    int right = num_words - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        int cmp = strcmp(word, dictionary[mid].word);

        if (cmp == 0) {
            return 1;
        } else if (cmp < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return 0;
}

void check_spelling(const char* text) {
    char* token = strtok(text, " ");
    while (token != NULL) {
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        if (!is_valid_word(token)) {
            printf("'%s' is not a valid word\n", token);
        }

        token = strtok(NULL, " ");
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <dictionary file> <text file>\n", argv[0]);
        exit(1);
    }

    load_dictionary(argv[1]);

    qsort(dictionary, num_words, sizeof(Word), compare_words);

    FILE* fp = fopen(argv[2], "r");
    if (fp == NULL) {
        perror("Error opening text file");
        exit(1);
    }

    char text[10000];
    fread(text, sizeof(char), sizeof(text), fp);
    fclose(fp);

    check_spelling(text);

    return 0;
}