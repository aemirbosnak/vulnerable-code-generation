#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void compress(char *input) {
    char output[BUFFER_SIZE];
    int i, j = 0;

    for (i = 0; input[i]; i++) {
        if (i > 0 && input[i] == input[i - 1]) {
            if (output[j] != 0)
                output[j]++;
            else
                output[j] = input[i];
        } else {
            if (output[j] != 0)
                printf("%c(%d) ", output[j], output[j]);
            output[j] = input[i];
            j++;
        }
    }

    printf("%c(%d) ", output[j], output[j]);
}

int main() {
    char input[10];

    printf("Enter a string to compress:\n");
    scanf("%s", input);

    compress(input);

    return 0;
}
