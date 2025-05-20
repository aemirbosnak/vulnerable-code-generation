//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000000 // maximum size of input buffer

// function to read input file into buffer
void read_file(FILE *input_file, char *buffer) {
    int c;
    int buffer_index = 0;

    while ((c = fgetc(input_file))!= EOF) {
        buffer[buffer_index++] = c;
    }

    buffer[buffer_index] = '\0'; // null terminate string
}

// function to write output file from buffer
void write_file(FILE *output_file, char *buffer) {
    fputs(buffer, output_file);
}

// function to compress input file using run-length encoding
void compress_file(FILE *input_file, FILE *output_file) {
    char buffer[MAX_BUFFER_SIZE];
    char current_char;
    int count = 1;

    read_file(input_file, buffer);

    fprintf(output_file, "%d", strlen(buffer)); // write length of uncompressed data

    current_char = buffer[0];
    for (int i = 1; i < strlen(buffer); i++) {
        if (buffer[i]!= current_char) {
            fprintf(output_file, "%d%c", count, current_char);
            count = 1;
            current_char = buffer[i];
        } else {
            count++;
        }
    }

    fprintf(output_file, "%d%c", count, current_char);
}

// function to decompress output file using run-length encoding
void decompress_file(FILE *input_file, FILE *output_file) {
    char buffer[MAX_BUFFER_SIZE];
    int count;
    char current_char;

    fscanf(input_file, "%d", &count); // read length of uncompressed data

    while (fgetc(input_file)!= EOF) {
        fscanf(input_file, "%d%c", &count, &current_char);

        for (int i = 0; i < count; i++) {
            fprintf(output_file, "%c", current_char);
        }
    }
}

int main() {
    FILE *input_file, *output_file;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    char input_buffer[MAX_BUFFER_SIZE];
    char output_buffer[MAX_BUFFER_SIZE];

    read_file(input_file, input_buffer);

    compress_file(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    input_file = fopen("output.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open output file for reading.\n");
        return 1;
    }

    output_file = fopen("decompressed.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open decompressed file for writing.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    decompress_file(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Compression and decompression complete.\n");

    return 0;
}