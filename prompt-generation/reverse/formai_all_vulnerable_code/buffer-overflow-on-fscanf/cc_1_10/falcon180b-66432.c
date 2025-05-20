//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000
#define MAX_SUGGESTIONS 5

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Dictionary;

Dictionary dictionary[MAX_DICTIONARY_SIZE];
int numWords = 0;

void loadDictionary(char* filename) {
    FILE* fp;
    char line[MAX_WORD_LENGTH];
    int wordCount = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file\n");
        exit(1);
    }

    while (fscanf(fp, "%s", line)!= EOF) {
        if (wordCount >= MAX_DICTIONARY_SIZE) {
            printf("Error: dictionary is full\n");
            exit(1);
        }

        strcpy(dictionary[wordCount].word, line);
        dictionary[wordCount].frequency = 1;
        wordCount++;
    }

    numWords = wordCount;
    fclose(fp);
}

int compareWords(const void* a, const void* b) {
    Dictionary* dictA = (Dictionary*)a;
    Dictionary* dictB = (Dictionary*)b;

    return strcmp(dictA->word, dictB->word);
}

void spellCheck(char* text) {
    char word[MAX_WORD_LENGTH];
    char* token;
    int i, j, k;

    token = strtok(text, " ");
    while (token!= NULL) {
        i = 0;
        while (isalnum(token[i])) {
            word[i] = tolower(token[i]);
            i++;
        }
        word[i] = '\0';

        k = 0;
        qsort(dictionary, numWords, sizeof(Dictionary), compareWords);
        for (j = 0; j < numWords; j++) {
            if (strcmp(word, dictionary[j].word) == 0) {
                k = 1;
                break;
            }
        }

        if (k == 0) {
            printf("Possible spelling mistake: %s\n", word);

            int numSuggestions = 0;
            char suggestions[MAX_SUGGESTIONS][MAX_WORD_LENGTH];

            j = 0;
            while (dictionary[j].frequency > 0 && numSuggestions < MAX_SUGGESTIONS) {
                int distance = 0;
                while (distance < strlen(dictionary[j].word) && distance < strlen(word) &&
                       dictionary[j].word[distance]!= word[distance]) {
                    distance++;
                }

                if (distance == strlen(word)) {
                    strcpy(suggestions[numSuggestions], dictionary[j].word);
                    numSuggestions++;
                }

                j++;
            }

            if (numSuggestions > 0) {
                printf("Did you mean: ");
                for (int l = 0; l < numSuggestions; l++) {
                    printf("%s ", suggestions[l]);
                }
                printf("\n");
            }
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    char filename[100];
    printf("Enter dictionary filename: ");
    scanf("%s", filename);

    loadDictionary(filename);

    char text[1000];
    printf("Enter text to spell check: ");
    scanf("%s", text);

    spellCheck(text);

    return 0;
}