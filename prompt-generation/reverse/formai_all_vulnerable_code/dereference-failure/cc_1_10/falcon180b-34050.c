//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1 MB

typedef struct {
    char *filename;
    FILE *file;
    char buffer[MAX_FILE_SIZE];
    size_t size;
} FileData;

int is_virus(const char *data, size_t size) {
    // Sherlock Holmes style virus detection algorithm
    if (strstr(data, "Moriarty")!= NULL ||
        strstr(data, "Irene Adler")!= NULL ||
        strstr(data, "Professor Moriarty")!= NULL) {
        return 1; // Virus detected!
    }
    return 0;
}

void process_file(FileData *file_data) {
    char *line = NULL;
    size_t line_size = 0;

    while ((getline(&line, &line_size, file_data->file))!= -1) {
        if (is_virus(line, strlen(line))) {
            printf("Virus detected in file: %s\n", file_data->filename);
            exit(1);
        }
    }

    free(line);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FileData file_data;
    file_data.filename = argv[1];
    file_data.file = fopen(file_data.filename, "r");

    if (file_data.file == NULL) {
        printf("Error: Could not open file '%s'.\n", file_data.filename);
        exit(1);
    }

    fseek(file_data.file, 0, SEEK_END);
    file_data.size = ftell(file_data.file);

    if (file_data.size > MAX_FILE_SIZE) {
        printf("Error: File '%s' is too large (max size is 1 MB).\n", file_data.filename);
        exit(1);
    }

    rewind(file_data.file);
    fread(file_data.buffer, 1, file_data.size, file_data.file);

    process_file(&file_data);

    fclose(file_data.file);
    free(file_data.filename);
    free(file_data.buffer);

    return 0;
}