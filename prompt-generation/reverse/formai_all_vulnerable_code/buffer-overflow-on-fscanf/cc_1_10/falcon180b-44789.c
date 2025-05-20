//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char english[50];
    char cat[50];
} word;

void load_words(word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (!file) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat)!= EOF) {
        count++;
    }

    fclose(file);
}

void translate_sentence(const char *sentence, word words[]) {
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
            printf("unknown ");
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    word words[MAX_WORDS];
    load_words(words);

    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence, words);

    return 0;
}