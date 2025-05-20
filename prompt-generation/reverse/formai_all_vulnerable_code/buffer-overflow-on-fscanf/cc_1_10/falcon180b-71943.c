//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} word_pair;

int load_words(word_pair *words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words file.\n");
        return 1;
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].alien) == 2) {
        count++;
        if (count == MAX_WORDS) {
            printf("Warning: reached maximum number of words.\n");
            break;
        }
    }

    fclose(file);
    return 0;
}

int main() {
    word_pair words[MAX_WORDS];
    if (load_words(words)!= 0) {
        return 1;
    }

    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence in English:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    char output[MAX_WORD_LENGTH];
    output[0] = '\0';

    char *token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, words[i].english) == 0) {
                strcat(output, words[i].alien);
                strcat(output, " ");
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("Warning: unknown word '%s'.\n", token);
        }

        token = strtok(NULL, " ");
    }

    printf("Alien translation: %s\n", output);

    return 0;
}