//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    bool isInDictionary;
} Word;

int main() {
    FILE *dictionaryFile;
    Word dictionary[MAX_DICTIONARY_SIZE];
    int numWordsInDictionary = 0;

    // Open the dictionary file for reading
    dictionaryFile = fopen("dictionary.txt", "r");
    if (dictionaryFile == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    // Read words from the dictionary file and add them to the dictionary array
    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(dictionaryFile, "%s", word)!= EOF) {
        strcpy(dictionary[numWordsInDictionary].word, word);
        dictionary[numWordsInDictionary].isInDictionary = true;
        numWordsInDictionary++;
    }

    // Close the dictionary file
    fclose(dictionaryFile);

    // Open the text file for reading
    FILE *textFile;
    char fileName[100];
    printf("Enter the name of the text file: ");
    scanf("%s", fileName);
    textFile = fopen(fileName, "r");
    if (textFile == NULL) {
        printf("Error opening text file.\n");
        return 1;
    }

    // Read words from the text file and check if they are in the dictionary
    char text[MAX_WORD_LENGTH + 1];
    while (fscanf(textFile, "%s", text)!= EOF) {
        int i;
        for (i = 0; i < numWordsInDictionary; i++) {
            if (strcmp(dictionary[i].word, text) == 0) {
                printf("%s is a valid word.\n", text);
            } else if (dictionary[i].isInDictionary) {
                printf("%s is misspelled.\n", text);
            }
        }
    }

    // Close the text file
    fclose(textFile);

    return 0;
}