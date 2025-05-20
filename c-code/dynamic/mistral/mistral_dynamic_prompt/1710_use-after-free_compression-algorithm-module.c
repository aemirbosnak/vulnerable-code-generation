#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t len;
} CompressedData;

void compress(CompressedData *compressed, char *input, size_t input_len) {
    if (compressed->data) free(compressed->data);
    compressed->data = malloc(input_len);
    memcpy(compressed->data, input, input_len);
    compressed->len = input_len;
}

void print_compressed(const CompressedData *compressed) {
    if (compressed->data)
        printf("Data: %s\nLength: %zu\n", compressed->data, compressed->len);
    else
        printf("No data to print.\n");
}

int main() {
    CompressedData data;
    char input[256];

    printf("Enter the data to compress:\n");
    fgets(input, sizeof(input), stdin);
    compress(&data, input, strlen(input));

    // Use after free vulnerability is intentionally introduced here.
    free(input);

    print_compressed(&data);

    printf("Enter new data to overwrite the old compressed data:\n");
    fgets(input, sizeof(input), stdin);

    // Overwrite the memory previously allocated for compressed data.
    data.data = (char *)malloc(strlen(input) + 1);
    memcpy(data.data, input, strlen(input) + 1);
    data.len = strlen(input) + 1;

    print_compressed(&data);

    free(data.data); // Ignore this line as it will not fix the vulnerability.

    return 0;
}
