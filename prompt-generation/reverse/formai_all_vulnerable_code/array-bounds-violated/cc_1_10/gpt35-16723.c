//FormAI DATASET v1.0 Category: Spell checking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_WORDS 10000

// Function to read dictionary words from a text file and store them in memory
int read_dictionary(char* file_name, char dictionary[][MAX_WORD_LENGTH]) {
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("\nError: Unable to open file '%s'", file_name);
        return -1;
    }

    int count = 0;
    char line[MAX_WORD_LENGTH];

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (count >= MAX_DICTIONARY_WORDS) {
            printf("\nError: Dictionary size exceeded, max %d words\n", MAX_DICTIONARY_WORDS);
            break;
        }

        size_t line_len = strlen(line);
        // Remove trailing newline if present
        if (line[line_len - 1] == '\n') {
            line[line_len - 1] = '\0';
            line_len--;
        }

        // Convert all uppercase letters to lowercase
        for (int i = 0; i < line_len; i++) {
            if (isupper(line[i])) {
                line[i] = tolower(line[i]);
            }
        }

        strcpy(dictionary[count], line);
        count++;
    }

    fclose(fp);
    return count;
}

// Function to check if a given word is correctly spelled or not
int spell_check(char* word, char dictionary[][MAX_WORD_LENGTH], int dictionary_size) {
    // Convert uppercase letters to lowercase
    size_t len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (isupper(word[i])) {
            word[i] = tolower(word[i]);
        }
    }

    // Binary search the dictionary for the given word
    int start = 0;
    int end = dictionary_size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        int cmp = strcmp(word, dictionary[mid]);
        if (cmp == 0) {
            return 1;
        }
        else if (cmp < 0) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return 0;
}

int main(int argc, char** argv) {
    char dictionary[MAX_DICTIONARY_WORDS][MAX_WORD_LENGTH];
    int dictionary_size = read_dictionary("dictionary.txt", dictionary);
    if (dictionary_size < 0) {
        return 1;
    }
    printf("Dictionary contains %d words\n", dictionary_size);

    // Check if a given text file contains any incorrectly spelled words
    if (argc != 2) {
        printf("\nUsage: %s <text_file_name>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("\nError: Unable to open file '%s'\n", argv[1]);
        return 1;
    }

    printf("\nIncorrectly spelled words:\n");

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        if (!spell_check(word, dictionary, dictionary_size)) {
            printf("%s\n", word);
        }
    }

    fclose(fp);

    return 0;
}