//Falcon-180B DATASET v1.0 Category: Firewall ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

int main() {
    char line[100];
    FILE *file;
    char filename[50];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, 100, file)!= NULL) {
        char *word = strtok(line, ",.?!;:");

        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: maximum number of words (%d) exceeded\n", MAX_WORDS);
                exit(1);
            }

            int len = strlen(word);

            if (len > MAX_WORD_LENGTH) {
                printf("Error: word '%s' is too long (max %d characters)\n", word, MAX_WORD_LENGTH);
                exit(1);
            }

            for (i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    printf("Error: word '%s' contains non-alphabetic characters\n", word);
                    exit(1);
                }
            }

            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;

            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Enter the number of most frequent words to display: ");
    scanf("%d", &i);

    for (int j = 0; j < i && j < numWords; j++) {
        printf("%s: %d\n", words[j].word, words[j].count);
    }

    return 0;
}