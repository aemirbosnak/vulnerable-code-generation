#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void compress(char *input, char *output) {
    int size = 1024;
    char buffer[size];

    int count = sscanf(input, "%512s", buffer);
    if (count == 1) {
        strcpy(output, buffer);
        printf("Compressed size: %ld bytes\n", strlen(buffer));
    } else {
        printf("Invalid input\n");
    }
}

int main() {
    char input[1024];
    char output[1024];

    printf("Enter input (max 512 chars): ");
    fgets(input, sizeof(input), stdin);

    compress(input, output);

    printf("Output:\n%s\n", output);

    return 0;
}
