//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} word_pair;

void load_words(word_pair words[]) {
    FILE *file = fopen("words.txt", "r");

    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat)!= EOF) {
        count++;
    }

    fclose(file);
}

void translate_sentence(char sentence[], word_pair words[]) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].cat);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("unknown word: %s\n", token);
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    word_pair words[MAX_WORDS];
    load_words(words);

    char sentence[1000];
    printf("enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence, words);

    return 0;
}