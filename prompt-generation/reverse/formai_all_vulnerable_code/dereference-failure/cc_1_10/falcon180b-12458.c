//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char *english;
    char *alien;
} word_pair;

word_pair words[MAX_WORDS];
int num_words;

void load_words() {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *english = strtok(line, " ");
        char *alien = strtok(NULL, " ");

        if (english == NULL || alien == NULL) {
            printf("Invalid line in words file: %s\n", line);
            exit(1);
        }

        words[num_words].english = strdup(english);
        words[num_words].alien = strdup(alien);
        num_words++;
    }

    fclose(fp);
}

char *translate(char *english) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(english, words[i].english) == 0) {
            return words[i].alien;
        }
    }

    return NULL;
}

int main() {
    load_words();

    char input[MAX_WORD_LEN];
    while (true) {
        printf("Enter a word to translate (or type 'quit' to exit): ");
        fgets(input, sizeof(input), stdin);

        char *english = strtok(input, "\n");
        if (strcmp(english, "quit") == 0) {
            break;
        }

        char *alien = translate(english);
        if (alien == NULL) {
            printf("Word not found: %s\n", english);
        } else {
            printf("Alien translation: %s\n", alien);
        }
    }

    return 0;
}