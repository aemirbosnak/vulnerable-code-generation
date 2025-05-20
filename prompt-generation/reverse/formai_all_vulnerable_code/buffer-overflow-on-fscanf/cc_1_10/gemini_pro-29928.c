//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 100

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text file>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    char words[MAX_WORDS][MAX_LEN];
    int nwords = 0;

    while (fscanf(fp, "%s", words[nwords]) != EOF) {
        nwords++;
        if (nwords >= MAX_WORDS) {
            fprintf(stderr, "Too many words in input file\n");
            exit(1);
        }
    }

    fclose(fp);

    int i, j;
    for (i = 0; i < nwords; i++) {
        for (j = 0; j < nwords; j++) {
            if (i == j) {
                continue;
            }

            int diff = strcmp(words[i], words[j]);
            if (diff == 0) {
                printf("%s is a duplicate\n", words[i]);
            } else if (diff < 0) {
                printf("%s comes before %s\n", words[i], words[j]);
            } else {
                printf("%s comes after %s\n", words[i], words[j]);
            }
        }
    }

    return 0;
}