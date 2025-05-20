//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

void loadDictionary(WordTranslation dictionary[MAX_WORDS]) {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: dictionary file not found.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", dictionary[count].word, dictionary[count].translation)!= EOF) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Error: dictionary file has too many entries.\n");
            exit(1);
        }
    }

    fclose(file);
}

int main() {
    WordTranslation dictionary[MAX_WORDS];
    loadDictionary(dictionary);

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a word to translate: ");
        fgets(input, MAX_WORD_LENGTH, stdin);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        char *token = strtok(input, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(dictionary[i].word, token) == 0) {
                    printf("%s -> %s\n", token, dictionary[i].translation);
                    break;
                }
            }

            if (i == MAX_WORDS) {
                printf("No translation found for '%s'.\n", token);
            }

            token = strtok(NULL, " ");
        }
    }

    return 0;
}