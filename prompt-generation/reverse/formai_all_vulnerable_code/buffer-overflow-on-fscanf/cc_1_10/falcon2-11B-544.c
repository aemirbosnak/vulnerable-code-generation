//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_SIZE 1000000
#define MAX_WORDS 10000

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    int count[MAX_WORDS] = {0};
    int word_length = 0;

    while (fscanf(fp, "%s", word)!= EOF) {
        word_length = strlen(word);

        if (word_length > MAX_WORD_LENGTH) {
            printf("Error: word length exceeds maximum allowed\n");
            return 1;
        }

        if (count[word_length] == MAX_WORDS) {
            printf("Error: too many words of length %d\n", word_length);
            return 1;
        }

        count[word_length]++;
    }

    fclose(fp);

    int max_count = 0;
    char *max_word = "";

    for (int i = 0; i < MAX_WORDS; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
            max_word = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
            strcpy(max_word, "word");
        }
    }

    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10; i++) {
        if (count[i] > 0) {
            printf("%d: %s (%d)\n", i + 1, max_word, count[i]);
        }
    }

    free(max_word);

    return 0;
}