//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_WORD 128

struct word {
    char *text;
    int count;
};

struct word *word_list = NULL;
int num_words = 0;

void add_word(char *text) {
    struct word *new_word = (struct word *) malloc(sizeof(struct word));
    new_word->text = strdup(text);
    new_word->count = 1;
    word_list = (struct word *) realloc(word_list, sizeof(struct word) * (num_words + 1));
    word_list[num_words] = *new_word;
    num_words++;
}

void print_word_list() {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_list[i].text, word_list[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE];
    char *word;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            add_word(word);
            word = strtok(NULL, " ");
        }
    }

    fclose(fp);

    print_word_list();

    return 0;
}