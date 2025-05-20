//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

char words[MAX_WORDS][MAX_WORD_LEN];
int num_words;

void read_words(FILE *fp) {
    char word[MAX_WORD_LEN];
    char ch;

    num_words = 0;

    while (fscanf(fp, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words.\n");
            exit(1);
        }

        strcpy(words[num_words], word);
        num_words++;
    }
}

void count_words(char *text) {
    char ch;
    int i, j;

    for (i = 0; text[i]!= '\0'; i++) {
        ch = tolower(text[i]);

        if (isalpha(ch)) {
            for (j = 0; j < num_words; j++) {
                if (strcmp(words[j], &text[i]) == 0) {
                    printf("%s found at position %d.\n", words[j], i);
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char text[1000000];

    if (argc!= 3) {
        printf("Usage: %s <movie_reviews_file> <movie_title>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: could not open file %s.\n", argv[1]);
        return 1;
    }

    read_words(fp);
    fclose(fp);

    printf("Searching for %s in movie reviews...\n", argv[2]);

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: could not open file %s.\n", argv[1]);
        return 1;
    }

    while (fgets(text, sizeof(text), fp)!= NULL) {
        count_words(text);
    }

    fclose(fp);

    return 0;
}