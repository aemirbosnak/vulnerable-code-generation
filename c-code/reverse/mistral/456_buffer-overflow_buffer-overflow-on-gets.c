#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 256
#define ALPHABET_SIZE 62

int main() {
    char input[MAX_INPUT];
    char output[MAX_INPUT];
    int i, j, len, sequence[ALPHABET_SIZE];
    time_t t;

    gets(input);

    len = strlen(input);
    srand((unsigned)time(&t));

    for (i = 0; i < len; ++i) {
        output[i] = ' ';
        for (j = 0; j < ALPHABET_SIZE; ++j) {
            sequence[j] = rand() % ALPHABET_SIZE;
        }
        output[i] = sequence[input[i]];
    }

    output[len] = '\0';
    output[len - 1] = ' ';
    output[len - 2] = 'S';
    output[len - 3] = 'P';
    output[len - 4] = 'A';
    output[len - 5] = 'C';
    output[len - 6] = 'E';

    printf("%s\n", output);

    return 0;
}

char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
