//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    FILE *ebook = fopen("ebook.txt", "r");
    if (ebook == NULL) {
        printf("Error: could not open ebook file.\n");
        return 1;
    }

    Word words[MAX_WORDS];
    int numWords = 0;

    char line[100];
    while (fgets(line, sizeof(line), ebook)!= NULL) {
        // Remove newline character from end of line
        line[strcspn(line, "\n")] = '\0';

        // Convert line to lowercase
        char *lowerLine = strdup(line);
        for (int i = 0; lowerLine[i]!= '\0'; i++) {
            lowerLine[i] = tolower(lowerLine[i]);
        }

        // Split line into words
        char *token = strtok(lowerLine, ",.!?;:");
        while (token!= NULL) {
            int index = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (index == numWords) {
                if (numWords >= MAX_WORDS - 1) {
                    printf("Error: too many unique words in ebook.\n");
                    fclose(ebook);
                    return 1;
                }
                strcpy(words[numWords].word, token);
                words[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, ",.!?;:");
        }
        free(lowerLine);
    }

    fclose(ebook);

    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < numWords && i < 10; i++) {
        printf("%d. %s (%d occurrences)\n", i + 1, words[i].word, words[i].count);
    }

    return 0;
}