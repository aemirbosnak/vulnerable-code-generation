//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000
#define KEY_SIZE 16

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    char *input_buffer, *output_buffer;
    long int input_file_size;
    int i, j;

    printf("Enter input file name: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    fseek(input_file, 0, SEEK_END);
    input_file_size = ftell(input_file);
    rewind(input_file);

    input_buffer = (char *) malloc(input_file_size);
    if (input_buffer == NULL) {
        printf("Error: Could not allocate memory for input buffer.\n");
        exit(1);
    }

    input_file_size = fread(input_buffer, 1, input_file_size, input_file);
    fclose(input_file);

    printf("Enter output file name: ");
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    output_buffer = (char *) malloc(input_file_size + KEY_SIZE);
    if (output_buffer == NULL) {
        printf("Error: Could not allocate memory for output buffer.\n");
        exit(1);
    }

    for (i = 0; i < input_file_size; i++) {
        output_buffer[i] = input_buffer[i] ^ 0xAA;
    }

    for (i = 0; i < KEY_SIZE; i++) {
        output_buffer[input_file_size + i] = rand() % 256;
    }

    fwrite(output_buffer, 1, input_file_size + KEY_SIZE, output_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}