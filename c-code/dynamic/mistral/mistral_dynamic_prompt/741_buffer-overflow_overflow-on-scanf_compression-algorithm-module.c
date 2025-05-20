#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    int i, j = 0;
    for (i = 0; input[i]; ++i) {
        if (i > BUFFER_SIZE - 1 || j >= BUFFER_SIZE - 1) break;
        output[j++] = (i > 0 && input[i] == input[i - 1]) ? '1' + output[j - 1] : input[i];
    }
}

int main() {
    char input[BUFFER_SIZE], output[BUFFER_SIZE];
    printf("Enter input:\n");
    scanf("%s", input);
    compress(input, output);
    printf("Compressed output:\n%s\n", output);
    return 0;
}
