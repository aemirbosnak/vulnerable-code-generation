//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_NAME_LENGTH 1000

int main() {
    char key[MAX_KEY_LENGTH];
    char input_file_name[MAX_FILE_NAME_LENGTH];
    char output_file_name[MAX_FILE_NAME_LENGTH];

    // Prompt the user for the input file name
    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);

    // Prompt the user for the output file name
    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    // Prompt the user for the encryption key
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Open the input file
    FILE* input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Determine the size of the input file
    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    rewind(input_file);

    // Allocate memory for the input buffer
    char* input_buffer = (char*) malloc(input_file_size);
    if (input_buffer == NULL) {
        printf("Error allocating memory for input buffer.\n");
        exit(1);
    }

    // Read the input file into the input buffer
    fread(input_buffer, 1, input_file_size, input_file);
    fclose(input_file);

    // Encrypt the input buffer using the key
    for (int i = 0; i < input_file_size; i++) {
        input_buffer[i] ^= key[i % strlen(key)];
    }

    // Open the output file
    FILE* output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write the encrypted buffer to the output file
    fwrite(input_buffer, 1, input_file_size, output_file);
    fclose(output_file);

    // Free the input buffer memory
    free(input_buffer);

    printf("File encrypted and saved as %s.\n", output_file_name);

    return 0;
}