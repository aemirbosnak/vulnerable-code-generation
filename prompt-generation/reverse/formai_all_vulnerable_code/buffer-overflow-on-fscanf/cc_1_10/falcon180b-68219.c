//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} word_translation;

void load_words(word_translation words[]);
void translate_sentence(char sentence[], word_translation words[]);

int main() {
    word_translation words[MAX_WORDS];
    load_words(words);

    char sentence[1000];
    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence, words);

    return 0;
}

void load_words(word_translation words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s", words[count].word, words[count].translation)!= EOF) {
        count++;
    }

    fclose(file);
}

void translate_sentence(char sentence[], word_translation words[]) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i = 0;
        while (i < MAX_WORDS && strcasecmp(token, words[i].word)!= 0) {
            i++;
        }

        if (i < MAX_WORDS) {
            printf("%s -> %s ", token, words[i].translation);
        } else {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }
}