//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *filename;
    char *backup_filename;
} file_t;

void backup_file(file_t *file) {
    char *backup_path = malloc(strlen(file->backup_filename) + 1);
    strcpy(backup_path, file->backup_filename);
    strcat(backup_path, ".bak");

    FILE *fp = fopen(file->filename, "r");
    if (fp == NULL) {
        printf("Error: File not found - %s\n", file->filename);
        exit(1);
    }

    FILE *backup_fp = fopen(backup_path, "w");
    if (backup_fp == NULL) {
        printf("Error: Could not create backup file - %s\n", backup_path);
        exit(1);
    }

    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        fputc(ch, backup_fp);
    }

    fclose(fp);
    fclose(backup_fp);
    free(backup_path);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <filename> <backup_filename>\n", argv[0]);
        exit(1);
    }

    file_t *file = malloc(sizeof(file_t));
    file->filename = argv[1];
    file->backup_filename = argv[2];

    backup_file(file);

    printf("Backup completed successfully!\n");
    return 0;
}