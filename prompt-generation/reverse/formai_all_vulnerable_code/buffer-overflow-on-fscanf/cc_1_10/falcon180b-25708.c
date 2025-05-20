//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

// Alien language words and their English translations
struct word {
    char alien[MAX_WORD_LEN];
    char english[MAX_WORD_LEN];
};

// Load alien language words from a file
void load_words(struct word *words) {
    FILE *file = fopen("words.txt", "r");
    int count = 0;
    while (fscanf(file, "%s %s", words[count].alien, words[count].english) == 2) {
        count++;
        if (count >= MAX_WORDS) {
            break;
        }
    }
    fclose(file);
}

// Translate a sentence from alien language to English
void translate_sentence(char *sentence, struct word *words) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].alien) == 0) {
                printf("%s ", words[i].english);
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("unknown word: %s", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    struct word words[MAX_WORDS];
    load_words(words);

    char sentence[1000];
    printf("Enter a sentence in alien language: ");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence, words);

    return 0;
}