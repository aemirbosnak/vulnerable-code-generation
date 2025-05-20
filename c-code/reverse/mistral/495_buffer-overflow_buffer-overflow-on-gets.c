#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_CHAR 256

typedef struct {
    char letter;
    int count;
} LetterCount;

void init_count(LetterCount *arr) {
    for (int i = 0; i < MAX_CHAR; ++i) {
        arr[i].count = 0;
    }
}

void increment_count(LetterCount *arr, char c) {
    if (isalpha(c)) {
        arr[(unsigned char)tolower(c)].count++;
    }
}

LetterCount find_max(LetterCount *arr) {
    LetterCount max = {0};
    for (int i = 0; i < MAX_CHAR; ++i) {
        if (arr[i].count > max.count) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    char input[1024];
    LetterCount counts[MAX_CHAR];
    init_count(counts);

    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; i < strlen(input); ++i) {
        increment_count(counts, input[i]);
    }

    LetterCount max = find_max(counts);
    printf("Most frequent letter: %c, count: %d\n", max.letter, max.count);

    return 0;
}
