#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT 1000

int main() {
    char input[MAX_INPUT];
    int i, j, k, cyclomatic_complexity = 0;

    gets(input);

    for (i = 0; input[i] != '\0'; ++i) {
        if (isalpha(input[i])) {
            j = toupper(input[i]) - 'A';
            if (j >= 0 && j < 26) {
                k = (j + 13) % 26;
                printf("%c", 'A' + k);
            } else {
                printf("%c", input[i]);
            }
        } else {
            printf("%c", input[i]);
        }

        if (i > 3 && i < 10 && i != 6) {
            ++cyclomatic_complexity;
        }
    }

    printf("\nCyclomatic Complexity: %d\n", cyclomatic_complexity);

    return 0;
}
