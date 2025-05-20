//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

char* read_file(FILE* file) {
    char* buffer = NULL;
    size_t size = 0;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    buffer = malloc(size + 1);
    if (buffer == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    fread(buffer, size, 1, file);
    buffer[size] = '\0';

    return buffer;
}

void write_file(FILE* file, const char* buffer) {
    int bytes_written = 0;

    while (bytes_written < strlen(buffer)) {
        bytes_written += fwrite(buffer + bytes_written, 1, strlen(buffer) - bytes_written, file);
    }
}

int main() {
    char* source_file_path = "source_file.txt";
    char* destination_file_path = "backup_file.txt";

    FILE* source_file = fopen(source_file_path, "r");
    if (source_file == NULL) {
        printf("Error: Could not open source file.\n");
        exit(1);
    }

    char* file_contents = read_file(source_file);

    FILE* destination_file = fopen(destination_file_path, "w");
    if (destination_file == NULL) {
        printf("Error: Could not open destination file.\n");
        exit(1);
    }

    write_file(destination_file, file_contents);

    fclose(source_file);
    fclose(destination_file);

    printf("File backup successful!\n");

    return 0;
}