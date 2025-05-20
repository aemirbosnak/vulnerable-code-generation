#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void count_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return;

    char word[10];
    int count = 0;
    while (fscanf(file, "%s", word) != EOF) {
        count++;
    }
    fclose(file);
    printf("Word count: %d\n", count);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        count_words(argv[1]);
    } else {
        printf("Usage: %s <filename>\n", argv[0]);
    }
    return 0;
}
