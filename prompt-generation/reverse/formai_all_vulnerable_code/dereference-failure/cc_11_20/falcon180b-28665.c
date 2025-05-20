//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *english;
    char *alien;
} WordPair;

int main() {
    FILE *dictionary;
    char line[MAX_WORD_LENGTH];
    WordPair words[MAX_WORDS];
    int numWords = 0;

    dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, dictionary)!= NULL) {
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) > 0) {
            words[numWords].english = strdup(line);
            words[numWords].alien = (char *)malloc(strlen(line) * 2 + 1);
            strcpy(words[numWords].alien, "");

            int i;
            for (i = 0; i < strlen(line); i++) {
                if (isalpha(line[i])) {
                    if (isupper(line[i])) {
                        strcat(words[numWords].alien, "A");
                    } else {
                        strcat(words[numWords].alien, "a");
                    }
                } else if (isdigit(line[i])) {
                    strcat(words[numWords].alien, "1");
                } else {
                    strcat(words[numWords].alien, " ");
                }
            }

            numWords++;
        }
    }

    fclose(dictionary);

    printf("Enter a sentence to translate:\n");
    char sentence[MAX_WORD_LENGTH];
    fgets(sentence, MAX_WORD_LENGTH, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                break;
            }
        }

        if (i == numWords) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}