//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_FILE_SIZE 1000000 // 1MB
#define VIRUS_SIGNATURE "virus"
#define VIRUS_FOUND 1
#define FILE_CLEAN 0
#define FILE_INFECTED 1

typedef struct {
    char *filename;
    FILE *file;
    char *buffer;
    size_t filesize;
    int filesignature;
} file_t;

int is_infected(file_t *file) {
    char *pos = strstr(file->buffer, VIRUS_SIGNATURE);
    if (pos!= NULL) {
        return VIRUS_FOUND;
    }
    return FILE_CLEAN;
}

void scan_file(char *filename) {
    file_t file;
    file.filename = filename;
    file.file = fopen(filename, "rb");
    if (file.file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    fseek(file.file, 0, SEEK_END);
    file.filesize = ftell(file.file);
    if (file.filesize > MAX_FILE_SIZE) {
        printf("Error: File %s is too large (%lu bytes)\n", filename, file.filesize);
        fclose(file.file);
        return;
    }

    rewind(file.file);
    file.buffer = malloc(file.filesize + 1);
    if (file.buffer == NULL) {
        printf("Error: Could not allocate memory for file %s\n", filename);
        fclose(file.file);
        return;
    }

    fread(file.buffer, 1, file.filesize, file.file);
    file.buffer[file.filesize] = '\0';

    int result = is_infected(&file);
    if (result == VIRUS_FOUND) {
        printf("Virus found in file %s\n", filename);
    } else {
        printf("File %s is clean\n", filename);
    }

    fclose(file.file);
    free(file.buffer);
}

int main(int argc, char **argv) {
    time_t start_time = time(NULL);

    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    scan_file(argv[1]);

    time_t end_time = time(NULL);
    printf("Scan completed in %ld seconds\n", end_time - start_time);

    return 0;
}