//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct {
    char *english;
    char *cat;
} Word;

void load_words(Word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat) == 2) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Too many words\n");
            exit(1);
        }
    }

    fclose(file);
}

void translate_sentence(char *sentence, Word words[]) {
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

    printf("\n");
}

int main() {
    Word words[MAX_WORDS];
    load_words(words);

    char sentence[1000];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence, words);

    return 0;
}