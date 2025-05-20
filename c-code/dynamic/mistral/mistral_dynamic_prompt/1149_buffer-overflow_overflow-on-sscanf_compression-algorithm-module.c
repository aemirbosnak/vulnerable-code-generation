#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input) {
    char buffer[BUFFER_SIZE];
    int count = 0;
    char temp[3];

    for (int i = 0; input[i] != '\0'; ++i) {
        if (i > 0 && input[i] == input[i - 1]) {
            ++count;
        } else {
            snprintf(temp, sizeof(temp), "%d%c", count, input[i]);
            strcat(buffer, temp);
            count = 1;
        }
    }

    printf("Compressed data: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    char input[BUFFER_SIZE];
    sscanf(argv[1], "%[^\n]", input);
    compress(input);

    return 0;
}
