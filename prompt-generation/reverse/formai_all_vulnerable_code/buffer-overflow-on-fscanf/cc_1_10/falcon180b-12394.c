//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

char *words[MAX_WORDS];
int num_words = 0;

void load_words(char *filename) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Too many words in dictionary.\n");
            exit(1);
        }
        words[num_words++] = strdup(word);
    }
    fclose(file);
}

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void sort_words() {
    qsort(words, num_words, sizeof(char *), compare_words);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dictionary> <text_file>\n", argv[0]);
        return 1;
    }

    load_words(argv[1]);
    sort_words();

    char line[MAX_WORD_LENGTH];
    FILE *file = fopen(argv[2], "r");
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, words[i]) == 0) {
                    break;
                }
            }
            if (i == num_words) {
                printf("%s is not in the dictionary.\n", word);
            }
            word = strtok(NULL, ",.?!;:");
        }
    }
    fclose(file);

    return 0;
}