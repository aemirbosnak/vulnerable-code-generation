//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *filename;
    int filesize;
    FILE *file;
} FileInfo;

void read_file(FileInfo *file_info) {
    char buffer[BUFFER_SIZE];
    int bytes_read;
    int i = 0;
    FILE *fp = file_info->file;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, fp))!= 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
        i += bytes_read;
    }

    printf("\nTotal bytes read: %d\n", i);
}

int main() {
    char filename[100];
    FILE *fp;
    int filesize;

    printf("Enter the name of the file to be recovered: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("File not found.\n");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    printf("File size: %d bytes\n", filesize);

    FileInfo file_info;
    file_info.filename = filename;
    file_info.filesize = filesize;
    file_info.file = fp;

    read_file(&file_info);

    fclose(fp);

    return 0;
}