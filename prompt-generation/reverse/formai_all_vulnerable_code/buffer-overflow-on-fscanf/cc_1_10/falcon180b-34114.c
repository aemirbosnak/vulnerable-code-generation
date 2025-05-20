//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
};

void loadWords(struct word words[]) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].cat)!= EOF) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            exit(1);
        }
    }

    fclose(file);
}

void translate(char *english, char *cat) {
    struct word words[MAX_WORDS];
    loadWords(words);

    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].english, english) == 0) {
            printf("%s\n", words[i].cat);
            return;
        }
    }

    printf("Unknown word: %s\n", english);
}

int main() {
    char input[MAX_WORD_LENGTH];

    while (1) {
        printf("Enter an English word to translate to Cat: ");
        fgets(input, MAX_WORD_LENGTH, stdin);

        char *english = strtok(input, "\n");
        if (english == NULL) {
            printf("Error: empty input\n");
            continue;
        }

        translate(english, "");
    }

    return 0;
}