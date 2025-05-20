#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 256

int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int count = 0;

    if ((file = fopen("log.txt", "r")) == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fscanf(file, "%s", word) != EOF) {
        count++;
    }

    fclose(file);
    printf("Total words: %d\n", count);

    return 0;
}
