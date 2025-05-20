//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000
#define MAX_LINE_LENGTH 1000

char *dict[] = {"cat", "dog", "bird", "fish", "hamster", "rabbit", "snake", "turtle", "lizard", "parrot"};
int num_dict_words = sizeof(dict)/sizeof(char *);

void read_dict(char *filename) {
    FILE *fp;
    char word[MAX_WORD_LENGTH];
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        dict[num_dict_words++] = strdup(word);
    }

    fclose(fp);
}

int is_valid_word(char *word) {
    int i;

    for (i = 0; i < num_dict_words; i++) {
        if (strcmp(word, dict[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

void process_line(char *line) {
    char word[MAX_WORD_LENGTH];
    int i, j;

    i = 0;
    while (i < strlen(line)) {
        if (isalpha(line[i])) {
            j = 0;
            while (isalpha(line[i]) && j < MAX_WORD_LENGTH) {
                word[j++] = tolower(line[i++]);
            }
            word[j] = '\0';
            if (is_valid_word(word)) {
                printf("%s\n", word);
            }
        } else {
            i++;
        }
    }
}

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];

    if (argc < 2) {
        printf("Usage: cat_translator <dictionary_file>\n");
        exit(1);
    }

    read_dict(argv[1]);

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        process_line(line);
    }

    return 0;
}