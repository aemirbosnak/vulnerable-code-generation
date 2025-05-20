//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

int compare(const void* a, const void* b) {
    Word* wordA = (Word*)a;
    Word* wordB = (Word*)b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    char input[1000];
    char word[MAX_WORD_LEN];
    FILE* dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    Word words[MAX_WORDS];
    int numWords = 0;

    while (fscanf(dictionary, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Dictionary is too large.\n");
            return 1;
        }
        strcpy(words[numWords].word, word);
        words[numWords].count = 0;
        numWords++;
    }

    fclose(dictionary);

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char* token = strtok(input, ",.!?;:-_\"'");
        while (token!= NULL) {
            int len = strlen(token);
            if (len > MAX_WORD_LEN) {
                len = MAX_WORD_LEN;
            }
            strncpy(word, token, len);
            word[len] = '\0';

            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("%s is not in the dictionary.\n", word);
            }

            token = strtok(NULL, ",.!?;:-_\"'");
        }
        printf("\n");
    }

    for (int i = 0; i < numWords; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}