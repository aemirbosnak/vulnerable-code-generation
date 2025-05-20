#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#define BUFFER_SIZE 256
#define PAYLOAD_SIZE 1024

void compress(char* input, char* output) {
    char buffer[BUFFER_SIZE];
    char payload[PAYLOAD_SIZE];

    strcpy(buffer, input);
    gets(payload);

    // Simulated compression logic
    for (size_t i = 0; i < strlen(buffer); ++i) {
        payload[i] ^= buffer[i];
    }

    // Write the compressed data to the output buffer
    strcpy(output, payload);
}

int main(int argc, char* argv[]) {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 2;
    }

    fgets(input, BUFFER_SIZE, file);
    fclose(file);

    compress(input, output);

    printf("Compressed data:\n%s\n", output);

    return 0;
}
