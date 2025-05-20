//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    char *data;
    int size;
    int position;
} buffer;

void init_buffer(buffer *b) {
    b->data = (char*) malloc(MAX_SIZE * sizeof(char));
    b->size = 0;
    b->position = 0;
}

void write_buffer(buffer *b, char c) {
    if (b->position == b->size) {
        b->size += MAX_SIZE;
        b->data = (char*) realloc(b->data, b->size * sizeof(char));
    }
    b->data[b->position++] = c;
}

void flush_buffer(buffer *b) {
    b->data[b->position] = '\0';
    printf("%s", b->data);
    b->position = 0;
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    char c;
    buffer input_buffer, output_buffer;

    printf("Enter input filename: ");
    scanf("%s", input_filename);
    printf("Enter output filename: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    init_buffer(&input_buffer);
    init_buffer(&output_buffer);

    while ((c = fgetc(input_file))!= EOF) {
        write_buffer(&input_buffer, c);
        if (input_buffer.position == 8) {
            flush_buffer(&input_buffer);
        }
    }

    if (input_buffer.position!= 0) {
        flush_buffer(&input_buffer);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}