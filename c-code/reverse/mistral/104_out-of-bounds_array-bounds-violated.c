#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void process_input(char *input) {
    int i, j, k;
    char temp[10];

    for (i = 0; i < 10; i++) {
        for (j = 0; input[i] != '\0'; j++) {
            if (isalpha(input[i])) {
                temp[j] = toupper(input[i]);
            } else if (j > 0 && isalpha(temp[j - 1])) {
                temp[j] = '_';
            } else {
                break;
            }
        }
        temp[j] = '\0';

        for (k = 0; k < i; k++) {
            if (strcmp(temp, input + k) == 0) {
                break;
            }
            if (k == i - 1) {
                printf("'%s' is a unique knight name.\n", temp);
            }
        }

        if (k == i) {
            for (j = 0; j < 10; j++) {
                input[i * 10 + j] = temp[j];
            }
        }
    }
}

int main() {
    char input[512];

    printf("Enter the names of your knights (up to 512 characters, separated by spaces):\n");
    fgets(input, sizeof(input), stdin);

    process_input(input);

    return 0;
}
