#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

int main() {
    char input[BUFFER_SIZE];
    char sanitized[BUFFER_SIZE];
    int i, j = 0;

    for (i = 0; i < 3; i++) {
        printf("Enter input %d: ", i + 1);
        fgets(input, BUFFER_SIZE, stdin);

        for (int k = 0; input[k]; k++) {
            if (!isalnum(input[k]) && input[k] != '_' && input[k] != ' ') {
                input[k] = '_';
            }
            sanitized[j++] = tolower(input[k]);
        }
        sanitized[j] = '\0';
    }

    printf("\nWelcome, %s!\n", sanitized);

    return 0;
}
