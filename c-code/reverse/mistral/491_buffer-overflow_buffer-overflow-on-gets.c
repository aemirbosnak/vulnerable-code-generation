#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256

typedef struct {
    char letter;
    int count;
} LetterCount;

void process_text(char *text, LetterCount *freq) {
    int len = strlen(text);
    for (int i = 0; i < len; ++i) {
        char c = tolower(text[i]);
        if (c >= 'a' && c <= 'z') {
            int index = c - 'a';
            if (freq[index].count == 0) {
                freq[index].letter = c;
                freq[index].count = 1;
            } else {
                ++freq[index].count;
            }
        }
    }
}

int main() {
    char input[MAX_CHAR];
    LetterCount freq[MAX_CHAR];
    printf("Enter text: ");
    fgets(input, MAX_CHAR, stdin);
    process_text(input, freq);

    int max_count = 0;
    int max_index = -1;
    for (int i = 0; i < MAX_CHAR; ++i) {
        if (freq[i].count > max_count) {
            max_count = freq[i].count;
            max_index = i;
        }
    }

    printf("Most frequent letter: %c, count: %d\n", freq[max_index].letter, freq[max_index].count);
    return 0;
}
