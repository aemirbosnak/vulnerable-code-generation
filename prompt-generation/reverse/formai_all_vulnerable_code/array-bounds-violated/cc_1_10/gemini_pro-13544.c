//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

char *dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp) != NULL) {
        line[strlen(line) - 1] = '\0';  // Remove newline character
        dictionary[num_words++] = strdup(line);
    }

    fclose(fp);
}

int edit_distance(char *word1, char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + fmin(fmin(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]);
            }
        }
    }

    return matrix[len1][len2];
}

int main() {
    load_dictionary();

    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check: ");
    scanf("%s", word);

    int min_distance = MAX_WORD_LENGTH;
    char *closest_word = NULL;

    for (int i = 0; i < num_words; i++) {
        int distance = edit_distance(word, dictionary[i]);
        if (distance < min_distance) {
            min_distance = distance;
            closest_word = dictionary[i];
        }
    }

    if (min_distance == 0) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is misspelled. Did you mean '%s'?\n", closest_word);
    }

    return 0;
}