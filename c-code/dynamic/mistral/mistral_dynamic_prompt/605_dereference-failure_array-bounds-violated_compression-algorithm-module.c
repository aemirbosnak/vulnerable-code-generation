#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    int i, j = 0;
    char tmp[BUFFER_SIZE];

    for (i = 0; input[i] != '\0'; ++i) {
        if (i > BUFFER_SIZE - 1) {
            tmp[j] = input[i];
            j = 0;
        }
        if (i > 0 && input[i] == tmp[j]) {
            tmp[j] = '[';
            tmp[j + 1] = input[i];
            tmp[j + 2] = ']';
            memcpy(&tmp[j + 3], &tmp[j + 1], j);
            j += 3;
        } else {
            tmp[j] = input[i];
            ++j;
        }
    }

    strcpy(output, tmp);
}

int main() {
    char input[BUFFER_SIZE] = "AAAAABBBCCDAAAAXXX";
    char output[BUFFER_SIZE];

    compress(input, output);

    printf("Compressed: %s\n", output);

    // Access out of bounds
    printf("%c", output[BUFFER_SIZE]);

    return 0;
}
