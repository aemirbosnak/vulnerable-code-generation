//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_CONTENT_LENGTH 1024 * 1024 * 10 // 10 MB

typedef struct {
    char *file_name;
    char *file_content;
    size_t file_content_length;
} File;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", file_name);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    if (file_size == 0) {
        printf("Error: File '%s' is empty.\n", file_name);
        fclose(fp);
        return 1;
    }

    char *file_content = malloc(file_size + 1);
    if (file_content == NULL) {
        printf("Error: Could not allocate memory for file content.\n");
        fclose(fp);
        return 1;
    }

    size_t bytes_read = fread(file_content, 1, file_size, fp);
    if (bytes_read!= file_size) {
        printf("Error: Could not read file content.\n");
        free(file_content);
        fclose(fp);
        return 1;
    }

    file_content[file_size] = '\0'; // Add null terminator

    File file = {
       .file_name = strdup(file_name),
       .file_content = file_content,
       .file_content_length = file_size
    };

    fclose(fp);

    printf("File name: %s\n", file.file_name);
    printf("File content length: %zu bytes\n", file.file_content_length);

    return 0;
}