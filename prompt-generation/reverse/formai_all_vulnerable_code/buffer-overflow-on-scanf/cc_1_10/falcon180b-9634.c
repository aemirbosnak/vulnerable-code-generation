//Falcon-180B DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wc1 = a;
    const WordCount* wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE* file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordCount words[100];
    int numWords = 0;

    printf("Enter filename: ");
    scanf("%s", line);

    file = fopen(line, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int i = 0;
        while (i < strlen(line)) {
            if (isspace(line[i])) {
                line[i] = '\0';
            }
            i++;
        }

        char* token = strtok(line, " ");

        while (token!= NULL) {
            strcpy(word, token);
            int j = 0;

            while (j < strlen(word)) {
                if (isalpha(word[j])) {
                    word[j] = tolower(word[j]);
                }
                j++;
            }

            int k = 0;
            while (k < numWords) {
                if (strcmp(words[k].word, word) == 0) {
                    words[k].count++;
                    break;
                }
                k++;
            }

            if (k == numWords) {
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }

            token = strtok(NULL, " ");
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word count:\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(file);

    return 0;
}