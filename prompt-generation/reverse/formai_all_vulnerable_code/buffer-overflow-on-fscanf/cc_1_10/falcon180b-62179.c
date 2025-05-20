//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

char dictionary[MAX_WORDS][MAX_WORD_LENGTH];
int num_words = 0;

void load_dictionary(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error loading dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(dictionary[num_words], word);
        num_words++;
    }

    fclose(fp);
}

int find_word(char* word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return i;
        }
    }
    return -1;
}

char* translate_sentence(char* sentence) {
    char* result = malloc(strlen(sentence) + 1);
    strcpy(result, "");

    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        int index = find_word(word);
        if (index!= -1) {
            strcat(result, dictionary[index]);
            strcat(result, " ");
        } else {
            strcat(result, word);
            strcat(result, " ");
        }
        word = strtok(NULL, " ");
    }

    return result;
}

int main() {
    load_dictionary("dictionary.txt");

    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    scanf("%[^\n]", sentence);

    char* translated_sentence = translate_sentence(sentence);
    printf("Translated sentence: %s\n", translated_sentence);

    free(translated_sentence);
    return 0;
}