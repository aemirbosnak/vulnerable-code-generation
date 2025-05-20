#include <stdint.h>
#include <stddef.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 10

int main(int argc, char *argv[]) {
    FILE *file;
    char words[MAX_WORDS][256];
    int frequencies[MAX_WORDS];
    int num_words = 0;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char word[256];
    while (fscanf(file, "%s", word) == 1) {
        bool found = false;
        for (int i = 0; i < num_words; ++i) {
            if (strcmp(words[i], word) == 0) {
                frequencies[i]++;
                found = true;
                break;
            }
        }

        if (!found) {
            if (num_words >= MAX_WORDS) {
                printf("Array overflow error\n");
                return 1;
            }
            strcpy(words[num_words], word);
            frequencies[num_words++] = 1;
        }
    }

    fclose(file);

    printf("Word frequencies:\n");
    for (int i = 0; i < num_words; ++i) {
        printf("%s: %d\n", words[i], frequencies[i]);
    }

    return 0;
}
