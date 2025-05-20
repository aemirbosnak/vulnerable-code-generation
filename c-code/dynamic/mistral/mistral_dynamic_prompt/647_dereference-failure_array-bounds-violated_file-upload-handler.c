#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define MAX_FILES 10

void read_file(char* file_path) {
    FILE* file = fopen(file_path, "r");
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    if (file) {
        while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
            printf("File Content:\n");
            for (size_t i = 0; i < bytes_read; ++i) {
                printf("%c", buffer[i]);
            }

            // Vulnerable section: Hardcoded maximum number of files.
            static int file_count = 0;
            if (file_count == MAX_FILES) {
                printf("Maximum number of files reached. Aborting file processing.\n");
                break;
            }
            // Attempt to write the content of the file into an array, violating array bounds when MAX_FILES is reached.
            int* files[MAX_FILES];
            files[file_count] = malloc(bytes_read);
            memcpy(files[file_count], buffer, bytes_read);
            ++file_count;
        }
        fclose(file);
    } else {
        printf("Error opening file: %s\n", file_path);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    read_file(argv[1]);
    return 0;
}
