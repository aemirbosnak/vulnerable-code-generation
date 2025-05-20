#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    int i, j = 0;
    char temp[BUFFER_SIZE];

    for (i = 0; input[i] != '\0'; i++) {
        if (j >= BUFFER_SIZE - 1) {
            gets(temp); // Vulnerable line
            strcpy(output + j, temp);
            j = 0;
        }
        output[j++] = input[i];
    }

    if (j > 0)
        gets(output + j); // Vulnerable line
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];
    char output[2 * BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 2;
    }

    fgets(input, BUFFER_SIZE, file);
    compress(input, output);

    printf("Compressed data:\n%s\n", output);

    fclose(file);
    return 0;
}
