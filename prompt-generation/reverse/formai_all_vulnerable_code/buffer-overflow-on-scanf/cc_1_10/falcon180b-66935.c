//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 256

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    time_t timestamp;
} FileInfo;

void backup_file(const char* src_file, const char* dest_dir)
{
    char dest_file[MAX_FILE_NAME_LEN];
    strcpy(dest_file, dest_dir);
    strcat(dest_file, "/");
    strcat(dest_file, src_file);

    FILE* src_fp = fopen(src_file, "rb");
    if (src_fp == NULL) {
        printf("Error opening source file: %s\n", src_file);
        return;
    }

    FILE* dest_fp = fopen(dest_file, "wb");
    if (dest_fp == NULL) {
        printf("Error opening destination file: %s\n", dest_file);
        fclose(src_fp);
        return;
    }

    char buffer[1024];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_fp)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_fp);
    }

    fclose(src_fp);
    fclose(dest_fp);

    printf("File backed up: %s\n", dest_file);
}

int main()
{
    char src_file[MAX_FILE_NAME_LEN];
    char dest_dir[MAX_FILE_NAME_LEN];

    printf("Enter source file name: ");
    scanf("%s", src_file);

    printf("Enter destination directory: ");
    scanf("%s", dest_dir);

    if (mkdir(dest_dir, 0777)!= 0) {
        printf("Error creating destination directory: %s\n", dest_dir);
        return 1;
    }

    backup_file(src_file, dest_dir);

    return 0;
}