//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_LEN 256
#define MAX_WORDS 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[MAX_WORD_LEN];
    int words[MAX_WORDS];
    int i, j, k;
    int total_words = 0;

    while (fscanf(fp, "%s", buffer) != EOF) {
        for (i = 0; i < total_words; i++) {
            if (strcmp(buffer, words[i]) == 0) {
                break;
            }
        }

        if (i == total_words) {
            words[total_words] = strdup(buffer);
            total_words++;
        }
    }

    fclose(fp);

    for (i = 0; i < total_words; i++) {
        printf("%s: ", words[i]);

        int count = 0;
        fp = fopen(argv[1], "r");
        while (fscanf(fp, "%s", buffer) != EOF) {
            if (strcmp(buffer, words[i]) == 0) {
                count++;
            }
        }
        fclose(fp);

        printf("%d\n", count);
    }

    return 0;
}