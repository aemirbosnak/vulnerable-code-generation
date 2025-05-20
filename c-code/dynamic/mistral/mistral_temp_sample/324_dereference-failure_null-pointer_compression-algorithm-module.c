#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    char buffer[BUFFER_SIZE];
    char *ptr = (char *) malloc(BUFFER_SIZE * sizeof(char));
    int i, count = 0, repeat = 1;

    if (!ptr) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (i = 0; input[i] != '\0'; ++i) {
        if (i > 0 && input[i] == ptr[i - repeat]) {
            ++count;
        } else {
            if (count > 1) {
                snprintf(buffer, BUFFER_SIZE, "%d%c", count, input[i]);
                strncat(output, buffer, BUFFER_SIZE);
            } else {
                output[count] = input[i];
            }
            count = 1;
            repeat = 0;
            ptr[i] = input[i];
        }
    }

    // Null pointer dereference vulnerability
    if (count > 1) {
        snprintf(buffer, BUFFER_SIZE, "%d%c", count, ptr[strlen(input)]);
        strncat(output, buffer, BUFFER_SIZE);
    } else {
        output[count] = ptr[strlen(input)];
    }

    free(ptr);
}

int main() {
    char input[BUFFER_SIZE] = "AABBBBCDABABC";
    char output[BUFFER_SIZE] = "";
    compress(input, output);
    printf("Compressed data: %s\n", output);
    return 0;
}
