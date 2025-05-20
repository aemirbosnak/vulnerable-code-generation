#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

int main() {
    char *input, c;
    int freq[ALPHABET_SIZE] = {0};
    int max_freq = 0;
    int index;

    input = (char *) malloc(sizeof(char) * 10000);
    if (!input) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter text: ");
    gets(input);

    for (int i = 0; input[i]; ++i) {
        c = tolower(input[i]);
        if (c >= 'a' && c <= 'z') {
            freq[(int)(c - 'a')]++;
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            index = i;
        }
    }

    printf("Most frequent letter: %c\n", 'a' + index);
    printf("Frequency: %d\n", max_freq);

    free(input);
    return 0;
}
