//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size in bytes

// Function prototypes
void backupFile(char *filename);
int isValidFilename(char *filename);
int getFileSize(FILE *fp);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <backup_folder>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    char *backup_folder = argv[2];

    if (!isValidFilename(filename)) {
        printf("Invalid filename.\n");
        exit(1);
    }

    backupFile(filename);

    return 0;
}

void backupFile(char *filename) {
    char *backup_filename = malloc(strlen(filename) + 10);
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    int file_size = getFileSize(fp);
    char *file_buffer = malloc(file_size);

    fseek(fp, 0, SEEK_SET);
    fread(file_buffer, file_size, 1, fp);

    fclose(fp);

    fp = fopen(backup_filename, "wb");
    if (fp == NULL) {
        printf("Error creating backup file %s\n", backup_filename);
        exit(1);
    }

    fwrite(file_buffer, file_size, 1, fp);

    fclose(fp);

    printf("Backup of %s created: %s\n", filename, backup_filename);
}

int isValidFilename(char *filename) {
    int len = strlen(filename);
    if (len == 0) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (!isalnum(filename[i]) && filename[i]!= '.' && filename[i]!= '_') {
            return 0;
        }
    }

    return 1;
}

int getFileSize(FILE *fp) {
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);

    return file_size;
}