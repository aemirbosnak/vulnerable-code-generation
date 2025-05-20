//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct {
    char *english;
    char *alien;
} word_t;

void load_words(word_t words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].alien)!= EOF) {
        count++;
    }

    fclose(file);
}

void translate_sentence(char *sentence, word_t words[]) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
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

int main() {
    word_t words[MAX_WORDS];
    load_words(words);

    char sentence[1000];
    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence, words);

    return 0;
}