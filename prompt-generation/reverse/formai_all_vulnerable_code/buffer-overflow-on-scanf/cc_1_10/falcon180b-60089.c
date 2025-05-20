//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 1000
#define MAX_FILE_SIZE 1000000
#define BUFFER_SIZE 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    char *file_data;
} File;

void backup_file(char *file_name) {
    FILE *fp;
    File file;
    char *buffer;

    strcpy(file.file_name, file_name);
    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    file.file_size = ftell(fp);
    rewind(fp);
    file.file_data = (char *) malloc(file.file_size);
    if (file.file_data == NULL) {
        printf("Error: Could not allocate memory for file %s\n", file_name);
        exit(1);
    }
    buffer = (char *) malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Error: Could not allocate memory for buffer\n");
        exit(1);
    }
    while (fread(buffer, 1, BUFFER_SIZE, fp) > 0) {
        memcpy(file.file_data + ftell(fp), buffer, BUFFER_SIZE);
    }
    fclose(fp);
    printf("File %s backed up successfully\n", file_name);
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the file to backup: ");
    scanf("%s", file_name);
    backup_file(file_name);
    return 0;
}