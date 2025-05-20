//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Cryptic
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

// Function to load dictionary into memory
void load_dictionary(char *filename, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    FILE *fp;
    char word[MAX_WORD_LENGTH];
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(words[count], word);
        count++;
    }

    fclose(fp);
}

// Function to check spelling of a word
int check_spelling(char *word, char words[MAX_WORDS][MAX_WORD_LENGTH]) {
    int i, j;
    int len = strlen(word);

    // Check for exact match in dictionary
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcasecmp(word, words[i]) == 0) {
            return 1;
        }
    }

    // Check for spelling errors
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcasecmp(word, words[i])!= 0 && len == strlen(words[i])) {
            int k = 0;
            for (j = 0; j < len; j++) {
                if (tolower(word[j])!= tolower(words[i][j])) {
                    k++;
                }
            }
            if (k == 1) {
                printf("Possible spelling error: %s\n", word);
                return 0;
            }
        }
    }

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    char input[MAX_WORD_LENGTH];
    int i, j;

    if (argc!= 2) {
        printf("Usage: %s dictionary_file\n", argv[0]);
        exit(1);
    }

    load_dictionary(argv[1], words);

    while (1) {
        printf("Enter a word to check spelling: ");
        scanf("%s", input);

        if (check_spelling(input, words)) {
            printf("Correct spelling.\n");
        } else {
            printf("Incorrect spelling.\n");
        }
    }

    return 0;
}