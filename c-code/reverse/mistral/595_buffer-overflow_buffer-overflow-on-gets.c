#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SHIFT 3

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0'; ++i) {
        if (isalpha(input[i])) {
            input[i] = (input[i] + SHIFT - 'A') % 26 + 'A';
        }
        printf("%c", input[i]);
    }
    printf("\n");
    return 0;
}
