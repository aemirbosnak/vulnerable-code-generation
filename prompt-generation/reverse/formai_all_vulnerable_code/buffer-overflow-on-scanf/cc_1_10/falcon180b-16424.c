//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_content[MAX_FILE_SIZE];
    int file_size;
} File;

void create_file(File *file, char *file_name) {
    strcpy(file->file_name, file_name);
    file->file_size = 0;
    file->file_content[0] = '\0';
}

void open_file(File *file, char *file_name) {
    strcpy(file->file_name, file_name);
    file->file_size = 0;
}

void close_file(File *file) {
    if (file->file_size == 0) {
        printf("Error: File is empty.\n");
        return;
    }

    printf("File closed successfully.\n");
}

void write_to_file(File *file, char *content) {
    int content_length = strlen(content);

    if (file->file_size + content_length > MAX_FILE_SIZE) {
        printf("Error: File is full.\n");
        return;
    }

    strcat(file->file_content, content);
    file->file_size += content_length;
}

void read_from_file(File *file, char *buffer, int buffer_size) {
    int content_length = file->file_size;

    if (content_length == 0) {
        printf("Error: File is empty.\n");
        return;
    }

    if (content_length > buffer_size) {
        printf("Error: Buffer is too small.\n");
        return;
    }

    strncpy(buffer, file->file_content, buffer_size);
}

int main() {
    File file;
    char file_name[MAX_FILE_NAME_LENGTH];
    char content[MAX_FILE_SIZE];
    char read_buffer[MAX_FILE_SIZE];

    printf("Enter file name: ");
    scanf("%s", file_name);

    create_file(&file, file_name);

    printf("Enter file content: ");
    scanf("%s", content);

    write_to_file(&file, content);

    printf("File content: ");
    read_from_file(&file, read_buffer, MAX_FILE_SIZE);
    printf("%s\n", read_buffer);

    close_file(&file);

    return 0;
}