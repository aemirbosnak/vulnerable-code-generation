//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

char words[MAX_WORDS][MAX_WORD_LEN];
int num_words = 0;

void read_file(FILE *file) {
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Maximum number of words reached.\n");
                exit(1);
            }
            int i = 0;
            while (isalpha(ch) && i < MAX_WORD_LEN - 1) {
                words[num_words][i++] = tolower(ch);
                ch = fgetc(file);
            }
            words[num_words][i] = '\0';
            num_words++;
        }
    }
}

void search_word(char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i], word) == 0) {
            printf("Found \"%s\" on line %d.\n", word, i + 1);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <word>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    read_file(file);
    fclose(file);

    char *word = argv[2];
    search_word(word);

    return 0;
}