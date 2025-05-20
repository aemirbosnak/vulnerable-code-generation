#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_BUFFER 256

int main() {
    char input[MAX_BUFFER];
    char word[MAX_BUFFER];
    int i, len, positive = 0, negative = 0;

    printf("Enter a sentence: ");
    gets(input);

    len = strlen(input);
    for (i = 0; i < len; ++i) {
        if (isspace(input[i])) {
            if (strlen(word) > 0) {
                if (strcmp(word, "SAD") == 0)
                    negative++;
                else if (strcmp(word, "HAPPY") == 0)
                    positive++;

                strcpy(word, "");
            }
            continue;
        }
        word[strlen(word)] = tolower(input[i]);
        word[strlen(word) + 1] = '\0';
    }

    if (strlen(word) > 0) {
        if (strcmp(word, "SAD") == 0)
            negative++;
        else if (strcmp(word, "HAPPY") == 0)
            positive++;
    }

    printf("Positive words: %d\n", positive);
    printf("Negative words: %d\n", negative);

    return 0;
}
