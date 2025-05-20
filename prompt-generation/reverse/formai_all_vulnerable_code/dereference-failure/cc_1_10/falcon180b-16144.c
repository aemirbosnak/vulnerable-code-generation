//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char *english;
    char *alien;
};

void load_words(struct word words[]) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *token;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        if (fgets(line, MAX_WORD_LENGTH, file) == NULL) {
            printf("Error: words.txt is empty\n");
            exit(1);
        }

        token = strtok(line, " ");
        words[i].english = strdup(token);

        token = strtok(NULL, " ");
        words[i].alien = strdup(token);
    }

    fclose(file);
}

void translate_sentence(struct word words[], char sentence[]) {
    char *token;
    int i;

    token = strtok(sentence, " ");
    while (token!= NULL) {
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("unknown word: %s\n", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}

int main() {
    struct word words[MAX_WORDS];

    load_words(words);

    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(words, sentence);

    return 0;
}