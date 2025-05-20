//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_CHARS 100

typedef struct {
    char english[MAX_CHARS];
    char cat[MAX_CHARS];
} word_pair;

void load_words(word_pair words[]);
void translate_sentence(char sentence[], word_pair words[]);

int main() {
    word_pair words[MAX_WORDS];

    load_words(words);

    char sentence[MAX_CHARS];
    printf("Enter a sentence to translate: ");
    fgets(sentence, MAX_CHARS, stdin);

    translate_sentence(sentence, words);

    return 0;
}

void load_words(word_pair words[]) {
    FILE *file = fopen("words.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int count = 0;
    while (count < MAX_WORDS && fscanf(file, "%s %s", words[count].english, words[count].cat)!= EOF) {
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
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}