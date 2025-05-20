//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000000
#define WORD_LEN 64

typedef struct {
    char word[WORD_LEN];
    int count;
} Word;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    Word words[MAX_WORDS];
    int num_words = 0;
    char buffer[WORD_LEN];

    while (fscanf(file, "%s", buffer)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Maximum number of words reached: %d\n", MAX_WORDS);
            break;
        }

        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(buffer, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == num_words) {
            strcpy(words[num_words].word, buffer);
            words[num_words].count = 1;
            num_words++;
        }
    }

    fclose(file);

    printf("Word\tCount\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}