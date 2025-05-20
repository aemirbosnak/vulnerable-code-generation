//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100

typedef struct {
    char *word;
    char *translation;
} cat_dictionary_entry;

cat_dictionary_entry dictionary[] = {
    {"meow", "I am hungry"},
    {"purr", "I am happy"},
    {"hiss", "I am angry"},
    {"meow meow", "I am very hungry"},
    {"purr purr", "I am very happy"},
    {"hiss hiss", "I am very angry"},
    {"meow purr", "I am hungry and happy"},
    {"purr hiss", "I am happy and angry"},
    {"hiss meow", "I am angry and hungry"},
    {"meow purr hiss", "I am hungry, happy, and angry"},
    {"purr hiss meow", "I am happy, angry, and hungry"},
    {"hiss meow purr", "I am angry, hungry, and happy"}
};

const int dictionary_size = sizeof(dictionary) / sizeof(cat_dictionary_entry);

char *translate_cat_language(char *cat_language) {
    char *translation = NULL;

    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(cat_language, dictionary[i].word) == 0) {
            translation = dictionary[i].translation;
            break;
        }
    }

    return translation;
}

int main() {
    char cat_language[MAX_WORD_SIZE];
    char *translation;

    printf("Enter a cat language phrase: ");
    scanf("%s", cat_language);

    translation = translate_cat_language(cat_language);

    if (translation == NULL) {
        printf("Sorry, I don't understand that cat language phrase.\n");
    } else {
        printf("Translation: %s\n", translation);
    }

    return 0;
}