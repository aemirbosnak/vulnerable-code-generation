//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[MAX_BUFFER_SIZE], output_filename[MAX_BUFFER_SIZE];
    char input_buffer[MAX_BUFFER_SIZE], output_buffer[MAX_BUFFER_SIZE];
    int input_file_size, output_file_size;

    // get input file name from command line argument
    if (argc < 2) {
        printf("Error: Input file name required.\n");
        return 1;
    }
    strncpy(input_filename, argv[1], MAX_BUFFER_SIZE);

    // open input file for reading
    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: Input file not found.\n");
        return 1;
    }

    // get input file size
    fseek(input_file, 0, SEEK_END);
    input_file_size = ftell(input_file);
    rewind(input_file);

    // open output file for writing
    strcpy(output_filename, input_filename);
    strcat(output_filename, ".hex");
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: Output file could not be created.\n");
        fclose(input_file);
        return 1;
    }

    // write header to output file
    fprintf(output_file, ":%08X00000001FF\n", input_file_size);

    // read input file and write hex to output file
    int bytes_read, bytes_written;
    while ((bytes_read = fread(input_buffer, 1, MAX_BUFFER_SIZE, input_file)) > 0) {
        bytes_written = sprintf(output_buffer, ":%02X", *(input_buffer));
        fwrite(output_buffer, 1, bytes_written, output_file);
        output_file_size += bytes_written;
    }

    // close input and output files
    fclose(input_file);
    fclose(output_file);

    // print success message
    printf("Success: %d bytes of hex data written to %s.\n", output_file_size, output_filename);

    return 0;
}