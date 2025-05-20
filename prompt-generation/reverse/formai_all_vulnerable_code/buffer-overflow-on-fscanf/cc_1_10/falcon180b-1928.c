//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct word {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error loading dictionary.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s %s\n", line, line) == 2) {
        strcpy(dictionary[num_words].english, line);
        strcpy(dictionary[num_words].alien, line);
        num_words++;
    }

    fclose(fp);
}

int binary_search(char *word, int start, int end) {
    if (start > end) {
        return -1;
    }

    int mid = (start + end) / 2;

    int cmp = strcmp(word, dictionary[mid].english);
    if (cmp == 0) {
        return mid;
    } else if (cmp < 0) {
        return binary_search(word, start, mid - 1);
    } else {
        return binary_search(word, mid + 1, end);
    }
}

void translate_sentence(char *sentence) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int idx = binary_search(token, 0, num_words - 1);
        if (idx!= -1) {
            printf("%s ", dictionary[idx].alien);
        } else {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    load_dictionary();

    char sentence[MAX_WORD_LENGTH * 100];
    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin);

    translate_sentence(sentence);

    return 0;
}