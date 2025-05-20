//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100

typedef struct {
    char word[MAX_WORDS][20];
    char translation[MAX_WORDS][50];
    int count;
} Dictionary;

void loadDictionary(Dictionary *dict) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("dictionary.txt", "r");

    if (fp == NULL) {
        printf("Error loading dictionary file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        strcpy(dict->word[i], line);
        dict->count++;
        i++;
    }

    fclose(fp);
}

int searchDictionary(Dictionary dict, char *word) {
    int i;

    for (i = 0; i < dict.count; i++) {
        if (strcmp(dict.word[i], word) == 0) {
            return i;
        }
    }

    return -1;
}

void translate(Dictionary dict, char *sentence) {
    char word[20];
    int i, j;

    for (i = 0; i < strlen(sentence); i++) {
        if (isspace(sentence[i])) {
            word[i] = '\0';

            j = searchDictionary(dict, word);

            if (j!= -1) {
                printf("%s -> %s\n", word, dict.translation[j]);
            } else {
                printf("%s -> Unknown\n", word);
            }

            i++;
        } else {
            word[i] = tolower(sentence[i]);
        }
    }
}

int main() {
    Dictionary dict;

    loadDictionary(&dict);

    char sentence[100];

    printf("Enter a sentence to translate:\n");
    scanf("%s", sentence);

    translate(dict, sentence);

    return 0;
}