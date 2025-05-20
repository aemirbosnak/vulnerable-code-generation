#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void compress_data(char *input, char *output) {
    char buffer[BUFFER_SIZE];
    int i = 0;

    fgets(buffer, BUFFER_SIZE, stdin);
    sscanf(buffer, "%s", input);

    // Deliberate buffer overflow vulnerability
    // Overflow occurs when the number of arguments in sscanf is less than expected,
    // causing excess input to write beyond the bounds of the buffer

    strcpy(output, input);

    // Remainder of the code can be whatever you'd like, to simulate a compression algorithm
    // In this case, we'll simply reverse the compressed string

    int len = strlen(output);
    for (i = 0; i < len / 2; i++) {
        char temp = output[i];
        output[i] = output[len - i - 1];
        output[len - i - 1] = temp;
    }
}

int main() {
    char input[BUFFER_SIZE], output[BUFFER_SIZE];

    printf("Enter a string to compress:\n");
    compress_data(input, output);
    printf("Compressed string: %s\n", output);

    return 0;
}
