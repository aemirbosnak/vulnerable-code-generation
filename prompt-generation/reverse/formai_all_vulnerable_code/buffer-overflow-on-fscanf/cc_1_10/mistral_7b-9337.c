//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_CHARS 50

typedef struct {
    char word[MAX_WORDS];
    char translation[MAX_CHARS];
} WordTranslation;

void loadTranslations(WordTranslation dictionary[], char filename[]) {
    FILE *file = fopen(filename, "r");
    int index = 0;

    if (file == NULL) {
        printf("Could not open file: %s\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s %s", dictionary[index].word, dictionary[index].translation) != EOF) {
        index++;
    }

    fclose(file);
}

void printTranslations(WordTranslation dictionary[], int numTranslations) {
    for (int i = 0; i < numTranslations; i++) {
        printf("%s: %s\n", dictionary[i].word, dictionary[i].translation);
    }
}

void translate(WordTranslation dictionary[], char inputWord[], char output[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(dictionary[i].word, inputWord) == 0) {
            strcpy(output, dictionary[i].translation);
            return;
        }
    }

    strcpy(output, "Unknown word");
}

int main() {
    WordTranslation dictionary[MAX_WORDS];
    char inputWord[MAX_WORDS];
    char output[MAX_CHARS];
    char filename[] = "translations.txt";

    loadTranslations(dictionary, filename);

    printf("Enter a word to translate: ");
    scanf("%s", inputWord);

    translate(dictionary, inputWord, output);

    printf("Translation: %s\n", output);

    printTranslations(dictionary, MAX_WORDS);

    return 0;
}

/* CAT Language Translator Example:

This program is a simple translator written in C that reads translations from a file and stores them in an array of WordTranslation structures. The user can then input a word to translate, which is compared to the stored words in the dictionary. If a match is found, the translation is printed out. If not, an error message is displayed. The program also prints out all the translations in the dictionary.

The filename of the translations file is hardcoded in the program, but it could easily be made a command-line argument. The dictionary array is also of a fixed size, but it could be dynamically allocated if needed.

The translations file should be formatted with one word and its translation per line. For example:

hello world
cat dog
house house

*/