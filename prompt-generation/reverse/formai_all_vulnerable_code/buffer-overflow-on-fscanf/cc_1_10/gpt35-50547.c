//FormAI DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <string.h>

const int MAX_WORDS = 1000;
const int MAX_WORD_LENGTH = 100;

void readDictionary(char dictionary[MAX_WORDS][MAX_WORD_LENGTH])
{
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error opening dictionary file\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(file, "%s", dictionary[i]) != EOF) {
        i++;
    }
    fclose(file);
}

void checkSpelling(char document[MAX_WORDS][MAX_WORD_LENGTH], int numWords, char dictionary[MAX_WORDS][MAX_WORD_LENGTH], int numDictionaryWords)
{
    for (int i = 0; i < numWords; i++) {
        int found = 0;
        for (int j = 0; j < numDictionaryWords; j++) {
            if (strcmp(document[i], dictionary[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Misspelled word: %s\n", document[i]);
        }
    }
}

int main()
{
    char dictionary[MAX_WORDS][MAX_WORD_LENGTH];
    readDictionary(dictionary);
    
    char document[MAX_WORDS][MAX_WORD_LENGTH];
    printf("Enter document: ");
    int numWords = 0;
    while (scanf("%s", document[numWords]) != EOF) {
        numWords++;
    }
    
    checkSpelling(document, numWords, dictionary, MAX_WORDS);
    
    return 0;
}