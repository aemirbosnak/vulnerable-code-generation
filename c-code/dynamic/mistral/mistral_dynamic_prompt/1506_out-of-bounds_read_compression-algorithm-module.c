#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void compress(char *input, char *output, int len) {
    int i, j = 0;
    char temp[256];

    for (i = 0; i < len - 1; i++) {
        if (input[i] == input[i + 1]) {
            temp[j++] = input[i];
        } else {
            if (j > 0) {
                temp[j] = '\0';
                output[i / 2] = temp[0];
                output[(i + 1) / 2] = temp[j - 1] ? temp[j - 1] : ' ';
                j = 0;
            }
        }
    }

    // Deliberate out-of-bounds read
    if (j > 0) {
        temp[j] = '\0';
        printf("Last character: %c\n", temp[j - 1]); // Out-of-bounds read vulnerability
    }

    // Ignore the last character if not repeated
    if (i == len - 1 && j < 2) {
        output[i / 2] = input[i];
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input string>\n", argv[0]);
        return 1;
    }

    char input[1024] = {0};
    strncpy(input, argv[1], sizeof(input) - 1);

    char output[512 * 2];
    compress(input, output, strlen(input));

    printf("Compressed string: %s\n", output);
    return 0;
}
