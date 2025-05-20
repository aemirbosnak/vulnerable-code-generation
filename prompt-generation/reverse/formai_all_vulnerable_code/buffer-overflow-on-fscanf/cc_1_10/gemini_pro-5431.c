//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char *words[MAX_WORDS];
    int counts[MAX_WORDS];

    int num_words = 0;
    while (1) {
        char word[MAX_WORD_LEN];
        if (fscanf(fp, "%s", word) != 1) {
            break;
        }

        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i]) == 0) {
                counts[i]++;
                break;
            }
        }

        if (i == num_words) {
            words[num_words] = strdup(word);
            counts[num_words] = 1;
            num_words++;
        }
    }

    fclose(fp);

    qsort(words, num_words, sizeof(char *), strcmp);

    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], counts[i]);
    }

    return EXIT_SUCCESS;
}