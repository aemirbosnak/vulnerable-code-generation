//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of input file

typedef struct {
    char file_name[100]; // file name
    int file_size; // file size
    char *data; // file data
} File;

File *read_file(char *file_name) {
    FILE *fp;
    File *file = malloc(sizeof(File));

    if (file == NULL) {
        printf("Memory error!\n");
        exit(1);
    }

    strcpy(file->file_name, file_name);

    if ((fp = fopen(file_name, "rb")) == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    file->file_size = ftell(fp);
    rewind(fp);

    if (file->file_size > MAX_SIZE) {
        printf("File is too large!\n");
        exit(1);
    }

    file->data = malloc(file->file_size + 1);

    if (file->data == NULL) {
        printf("Memory error!\n");
        exit(1);
    }

    fread(file->data, file->file_size, 1, fp);
    file->data[file->file_size] = '\0';

    fclose(fp);

    return file;
}

void write_file(File *file) {
    FILE *fp;

    if ((fp = fopen(file->file_name, "wb")) == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    fwrite(file->data, file->file_size, 1, fp);

    fclose(fp);
}

int main() {
    char file_name[100];
    printf("Enter the name of the file to recover: ");
    scanf("%s", file_name);

    File *file = read_file(file_name);

    if (file == NULL) {
        return 1;
    }

    printf("File name: %s\n", file->file_name);
    printf("File size: %d bytes\n", file->file_size);

    write_file(file);

    printf("File recovery completed successfully!\n");

    return 0;
}