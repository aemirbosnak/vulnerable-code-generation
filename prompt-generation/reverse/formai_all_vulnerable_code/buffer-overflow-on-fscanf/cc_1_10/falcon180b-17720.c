//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char *english;
    char *cat;
} translation;

void load_translations(translation translations[]);
char* translate_sentence(char* sentence, translation translations[]);

int main() {
    translation translations[100];
    load_translations(translations);

    char sentence[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate to Cat:\n");
    fgets(sentence, MAX_WORD_LENGTH, stdin);

    char* translated_sentence = translate_sentence(sentence, translations);
    printf("Translated sentence: %s\n", translated_sentence);

    return 0;
}

void load_translations(translation translations[]) {
    FILE* file = fopen("translations.txt", "r");

    if (file == NULL) {
        printf("Error loading translations file.\n");
        exit(1);
    }

    int num_translations = 0;
    while (fscanf(file, "%s %s\n", translations[num_translations].english, translations[num_translations].cat)!= EOF) {
        num_translations++;
    }

    fclose(file);
}

char* translate_sentence(char* sentence, translation translations[]) {
    int sentence_length = strlen(sentence);
    char* translated_sentence = malloc(sentence_length + 1);

    int translated_sentence_index = 0;
    for (int i = 0; i < sentence_length; i++) {
        if (isalpha(sentence[i])) {
            int english_index = 0;
            while (english_index < MAX_WORD_LENGTH && translations[english_index].english[english_index]!= '\0' && tolower(sentence[i])!= translations[english_index].english[english_index]) {
                english_index++;
            }

            if (translations[english_index].english[english_index]!= '\0') {
                strncat(translated_sentence, translations[english_index].cat, MAX_WORD_LENGTH - english_index);
                translated_sentence_index += strlen(translations[english_index].cat) - english_index;
            } else {
                strncat(translated_sentence, &sentence[i], 1);
                translated_sentence_index++;
            }
        } else {
            strncat(translated_sentence, &sentence[i], 1);
            translated_sentence_index++;
        }
    }

    translated_sentence[translated_sentence_index] = '\0';

    return translated_sentence;
}