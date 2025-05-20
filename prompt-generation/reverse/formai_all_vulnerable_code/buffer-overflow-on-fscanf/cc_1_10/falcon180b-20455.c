//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int word_count = 0;

void load_words() {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open words.txt\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(words[word_count], word);
        word_count++;
    }

    fclose(fp);
}

void translate(char *sentence) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < word_count; i++) {
            if (strcmp(token, words[i]) == 0) {
                printf("%s", words[i]);
                break;
            }
        }

        if (i == word_count) {
            printf("%s", token);
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    load_words();

    char sentence[1000];
    printf("Enter a sentence in English: ");
    fgets(sentence, sizeof(sentence), stdin);

    translate(sentence);

    return 0;
}