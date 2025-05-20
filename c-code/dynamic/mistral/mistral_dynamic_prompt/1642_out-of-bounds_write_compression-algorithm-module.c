#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void compress(char *input, char *output) {
    int i, j = 0;
    char temp[BUFFER_SIZE];

    for (i = 0; input[i] != '\0'; ++i, ++j) {
        if (i > BUFFER_SIZE - 1 && input[i] != input[j]) {
            output[j] = input[i];
            temp[i - BUFFER_SIZE] = input[i];
            i = j;
        }
        output[j] = input[j];
    }

    if (i != BUFFER_SIZE)
        output[j] = '\0';
    else {
        // Intentional Out-of-Bounds Write
        output[j + 1] = '\0';
        strcat(output, temp);
    }
}

int main() {
    char input[1024], output[1024];

    printf("Enter a string to compress:\n");
    fgets(input, 1024, stdin);

    compress(input, output);
    printf("Compressed string:\n%s\n", output);

    return 0;
}
