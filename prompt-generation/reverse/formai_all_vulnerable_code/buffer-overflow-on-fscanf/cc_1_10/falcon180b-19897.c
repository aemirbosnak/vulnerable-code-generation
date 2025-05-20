//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} word_pair;

word_pair dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error loading dictionary\n");
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

int binary_search(char *word) {
    int low = 0;
    int high = num_words - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(word, dictionary[mid].english);

        if (cmp == 0) {
            printf("Alien: %s\n", dictionary[mid].alien);
            return 0;
        } else if (cmp < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("Word not found\n");
    return 1;
}

int main() {
    load_dictionary();

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter a word to translate: ");
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        int result = binary_search(input);
        if (result == 0) {
            break;
        }
    }

    return 0;
}