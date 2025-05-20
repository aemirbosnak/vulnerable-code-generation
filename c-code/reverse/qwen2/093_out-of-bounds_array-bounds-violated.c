#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

void convertToLower(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

void removePunctuation(char *word) {
    int len = strlen(word);
    while (len > 0 && ispunct(word[len - 1])) {
        word[--len] = '\0';
    }
}

int main() {
    FILE *file;
    char filename[] = "words.txt";
    char word[MAX_WORD_LENGTH];
    char *words[MAX_WORDS];
    int counts[MAX_WORDS] = {0};
    int wordCount = 0;

    if ((file = fopen(filename, "r")) == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fscanf(file, "%s", word) != EOF) {
        convertToLower(word);
        removePunctuation(word);

        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], word) == 0) {
                counts[i]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            if (wordCount >= MAX_WORDS) {
                fprintf(stderr, "Too many words\n");
                fclose(file);
                return EXIT_FAILURE;
            }
            words[wordCount] = strdup(word);
            counts[wordCount++]++;
        }
    }

    fclose(file);

    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], counts[i]);
        free(words[i]);
    }

    return EXIT_SUCCESS;
}
