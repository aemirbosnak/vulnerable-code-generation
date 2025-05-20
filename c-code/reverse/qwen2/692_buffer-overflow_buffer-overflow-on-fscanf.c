#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 10

int main() {
    FILE *file = fopen("log.txt", "r");
    char word[MAX_WORD_LENGTH];
    int counts[256] = {0};

    while (fscanf(file, "%s", word) != EOF) {
        counts[word[0]]++;
    }

    fclose(file);

    for (int i = 0; i < 256; i++) {
        if (counts[i] > 0) {
            printf("%c: %d\n", i, counts[i]);
        }
    }

    return 0;
}
