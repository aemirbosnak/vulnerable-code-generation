//FormAI DATASET v1.0 Category: File Backup System ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILES 10    // Maximum number of files to backup
#define MAX_FILENAME 20 // Maximum characters for filename
#define MAX_DIR 100     // Maximum characters for directory path

typedef struct {
    char name[MAX_FILENAME];
    int size;
} File;

typedef struct {
    char directory[MAX_DIR];
    int num_files;
    File files[MAX_FILES];
} Backup;

int main() {
    Backup b;
    int i;

    printf("Enter the directory path for backup:\n");
    scanf("%s", b.directory);

    printf("Enter the number of files to backup (1-%d):\n", MAX_FILES);
    scanf("%d", &b.num_files);

    for (i = 0; i < b.num_files; i++) {
        printf("Enter name of file %d:\n", i+1);
        scanf("%s", b.files[i].name);
        printf("Enter size of file %d in bytes:\n", i+1);
        scanf("%d", &b.files[i].size);
    }

    // Open backup file and write data
    FILE *backup_file;
    backup_file = fopen("backup.dat", "wb");
    fwrite(&b, sizeof(b), 1, backup_file);
    fclose(backup_file);

    // Read backup file and print data
    Backup b_read;
    backup_file = fopen("backup.dat", "rb");
    fread(&b_read, sizeof(b_read), 1, backup_file);
    fclose(backup_file);

    printf("\nBackup Saved:\n");
    printf("Directory: %s\n", b_read.directory);
    printf("Number of Files: %d\n", b_read.num_files);
    for (i = 0; i < b_read.num_files; i++) {
        printf("File %d Name: %s, Size: %d bytes\n", i+1, b_read.files[i].name, b_read.files[i].size);
    }

    return 0;
}