//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_FILE_SIZE 20971520 // 20MB
#define MAX_FILE_NAME 255
#define TRUE 1
#define FALSE 0

typedef int BOOL;

BOOL recover_data(const char* filename);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (recover_data(argv[1])) {
        printf("File successfully recovered!\n");
    } else {
        printf("Failed to recover file.\n");
    }

    return 0;
}

BOOL recover_data(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file.\n");
        return FALSE;
    }

    char current_filename[MAX_FILE_NAME + 1];
    unsigned char buffer[BLOCK_SIZE];
    unsigned long long bytes_read = 0;

    FILE* output_file = NULL;
    BOOL first_block = TRUE;
    BOOL recovery_started = FALSE;

    while (!feof(file) && bytes_read < MAX_FILE_SIZE) {
        size_t bytes_read_current_block = fread(buffer, 1, BLOCK_SIZE, file);
        bytes_read += bytes_read_current_block;

        if (bytes_read_current_block != BLOCK_SIZE && !feof(file)) {
            printf("Unexpected end of block. Aborting.\n");
            fclose(file);
            return FALSE;
        }

        // Check if block is the start of a new file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe0 &&
            buffer[6] == 'J' && buffer[7] == 'F' && buffer[8] == 'I' && buffer[9] == 'F') {

            // Close previously opened output file, if any
            if (output_file) {
                fclose(output_file);
            }

            // Extract filename from header
            int current_file_offset = 0;
            while (buffer[10 + current_file_offset]) {
                current_filename[current_file_offset] = buffer[10 + current_file_offset];
                current_file_offset++;
            }
            current_filename[current_file_offset] = '\0';

            if (strlen(current_filename) == 0) {
                printf("Unexpected end of filename. Aborting.\n");
                fclose(file);
                return FALSE;
            }

            // Open new output file
            output_file = fopen(current_filename, "w");
            if (!output_file) {
                printf("Failed to create output file: '%s'. Aborting.\n", current_filename);
                fclose(file);
                return FALSE;
            }

            // Write current block to output file
            fwrite(buffer, 1, bytes_read_current_block, output_file);
            first_block = FALSE;
            recovery_started = TRUE;

        } else if (!first_block) {
            // Write current block to output file
            fwrite(buffer, 1, bytes_read_current_block, output_file);
            recovery_started = TRUE;
        }
    }

    fclose(file);

    if (!recovery_started) {
        printf("No data found for recovery.\n");
        return FALSE;
    }

    return TRUE;
}