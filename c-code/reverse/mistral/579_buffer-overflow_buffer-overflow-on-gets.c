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
    char message[1024];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    int spam = 0;
    for (int i = 0; i < KEYWORD_COUNT; ++i) {
        size_t len = strlen(keywords[i]);
        for (size_t j = 0; j <= message[0] ? strlen(message) - len : 0; ++j) {
            if (strncasecmp(&message[j], keywords[i], len) == 0) {
                spam = 1;
                break;
            }
        }
        if (spam) break;
    }

    printf("%s\n", spam ? "Spam detected" : "No spam found");
    return 0;
}
