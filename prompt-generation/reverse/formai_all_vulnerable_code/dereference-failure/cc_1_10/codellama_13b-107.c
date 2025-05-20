//Code Llama-13B DATASET v1.0 Category: File handling ; Style: modular
// file_handling.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Structure to store file information
typedef struct {
    char name[100];
    char data[100];
} File;

// Function to read file information
void read_file(char* file_path, File* file) {
    FILE* fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    fgets(file->name, 100, fp);
    fgets(file->data, 100, fp);
    fclose(fp);
}

// Function to write file information
void write_file(char* file_path, File* file) {
    FILE* fp = fopen(file_path, "w");
    if (fp == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    fputs(file->name, fp);
    fputs(file->data, fp);
    fclose(fp);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file_path> <file_name>\n", argv[0]);
        exit(1);
    }

    File file;
    read_file(argv[1], &file);
    printf("File name: %s\n", file.name);
    printf("File data: %s\n", file.data);

    write_file(argv[2], &file);
    printf("File written successfully!\n");

    return 0;
}