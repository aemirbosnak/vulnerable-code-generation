#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

typedef struct {
    char letter;
    int count;
} Letter;

int compare(const void *a, const void *b) {
    return ((Letter *)b)->count - ((Letter *)a)->count;
}

int main() {
    char input[1000000];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    Letter freq[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        freq[i].letter = 'a' + i;
        freq[i].count = 0;
    }

    for (int i = 0, len = strlen(input); i < len; ++i) {
        if (isalpha(input[i])) {
            int index = tolower(input[i]) - 'a';
            freq[index].count++;
        }
    }

    qsort(freq, ALPHABET_SIZE, sizeof(Letter), compare);

    printf("Most frequent letter: %c\n", freq[0].letter);

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (freq[i].count == freq[0].count) {
            printf("%c ", freq[i].letter);
        }
    }

    return 0;
}
