//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

int loadDictionary(WordPair dictionary[], int maxWords) {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error loading dictionary file.\n");
        return 0;
    }

    int count = 0;
    while (count < maxWords && fscanf(file, "%s %s\n", dictionary[count].word, dictionary[count].translation)!= EOF) {
        count++;
    }

    fclose(file);
    return count;
}

int main() {
    WordPair dictionary[MAX_WORDS];
    int numWords = loadDictionary(dictionary, MAX_WORDS);

    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence in Alien language:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    char output[MAX_WORD_LENGTH];
    output[0] = '\0';
    int outputIndex = 0;

    char *token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(dictionary[i].word, token) == 0) {
                strcat(output, dictionary[i].translation);
                strcat(output, " ");
                break;
            }
        }

        if (i == numWords) {
            printf("Unknown word: %s\n", token);
        }

        token = strtok(NULL, " ");
    }

    printf("Translation: %s\n", output);

    return 0;
}