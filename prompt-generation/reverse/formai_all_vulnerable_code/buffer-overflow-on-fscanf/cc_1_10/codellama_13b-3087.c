//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: genius
/*
 * A genius C spell checking program
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 16
#define MAX_WORDS 1000

// Global variables
char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;

// Function prototypes
void load_words();
void check_spelling(char *word);

int main() {
    load_words();
    char word[MAX_WORD_LENGTH];
    while (fgets(word, MAX_WORD_LENGTH, stdin)) {
        check_spelling(word);
    }
    return 0;
}

void load_words() {
    // Load the words from a file
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    num_words = 0;
    while (fscanf(fp, "%s", words[num_words]) == 1) {
        num_words++;
    }
    fclose(fp);
}

void check_spelling(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i]) == 0) {
            printf("%s is a valid word\n", word);
            return;
        }
    }
    printf("%s is not a valid word\n", word);
}