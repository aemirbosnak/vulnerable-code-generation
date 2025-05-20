//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 4096

typedef struct {
    char *data;
    int size;
} Buffer;

void init_buffer(Buffer *buffer) {
    buffer->data = (char *) malloc(MAX_BUFFER_SIZE);
    buffer->size = 0;
}

void free_buffer(Buffer *buffer) {
    free(buffer->data);
}

void add_char(Buffer *buffer, char c) {
    if (buffer->size >= MAX_BUFFER_SIZE) {
        printf("Error: Buffer overflow!\n");
        exit(1);
    }
    buffer->data[buffer->size++] = c;
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[256], output_filename[256];
    Buffer input_buffer, output_buffer;

    printf("Enter input filename: ");
    scanf("%s", input_filename);
    printf("Enter output filename: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    init_buffer(&input_buffer);
    init_buffer(&output_buffer);

    int input_char;
    while ((input_char = fgetc(input_file))!= EOF) {
        if (isalpha(input_char)) {
            add_char(&output_buffer, tolower(input_char));
        }
    }

    int output_char;
    while ((output_char = getc(output_buffer.data))!= EOF) {
        fputc(output_char, output_file);
    }

    free_buffer(&input_buffer);
    free_buffer(&output_buffer);

    fclose(input_file);
    fclose(output_file);

    return 0;
}