//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void read_file(char *filename, Word *words) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    size_t len = 0;
    ssize_t read;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    while ((read = getline(&line, &len, file))!= -1) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < strlen(word); i++) {
                if (isalpha(word[i])) {
                    word[i] = tolower(word[i]);
                }
            }
            Word *w = NULL;
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    w = &words[i];
                    break;
                }
            }
            if (w == NULL) {
                if (i >= MAX_WORDS) {
                    printf("Error: too many words in file\n");
                    exit(1);
                }
                w = &words[i];
                strcpy(w->word, word);
            }
            w->count++;
            word = strtok(NULL, " ");
        }
    }

    fclose(file);
}

void print_results(Word *words) {
    printf("Word\tCount\n");
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strlen(words[i].word) > 0) {
            printf("%s\t%d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Word words[MAX_WORDS];
    read_file(argv[1], words);
    print_results(words);

    return 0;
}