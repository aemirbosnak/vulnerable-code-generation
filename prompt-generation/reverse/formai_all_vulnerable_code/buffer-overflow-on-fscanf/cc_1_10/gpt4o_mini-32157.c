//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_TRANSLATIONS 100

typedef struct {
    char human[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Translation;

typedef struct {
    Translation translations[MAX_TRANSLATIONS];
    int count;
} Dictionary;

void init_dictionary(Dictionary* dict) {
    dict->count = 0;
}

void add_translation(Dictionary* dict, const char* human, const char* alien) {
    if(dict->count < MAX_TRANSLATIONS) {
        strncpy(dict->translations[dict->count].human, human, MAX_WORD_LENGTH);
        strncpy(dict->translations[dict->count].alien, alien, MAX_WORD_LENGTH);
        dict->count++;
    } else {
        printf("Dictionary is full, cannot add more translations.\n");
    }
}

const char* translate(Dictionary* dict, const char* human_word) {
    for(int i = 0; i < dict->count; i++) {
        if(strcmp(dict->translations[i].human, human_word) == 0) {
            return dict->translations[i].alien;
        }
    }
    return NULL;
}

void load_dictionary(Dictionary* dict, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open the dictionary file.\n");
        return;
    }
    
    char human[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];

    while(fscanf(file, "%s %s", human, alien) == 2) {
        add_translation(dict, human, alien);
    }

    fclose(file);
}

void display_translations(Dictionary* dict) {
    printf("List of translations:\n");
    for(int i = 0; i < dict->count; i++) {
        printf("%s -> %s\n", dict->translations[i].human, dict->translations[i].alien);
    }
}

int main() {
    Dictionary dict;
    init_dictionary(&dict);

    load_dictionary(&dict, "translations.txt");
    display_translations(&dict);
    
    char input[MAX_WORD_LENGTH];
    while(1) {
        printf("Enter a word to translate (or type 'exit' to quit): ");
        scanf("%s", input);
        
        if(strcmp(input, "exit") == 0) {
            break;
        }

        const char* translation = translate(&dict, input);
        if(translation) {
            printf("Translation: %s\n", translation);
        } else {
            printf("No translation found for '%s'.\n", input);
        }
    }

    return 0;
}