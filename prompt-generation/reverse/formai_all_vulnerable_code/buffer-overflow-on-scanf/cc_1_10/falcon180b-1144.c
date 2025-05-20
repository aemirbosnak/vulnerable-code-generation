//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 100

struct file_info {
    char filename[MAX_FILE_NAME_LENGTH];
    time_t backup_time;
};

void backup_file(char *filename) {
    char backup_filename[MAX_FILE_NAME_LENGTH];
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");

    FILE *backup_file = fopen(backup_filename, "wb");
    if (backup_file == NULL) {
        printf("Error: Failed to create backup file %s\n", backup_filename);
        exit(1);
    }

    FILE *original_file = fopen(filename, "rb");
    if (original_file == NULL) {
        printf("Error: Failed to open original file %s\n", filename);
        exit(1);
    }

    char buffer[1024];
    while (fread(buffer, 1, 1024, original_file) > 0) {
        fwrite(buffer, 1, 1024, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);

    printf("Backup created for file %s\n", filename);
}

int compare_backup_times(const void *a, const void *b) {
    const struct file_info *file_a = a;
    const struct file_info *file_b = b;

    return difftime(file_a->backup_time, file_b->backup_time);
}

int main() {
    int num_files = 0;
    struct file_info files[MAX_FILES];

    printf("Enter the names of the files to backup (up to %d):\n", MAX_FILES);
    while (num_files < MAX_FILES && scanf("%s", files[num_files].filename)!= EOF) {
        num_files++;
    }

    for (int i = 0; i < num_files; i++) {
        backup_file(files[i].filename);
        files[i].backup_time = time(NULL);
    }

    qsort(files, num_files, sizeof(struct file_info), compare_backup_times);

    printf("Files sorted by backup time:\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s: %s\n", files[i].filename, ctime(&files[i].backup_time));
    }

    return 0;
}