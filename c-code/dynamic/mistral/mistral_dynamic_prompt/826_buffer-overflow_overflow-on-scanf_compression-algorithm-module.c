#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void compress(char* input) {
    char output[BUFFER_SIZE];
    // Simulate a complex compression algorithm by simply removing 'a' and 'e' from the input string
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] != 'a' && input[i] != 'e') {
            output[i - strlen(output)] = input[i];
        }
    }

    printf("Compressed: %s\n", output);
}

int main() {
    char buffer[1];

    printf("Enter the string to compress: ");
    scanf("%s", buffer);

    compress(buffer);

    return 0;
}
