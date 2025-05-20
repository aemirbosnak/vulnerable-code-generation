//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *file;
    char filename[100];
    char line[MAX_WORD_LEN];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file and count words
    while (fgets(line, MAX_WORD_LEN, file)!= NULL) {
        int len = strlen(line);
        int wordCount = 0;
        char *token = strtok(line, ",.?!;:\"'");
        while (token!= NULL) {
            int j;
            for (j = 0; j < len; j++) {
                if (isalpha(line[j])) {
                    line[j] = tolower(line[j]);
                }
            }
            wordCount++;
            strcpy(words[numWords].word, token);
            words[numWords].count = wordCount;
            numWords++;
            token = strtok(NULL, ",.?!;:\"'");
        }
    }

    // Sort words by frequency
    qsort(words, numWords, sizeof(WordCount), compare);

    // Print results
    printf("Word frequency:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Close file
    fclose(file);

    return 0;
}