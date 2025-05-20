//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 20

// Function to read words from file
void read_words(char *filename, char **words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[WORD_LENGTH];
    int count = 0;

    // Read words from file
    while (fscanf(file, "%s", word)!= EOF) {
        words[count] = strdup(word);
        count++;
    }

    fclose(file);
}

// Function to compare words
int compare_words(char *word1, char *word2) {
    int length1 = strlen(word1);
    int length2 = strlen(word2);

    if (length1!= length2) {
        return 0;
    }

    for (int i = 0; i < length1; i++) {
        if (tolower(word1[i])!= tolower(word2[i])) {
            return 0;
        }
    }

    return 1;
}

// Function to check spelling
void check_spelling(char **words, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (compare_words(words[i], words[j])) {
                printf("Possible spelling error: %s and %s\n", words[i], words[j]);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <dictionary>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    char *dictionary = argv[2];

    // Read words from file
    char **words = malloc(MAX_WORDS * sizeof(char *));
    int count = 0;
    read_words(filename, words);
    count = count - 1;

    // Read dictionary
    FILE *dict_file = fopen(dictionary, "r");
    if (dict_file == NULL) {
        printf("Error opening dictionary file %s\n", dictionary);
        exit(1);
    }

    char dict_word[WORD_LENGTH];
    while (fscanf(dict_file, "%s", dict_word)!= EOF) {
        words[count] = strdup(dict_word);
        count++;
    }

    fclose(dict_file);

    // Sort words
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Check spelling
    check_spelling(words, count);

    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}