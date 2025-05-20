//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

void loadDictionary(WordTranslation* dictionary) {
    FILE* file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error loading dictionary\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s", dictionary[count].word, dictionary[count].translation)!= EOF) {
        count++;
    }

    fclose(file);
}

void translate(const char* input, WordTranslation* dictionary) {
    char* token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, dictionary[i].word) == 0) {
                printf("%s ", dictionary[i].translation);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    WordTranslation dictionary[MAX_WORDS];
    loadDictionary(dictionary);

    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    translate(input, dictionary);

    return 0;
}