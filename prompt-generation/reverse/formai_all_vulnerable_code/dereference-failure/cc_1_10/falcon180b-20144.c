//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 1024

typedef struct {
    char name[MAX_PATH];
    char backup_name[MAX_PATH];
} File;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char *file_path = argv[1];
    File file;

    strcpy(file.name, file_path);

    // Get the file extension
    char *ext = strrchr(file.name, '.');
    if (ext == NULL) {
        printf("Invalid file extension.\n");
        return 1;
    }

    // Backup file name
    strcpy(file.backup_name, file.name);
    strcat(file.backup_name, ".bak");

    // Open the file for reading
    FILE *fp = fopen(file.name, "rb");
    if (fp == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    // Create the backup file
    FILE *bkp_fp = fopen(file.backup_name, "wb");
    if (bkp_fp == NULL) {
        printf("Could not create backup file.\n");
        fclose(fp);
        return 1;
    }

    // Copy the contents of the original file to the backup file
    char buffer[1024];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, 1024, fp)) > 0) {
        fwrite(buffer, 1, bytes_read, bkp_fp);
    }

    // Close the files
    fclose(fp);
    fclose(bkp_fp);

    printf("Backup created successfully.\n");

    return 0;
}