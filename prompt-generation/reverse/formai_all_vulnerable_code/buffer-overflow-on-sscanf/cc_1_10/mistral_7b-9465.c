//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define NUM_WORDS 100

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} word_t;

word_t words[NUM_WORDS];

void load_words() {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open words file.\n");
        exit(1);
    }

    int i = 0;
    char line[MAX_WORD_LENGTH * 2];
    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%s %s", words[i].english, words[i].alien);
        i++;
    }

    fclose(fp);
}

void translate_word(char *english) {
    for (int i = 0; i < NUM_WORDS; i++) {
        if (strcmp(words[i].english, english) == 0) {
            printf("%s\n", words[i].alien);
            return;
        }
    }

    printf("Error: Unknown English word.\n");
}

int main() {
    load_words();

    char input[100];
    while (1) {
        printf("Enter English word or type 'quit' to exit: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "quit") == 0) {
            break;
        }

        translate_word(input);
    }

    return 0;
}