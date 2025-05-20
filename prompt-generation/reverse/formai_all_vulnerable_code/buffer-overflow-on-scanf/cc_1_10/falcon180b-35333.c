//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // 1 MB
#define BUFFER_SIZE 1024 // 1 KB

typedef struct {
    char filename[100];
    char backup_filename[100];
    int file_size;
    FILE *file;
    FILE *backup_file;
} file_info;

void backup_file(file_info *file_info) {
    char buffer[BUFFER_SIZE];
    int bytes_read;
    file_info->backup_file = fopen(file_info->backup_filename, "wb");
    if (file_info->backup_file == NULL) {
        printf("Error: Could not create backup file.\n");
        exit(1);
    }
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file_info->file)) > 0) {
        fwrite(buffer, 1, bytes_read, file_info->backup_file);
    }
    fclose(file_info->backup_file);
}

int main() {
    int num_files;
    printf("Enter the number of files to backup: ");
    scanf("%d", &num_files);
    file_info *files = malloc(num_files * sizeof(file_info));
    if (files == NULL) {
        printf("Error: Could not allocate memory for file info.\n");
        exit(1);
    }
    for (int i = 0; i < num_files; i++) {
        printf("Enter the filename for file %d: ", i+1);
        scanf("%s", files[i].filename);
        strcpy(files[i].backup_filename, "backup_");
        strcat(files[i].backup_filename, files[i].filename);
        strcat(files[i].backup_filename, ".bak");
        files[i].file = fopen(files[i].filename, "rb");
        if (files[i].file == NULL) {
            printf("Error: Could not open file %s.\n", files[i].filename);
            exit(1);
        }
        fseek(files[i].file, 0, SEEK_END);
        files[i].file_size = ftell(files[i].file);
        if (files[i].file_size > MAX_FILE_SIZE) {
            printf("Error: File %s is too large to backup (max size is 1 MB).\n", files[i].filename);
            exit(1);
        }
        rewind(files[i].file);
    }
    printf("Enter the destination directory for backups: ");
    scanf("%s", files[0].backup_filename);
    for (int i = 0; i < num_files; i++) {
        backup_file(&files[i]);
    }
    for (int i = 0; i < num_files; i++) {
        fclose(files[i].file);
        fclose(files[i].backup_file);
    }
    free(files);
    return 0;
}