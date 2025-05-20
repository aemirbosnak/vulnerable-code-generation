#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 4096

void compress(char *input) {
    char buffer[BUFFER_SIZE];
    int index = 0;

    for (int i = 0; input[i]; i++) {
        buffer[index++] = input[i] > 'A' && input[i] < 'Z' ? input[i] + 13 : input[i];
    }

    printf("Compressed Data: %s\n", buffer);
}

int main() {
    char input[1024];

    printf("Enter data to compress:\n");
    fgets(input, sizeof(input), stdin);

    compress(input);

    char padding[BUFFER_SIZE];
    memset(padding, '\0', BUFFER_SIZE);

    printf("Input data after padding:\n");
    printf("%s\n", padding);

    printf("Size of input data after padding: %zu\n", strlen(padding));

    // Here comes the overflow
    int number;
    sscanf(padding, "%d%n", &number, padding + BUFFER_SIZE - 1);

    printf("Stored number: %d\n", number);
    return 0;
}
