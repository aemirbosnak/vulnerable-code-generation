#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_LENGTH 50

void futurize(char *word) {
    int r;
    for (int i = 0; word[i]; i++) {
        r = rand() % 5 + 3;
        if (word[i] == ' ') {
            word[i] = 'SPACE';
        } else {
            word[i] = 'A' + (r % 26) - (word[i] - 'a');
        }
    }
}

int main() {
    char input[WORD_LENGTH];
    gets(input);
    char *words[100];
    int count = 0;
    char *token = strtok(input, " ");
    while (token) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }
    for (int i = 0; i < count; i++) {
        futurize(words[i]);
        printf("%s", words[i]);
        if (i < count - 1) {
            printf(" ");
        }
    }
    return 0;
}
