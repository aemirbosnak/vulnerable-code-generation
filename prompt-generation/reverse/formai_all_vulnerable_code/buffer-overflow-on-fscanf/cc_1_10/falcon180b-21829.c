//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

struct word {
    char word[MAX_WORD_LEN];
    char *meaning;
};

void load_dictionary(struct word dict[]);
int find_word(struct word dict[], char *word);
void print_meaning(struct word dict[], int index);

int main() {
    struct word dict[MAX_WORDS];
    load_dictionary(dict);

    char input[MAX_WORD_LEN];
    while (1) {
        printf("Enter a word: ");
        scanf("%s", input);
        int index = find_word(dict, input);
        if (index == -1) {
            printf("Word not found.\n");
        } else {
            print_meaning(dict, index);
        }
    }

    return 0;
}

void load_dictionary(struct word dict[]) {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error loading dictionary.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s\n", dict[count].word, dict[count].meaning)!= EOF) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Dictionary too large.\n");
            exit(1);
        }
    }

    fclose(fp);
}

int find_word(struct word dict[], char *word) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(dict[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void print_meaning(struct word dict[], int index) {
    if (index == -1) {
        printf("No meaning available.\n");
    } else {
        printf("%s: %s\n", dict[index].word, dict[index].meaning);
    }
}