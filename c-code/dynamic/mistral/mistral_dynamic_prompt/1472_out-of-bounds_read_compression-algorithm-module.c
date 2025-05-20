#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    char buffer[BUFFER_SIZE];
    int index = 0;
    int i, count = 0;

    for (i = 0; input[i] != '\0'; ++i) {
        if (count < BUFFER_SIZE - 1) {
            buffer[count++] = input[i];
        } else {
            buffer[BUFFER_SIZE - 1] = '\0';
            strcpy(output + index, buffer);
            index += count;
            count = 0;
        }
    }

    if (count > 0) {
        buffer[count++] = '\0';
        strcpy(output + index, buffer);
        index += count;
    }

    // OOB Read Vulnerability ---------------------
    printf("Original String Length: %ld\n", strlen(input));
    printf("Compressed String Length: %ld\n", strlen(output));
    printf("Unsafe Access: %c\n", output[index]);
    // -------------------------------------------
}

int main() {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];

    printf("Enter a string to compress: ");
    fgets(input, BUFFER_SIZE, stdin);

    compress(input, output);

    printf("Compressed String: %s\n", output);

    return 0;
}
