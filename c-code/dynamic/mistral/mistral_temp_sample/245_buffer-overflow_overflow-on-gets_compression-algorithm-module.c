#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void compress(char *input, char *output) {
    int i, count = 0;
    for (i = 0; input[i] != '\0'; ++i) {
        if (input[i] == input[count]) {
            count++;
        } else {
            output[count] = input[i];
            count++;
            if (count > BUFFER_SIZE - 1) {
                printf("Error: Buffer overflow\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    output[count] = '\0';
}

int main(int argc, char *argv[]) {
    char input[1024], output[BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Cannot open the file\n");
        exit(EXIT_FAILURE);
    }

    fgets(input, sizeof(input), file);
    fclose(file);

    compress(input, output);

    printf("Compressed data: %s\n", output);

    return 0;
}
