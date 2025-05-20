//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;

int compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void load_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        if (num_words >= MAX_WORDS) {
            printf("Maximum number of words exceeded\n");
            exit(1);
        }

        int len = strlen(word);
        if (len >= MAX_WORD_LENGTH) {
            printf("Word too long: %s\n", word);
            exit(1);
        }

        strcpy(words[num_words], word);
        num_words++;
    }

    fclose(file);
}

void print_words() {
    qsort(words, num_words, sizeof(words[0]), compare);

    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the file containing the list of words: ");
    scanf("%s", filename);

    load_words(filename);

    printf("The words in alphabetical order are:\n");
    print_words();

    return 0;
}