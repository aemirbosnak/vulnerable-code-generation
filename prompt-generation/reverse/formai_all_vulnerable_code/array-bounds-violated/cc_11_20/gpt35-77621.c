//FormAI DATASET v1.0 Category: Text processing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_NUM_WORDS 5000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please enter a file name.\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("Could not open file.\n");
        return 1;
    }

    char word[MAX_WORD_LEN];
    char *words[MAX_NUM_WORDS];
    int freq[MAX_NUM_WORDS] = {0};
    int n_words = 0;

    while (fscanf(file, "%s", word) == 1) {
        int len = strlen(word);
        // convert to lowercase
        for (int i = 0; i < len; i++) {
            word[i] = tolower(word[i]);
        }
        // remove punctuation
        if (ispunct(word[len - 1])) {
            word[len - 1] = '\0';
        }
        words[n_words] = strdup(word);
        freq[n_words]++;
        n_words++;
        while (fscanf(file, "%s", word) == 1) {
            len = strlen(word);
            for (int i = 0; i < len; i++) {
                word[i] = tolower(word[i]);
            }
            if (ispunct(word[len - 1])) {
                word[len - 1] = '\0';
            }
            int found = 0;
            for (int i = 0; i < n_words; i++) {
                if (strcmp(words[i], word) == 0) {
                    freq[i]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                words[n_words] = strdup(word);
                freq[n_words]++;
                n_words++;
            }
            if (n_words == MAX_NUM_WORDS) {
                printf("Too many words.\n");
                return 1;
            }
        }
    }

    printf("Word frequency:\n");
    for (int i = 0; i < n_words; i++) {
        printf("%s: %d\n", words[i], freq[i]);
        free(words[i]);
    }

    fclose(file);
    return 0;
}