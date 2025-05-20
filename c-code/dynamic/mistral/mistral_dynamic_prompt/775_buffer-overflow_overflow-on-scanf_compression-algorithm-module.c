#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void compress(char *input, char *output) {
    int i, j = 0;

    for (i = 0; input[i]; i++) {
        if (i > 0 && input[i] == input[i - 1]) {
            output[j++] = input[i];
        } else {
            output[j++] = input[i];
            output[j++] = ' ';
        }
    }
    output[j] = '\0';
}

int main() {
    char input[1024];
    char output[2048];

    printf("Enter the string to compress:\n");
    scanf("%s", input);

    compress(input, output);

    printf("Compressed string:\n%s\n", output);

    return 0;
}
