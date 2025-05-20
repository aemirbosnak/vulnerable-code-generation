//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define DICTIONARY_FILE "dictionary.txt"

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} Word;

Word dictionary[MAX_WORDS];
int numWords;

void readDictionary() {
    FILE* file;
    char line[100];
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
    int i = 0;

    file = fopen(DICTIONARY_FILE, "r");
    if (file == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (i >= MAX_WORDS) {
            printf("Dictionary is full.\n");
            exit(1);
        }
        sscanf(line, "%s %s", word, translation);
        strcpy(dictionary[i].word, word);
        strcpy(dictionary[i].translation, translation);
        i++;
    }

    numWords = i;
    fclose(file);
}

void translate() {
    char sentence[1000];
    char word[MAX_WORD_LENGTH];
    int i, j;

    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin);

    i = 0;
    while ((word[0] = toupper(sentence[i]))!= '\0') {
        j = 0;
        while (isalpha(word[j]) && j < MAX_WORD_LENGTH - 1) {
            word[j] = tolower(sentence[i]);
            i++;
            j++;
        }
        word[j] = '\0';

        for (int k = 0; k < numWords; k++) {
            if (strcmp(dictionary[k].word, word) == 0) {
                printf("%s ", dictionary[k].translation);
                break;
            }
        }
    }

    printf("\n");
}

int main() {
    readDictionary();
    translate();

    return 0;
}