//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <encrypt/decrypt> <input_file>\n", argv[0]);
        return 1;
    }

    char mode = argv[1][0];
    FILE *input_file = fopen(argv[2], "rb");

    if (input_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    long file_size = 0;
    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    unsigned char *buffer = malloc(file_size);
    if (buffer == NULL) {
        printf("Error allocating memory.\n");
        fclose(input_file);
        return 1;
    }

    size_t bytes_read = fread(buffer, 1, file_size, input_file);
    if (bytes_read!= file_size) {
        printf("Error reading file.\n");
        free(buffer);
        fclose(input_file);
        return 1;
    }

    fclose(input_file);

    int key = mode == 'e'? 7 : -7;

    for (size_t i = 0; i < file_size; i++) {
        buffer[i] ^= key;
    }

    FILE *output_file = fopen(argv[2], "wb");

    if (output_file == NULL) {
        printf("Error opening output file.\n");
        free(buffer);
        return 1;
    }

    bytes_read = fwrite(buffer, 1, file_size, output_file);
    if (bytes_read!= file_size) {
        printf("Error writing output file.\n");
        fclose(output_file);
        free(buffer);
        return 1;
    }

    fclose(output_file);
    free(buffer);

    printf("Done.\n");
    return 0;
}