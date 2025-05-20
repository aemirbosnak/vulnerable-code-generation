//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size to recover

// Function to read the contents of a file into a buffer
void read_file(FILE *file, char *buffer) {
    fseek(file, 0, SEEK_SET); // Move the file pointer to the beginning of the file
    fread(buffer, 1, MAX_FILE_SIZE, file); // Read up to MAX_FILE_SIZE bytes into the buffer
    buffer[MAX_FILE_SIZE] = '\0'; // Null terminate the buffer to ensure it's a string
}

// Function to write the contents of a buffer to a file
void write_file(FILE *file, char *buffer) {
    fwrite(buffer, strlen(buffer), 1, file); // Write the contents of the buffer to the file
}

// Function to recover a deleted file
void recover_file(char *filename) {
    FILE *input_file, *output_file;
    char buffer[MAX_FILE_SIZE];

    // Open the input file for reading
    input_file = fopen(filename, "rb");
    if (input_file == NULL) {
        printf("Error: Input file not found.\n");
        return;
    }

    // Open the output file for writing
    output_file = fopen("recovered.txt", "wb");
    if (output_file == NULL) {
        printf("Error: Output file could not be created.\n");
        fclose(input_file);
        return;
    }

    // Read the contents of the input file into a buffer
    read_file(input_file, buffer);

    // Write the contents of the buffer to the output file
    write_file(output_file, buffer);

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File successfully recovered!\n");
}

int main() {
    char filename[100];

    // Get the name of the deleted file from the user
    printf("Enter the name of the deleted file: ");
    scanf("%s", filename);

    // Recover the deleted file
    recover_file(filename);

    return 0;
}