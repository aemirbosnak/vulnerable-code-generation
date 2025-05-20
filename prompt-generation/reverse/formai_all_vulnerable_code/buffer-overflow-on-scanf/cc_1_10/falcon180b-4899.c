//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1000000 // 1 MB

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char extension[10];
    int size;
    char *data;
} File;

void read_file(const char *filename, File *file) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    file->data = malloc(file->size);
    if (file->data == NULL) {
        printf("Error: Could not allocate memory for file %s\n", filename);
        exit(1);
    }

    fread(file->data, 1, file->size, fp);
    fclose(fp);

    char *dot = strrchr(filename, '.');
    if (dot == NULL) {
        strcpy(file->extension, "unknown");
    } else {
        strcpy(file->extension, dot + 1);
    }
}

void write_file(const char *filename, const File *file) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fwrite(file->data, 1, file->size, fp);
    fclose(fp);
}

void print_file_info(const File *file) {
    printf("Name: %s\n", file->name);
    printf("Extension: %s\n", file->extension);
    printf("Size: %d bytes\n", file->size);
}

int main() {
    File file;
    char input_filename[MAX_FILE_NAME_LENGTH];
    char output_filename[MAX_FILE_NAME_LENGTH];

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    read_file(input_filename, &file);

    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    write_file(output_filename, &file);

    printf("File recovery successful!\n");

    return 0;
}