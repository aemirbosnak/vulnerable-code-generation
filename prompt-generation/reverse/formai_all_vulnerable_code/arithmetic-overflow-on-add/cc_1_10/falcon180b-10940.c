//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char filename[100];
    char backup_filename[100];
    int size;
} File;

void create_backup_filename(char* filename, char* backup_filename) {
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    char* source_file = argv[1];
    char* dest_file = argv[2];

    FILE* fp = fopen(source_file, "r");
    if (fp == NULL) {
        printf("Error: could not open source file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* buffer = malloc(size + 1);
    if (buffer == NULL) {
        printf("Error: could not allocate memory for buffer.\n");
        fclose(fp);
        return 1;
    }

    int bytes_read = fread(buffer, 1, size, fp);
    if (bytes_read!= size) {
        printf("Error: could not read entire source file.\n");
        free(buffer);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    File file;
    strcpy(file.filename, source_file);
    strcpy(file.backup_filename, dest_file);
    file.size = size;

    FILE* backup_fp = fopen(file.backup_filename, "w");
    if (backup_fp == NULL) {
        printf("Error: could not open backup file.\n");
        free(buffer);
        return 1;
    }

    int bytes_written = fwrite(buffer, 1, size, backup_fp);
    if (bytes_written!= size) {
        printf("Error: could not write entire backup file.\n");
        fclose(backup_fp);
        free(buffer);
        return 1;
    }

    fclose(backup_fp);
    free(buffer);

    printf("Backup created successfully!\n");

    return 0;
}