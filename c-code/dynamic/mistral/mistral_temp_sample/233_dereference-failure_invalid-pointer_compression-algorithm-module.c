#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

void compress(char *input, char *output) {
    int i;
    char *ptr = (char *) malloc(MAX_BUFFER * sizeof(char));

    for (i = 0; input[i] != '\0'; i++) {
        ptr[i] = input[i] - i;
    }

    strcpy(output, ptr);
    free(ptr);
}

int main(int argc, char *argv[]) {
    char input[MAX_BUFFER], output[MAX_BUFFER];

    printf("Enter input string:\n");
    scanf("%s", input);

    compress(input, output);
    printf("Compressed output:\n%s\n", output);

    return 0;
}
