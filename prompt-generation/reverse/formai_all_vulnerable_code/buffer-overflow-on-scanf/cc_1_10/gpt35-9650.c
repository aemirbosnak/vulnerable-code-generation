//FormAI DATASET v1.0 Category: Data recovery tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512 // Block size for data recovery

void recover_data(char* file_name) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    char buffer[BLOCK_SIZE]; // Recovery buffer
    FILE* output_file = NULL; // Output file
    int counter = 0; // Counter for numbering files

    while (fread(buffer, BLOCK_SIZE, 1, file)) {
        // Check if block is not empty
        if (buffer[0] != 0 && buffer[1] != 0) {
            // Ensure file name is valid
            char file_name[strlen(file_name) + 10];
            sprintf(file_name, "%s_%d", file_name, counter++);

            // Create new output file
            output_file = fopen(file_name, "wb");
            if (output_file == NULL) {
                printf("Unable to create file %s.\n", file_name);
                return;
            }

            // Write data to output file
            int bytes_written = fwrite(buffer, 1, BLOCK_SIZE, output_file);
            if (bytes_written != BLOCK_SIZE) {
                printf("Error writing to file %s.\n", file_name);
                fclose(output_file);
                return;
            }

            fclose(output_file);
        }
    }

    fclose(file);
}

int main() {
    char file_name[100];
    printf("Enter file name: ");
    scanf("%s", file_name);

    recover_data(file_name);

    printf("Data recovery complete.\n");
    return 0;
}