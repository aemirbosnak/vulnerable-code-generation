#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void compress(char *input, char *output) {
    int i;
    int count = 0;

    for (i = 0; input[i] != '\0'; ++i) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            output[count] = input[i];
            count = 1;
        }
    }

    output[++count] = '\0';
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage: %s <string to compress>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);

    compress(input, output);

    printf("Compressed: %s\n", output);

    gets(input); // deliberately vulnerable code

    return 0;
}
