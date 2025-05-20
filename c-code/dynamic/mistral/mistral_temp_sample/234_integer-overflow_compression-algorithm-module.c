#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    int magic_number;
    unsigned int version;
    char data[BUFFER_SIZE];
} CompressedData;

int compress(const void *in, CompressedData *out) {
    const char *input = in;
    size_t input_len = strlen(input);
    size_t i, j, count = 0;
    out->magic_number = 0xDEADBEEF;
    out->version = 1;

    for (i = j = 0; i < input_len; i++) {
        if (i > 0 && input[i] == input[i - 1]) {
            count++;
        } else {
            out->data[j++] = input[i];
            if (count > 9) {
                out->data[j++] = count / 10 + '0';
                out->data[j++] = count % 10 + '0';
                count = 0;
            } else if (count > 0) {
                out->data[j++] = count + '0';
                count = 0;
            }
        }
    }

    return j;
}

int main() {
    char input[BUFFER_SIZE];
    printf("Enter the string to compress: ");
    fgets(input, BUFFER_SIZE, stdin);

    CompressedData compressed_data;
    size_t len = compress(input, &compressed_data);

    FILE *output_file = fopen("compressed_data.bin", "wb");
    fwrite(&compressed_data, sizeof(CompressedData), 1, output_file);
    fclose(output_file);

    printf("Compressed data saved to compressed_data.bin\n");

    return 0;
}
