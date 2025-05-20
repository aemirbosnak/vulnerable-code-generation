#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEYWORD_COUNT 4
const char *keywords[KEYWORD_COUNT] = {"advertising", "winning", "watches", "free"};

int main() {
    char input[1024];
    int counts[KEYWORD_COUNT] = {0};

    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; i < strlen(input); ++i) {
        for (int j = 0; j < KEYWORD_COUNT; ++j) {
            size_t len = strlen(keywords[j]);
            if (i + len <= strlen(input) &&
                strncmp(input + i, keywords[j], len) == 0 &&
                isspace(input[i - 1]) && isspace(input[i + len])) {
                counts[j]++;
                if (counts[j] > 0) {
                    printf("Warning: Possible spam detected: %s\n", keywords[j]);
                }
                break;
            }
        }
    }

    return 0;
}
