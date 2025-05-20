//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char *english;
    char *alien;
};

void load_words(struct word *words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].alien) == 2) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Too many words.\n");
            exit(1);
        }
    }

    fclose(file);
}

void translate(char *text, struct word *words) {
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            text[i] = toupper(text[i]);
        }
    }

    int word_count = 0;
    char *words_array[MAX_WORD_LENGTH];
    char *token = strtok(text, " ");
    while (token!= NULL) {
        int found = 0;
        for (j = 0; j < word_count; j++) {
            if (strcmp(token, words[j].english) == 0) {
                strcpy(words_array[word_count], words[j].alien);
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words_array[word_count], "UNKNOWN");
        }

        word_count++;
        token = strtok(NULL, " ");
    }

    printf("Alien translation:\n");
    for (i = 0; i < word_count; i++) {
        printf("%s ", words_array[i]);
    }
    printf("\n");
}

int main() {
    struct word words[MAX_WORDS];
    load_words(words);

    char text[1000];
    printf("Enter text to translate:\n");
    fgets(text, sizeof(text), stdin);

    translate(text, words);

    return 0;
}