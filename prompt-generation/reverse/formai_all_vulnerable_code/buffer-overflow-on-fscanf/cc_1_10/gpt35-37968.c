//FormAI DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define WORD_COUNT 1000

// Function to check if a character is a valid alphabet
int is_alpha(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    return 0;
}

// Function to remove non-alphabetic characters from a word
void clean_word(char* word) {
    int i = 0, j = 0;

    while(word[i] != '\0') {
        if (is_alpha(word[i])) {
            word[j++] = tolower(word[i]);
        }
        i++;
    }
    word[j] = '\0';
}

// Function to compare two words
int compare_words(const void* a, const void* b) {
    char* s1 = *(char**)a;
    char* s2 = *(char**)b;
    return strcmp(s1, s2);
}

int main() {
    FILE* fp;
    char word[MAX_WORD_LEN];
    char* words[WORD_COUNT];
    int i = 0, j;

    // Open the file for reading
    fp = fopen("input.txt", "r");
    if(fp == NULL) {
        printf("Unable to open file\n");
        exit(0);
    }

    // Read words from file and store them in an array
    while(fscanf(fp, "%s", word) != EOF) {
        clean_word(word);
        // Ignore empty words
        if(strlen(word) == 0) {
            continue;
        }
        words[i] = (char*)malloc(sizeof(char) * MAX_WORD_LEN);
        strcpy(words[i++], word);
    }

    // Close the file
    fclose(fp);

    // Sort the words array
    qsort(words, i, sizeof(char*), compare_words);

    // Check for spelling errors
    for(j = 1; j < i; j++) {
        if(strcmp(words[j], words[j-1]) == 0) {
            printf("%s is spelled incorrectly!\n", words[j]);
            free(words[j]);
        }
    }

    // Free memory allocated for words array
    for(j = 0; j < i; j++) {
        free(words[j]);
    }

    return 0;
}