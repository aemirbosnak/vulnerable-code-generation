#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    char buffer[BUFFER_SIZE];
    int count = 0;

    while (sscanf(input, "%*[^%c]%c", &buffer[count]) != EOF && count < BUFFER_SIZE - 1) {
        count++;
    }

    output = malloc(count + 1);
    strcpy(output, buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    char input[BUFFER_SIZE];
    compress(argv[1], input);
    printf("Compressed: %s\n", input);

    return 0;
}
