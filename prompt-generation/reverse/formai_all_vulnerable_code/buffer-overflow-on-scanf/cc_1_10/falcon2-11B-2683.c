//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100
#define MAX_FILE_NAME_LEN 100
#define MAX_BUF_SIZE 1000

typedef struct {
    char filename[MAX_FILE_NAME_LEN];
    char buffer[MAX_BUF_SIZE];
    int read_offset;
    int write_offset;
    int file_size;
} file_info;

int main() {
    file_info file_data;
    char filename[MAX_FILE_NAME_LEN];
    char* buffer;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file_data.filename[0] = '\0';
    strcpy(file_data.filename, filename);

    file_data.read_offset = 0;
    file_data.write_offset = 0;
    file_data.file_size = 0;

    FILE* fp = fopen(filename, "r+b");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    buffer = malloc(MAX_BUF_SIZE);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        fclose(fp);
        return 1;
    }

    while (fread(buffer, sizeof(char), MAX_BUF_SIZE, fp) > 0) {
        if (file_data.write_offset + MAX_BUF_SIZE > file_data.file_size) {
            fwrite(buffer, sizeof(char), MAX_BUF_SIZE, fp);
            file_data.file_size += MAX_BUF_SIZE;
        } else {
            fwrite(buffer, sizeof(char), MAX_BUF_SIZE, fp);
            file_data.write_offset += MAX_BUF_SIZE;
        }
    }

    fclose(fp);
    free(buffer);

    return 0;
}