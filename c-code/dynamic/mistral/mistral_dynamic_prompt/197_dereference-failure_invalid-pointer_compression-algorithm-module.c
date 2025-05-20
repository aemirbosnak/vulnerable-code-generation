#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 1024

void compress(char *input, char *output) {
    int i;
    char buffer[MAX_BUFFER];

    for (i = 0; i < strlen(input); i++) {
        buffer[(i / 2) % MAX_BUFFER] = input[i];
    }

    strcpy(output, buffer);
}

int main() {
    char input[1] = { '\0' };
    char output[MAX_BUFFER];

    printf("Enter string to compress: ");
    scanf("%s", input);

    compress(input, output);

    printf("Compressed string: %s\n", output);

    char *invalid_ptr = NULL;
    int i;
    for (i = 0; i < 10; i++) {
        printf("%c", *invalid_ptr++);
    }

    return 0;
}
