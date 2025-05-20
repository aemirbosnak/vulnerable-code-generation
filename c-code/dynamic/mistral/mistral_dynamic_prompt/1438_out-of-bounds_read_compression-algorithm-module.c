#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    int i, j = 0;
    char temp[BUFFER_SIZE];

    for (i = 0; input[i]; i++) {
        if (i >= BUFFER_SIZE - 1) {
            compress(input + i, temp);
            strcat(output, temp);
            i = 0;
        }

        temp[j++] = input[i];

        if (input[i] == 'A' && (i > 0 && input[i - 1] == 'B')) {
            temp[j] = 'C';
            j++;
        }
    }

    if (i != BUFFER_SIZE - 1) {
        compress(input + i, temp);
        strcat(output, temp);
    } else {
        strcat(output, temp);
    }
}

int main() {
    char input[BUFFER_SIZE];
    char output[2 * BUFFER_SIZE];

    printf("Enter input: ");
    fgets(input, BUFFER_SIZE, stdin);

    compress(input, output);

    printf("Compressed output:\n%s\n", output);

    return 0;
}
