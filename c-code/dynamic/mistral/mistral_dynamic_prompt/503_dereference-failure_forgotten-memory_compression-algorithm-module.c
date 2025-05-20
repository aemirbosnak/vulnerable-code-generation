#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void compress(char *input, char *output) {
    int len = strlen(input);
    int *frequencies = (int*) malloc(256 * sizeof(int));

    for (int i = 0; i < len; i++) {
        frequencies[input[i]]++;
    }

    int index = 0;
    for (int i = 0; i < 256; i++) {
        if (frequencies[i]) {
            output[index++] = i;
            output[index++] = frequencies[i];
        }
    }

    printf("Compressed data:\n");
    for (int i = 0; i < len; i++) {
        printf("%c", output[i]);
    }
}

int main() {
    char input[1000];
    char output[1000];
    printf("Enter a string: ");
    scanf("%s", input);

    compress(input, output);

    return 0;
}
