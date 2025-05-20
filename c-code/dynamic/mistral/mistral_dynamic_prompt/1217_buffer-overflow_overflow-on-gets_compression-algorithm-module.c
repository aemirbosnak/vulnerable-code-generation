#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void compress(char *input) {
    char buffer[10];
    int i;

    for (i = 0; i < strlen(input); ++i) {
        strncat(buffer, &input[i], 1);
        if (i == strlen(buffer) - 3 && strcmp(buffer, "aba") == 0) {
            strcat(buffer, "A");
        }
    }

    printf("Compressed data: %s\n", buffer);
}

int main() {
    char input[1000];
    printf("Enter data to compress: ");
    gets(input);
    compress(input);

    return 0;
}
