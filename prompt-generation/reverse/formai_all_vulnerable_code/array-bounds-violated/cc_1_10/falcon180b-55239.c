//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word_count {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compare_words(const void *a, const void *b) {
    const struct word_count *word1 = a;
    const struct word_count *word2 = b;

    return strcmp(word1->word, word2->word);
}

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    struct word_count words[MAX_WORDS];

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int i = 0;
        char *token;

        // Remove newline character from end of line
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        // Tokenize line into words
        token = strtok(line, ",.!?;:\"'");
        while (token!= NULL) {
            // Convert word to lowercase
            for (int j = 0; j < strlen(token); j++) {
                token[j] = tolower(token[j]);
            }

            // Check if word is already in array
            int found = 0;
            for (int k = 0; k < word_count; k++) {
                if (strcmp(words[k].word, token) == 0) {
                    words[k].count++;
                    found = 1;
                    break;
                }
            }

            // Add new word to array if not found
            if (!found) {
                strcpy(words[word_count].word, token);
                words[word_count].count = 1;
                word_count++;
            }

            token = strtok(NULL, ",.!?;:\"'");
        }
    }

    // Sort words by count
    qsort(words, word_count, sizeof(struct word_count), compare_words);

    // Print top 10 most frequent words
    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}