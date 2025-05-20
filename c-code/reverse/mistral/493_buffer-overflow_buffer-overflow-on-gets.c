#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 128

typedef struct {
    char letter;
    int count;
} LetterCount;

int compareLetters(const void *a, const void *b) {
    return ((LetterCount *)b)->count - ((LetterCount *)a)->count;
}

int main() {
    char input[1024];
    LetterCount freq[MAX_CHAR];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; i < MAX_CHAR; ++i)
        freq[i].count = 0;

    for (int i = 0; input[i]; ++i) {
        if (isalpha(input[i])) {
            char c = tolower(input[i]);
            ++freq[c].count;
        }
    }

    qsort(freq, MAX_CHAR, sizeof(LetterCount), compareLetters);

    printf("Most frequent letter: %c, count: %d\n", freq[0].letter, freq[0].count);

    return 0;
}
