//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    time_t last_backup_time;
} File;

void print_file(const File *file) {
    printf("%s (%ld)\n", file->name, file->last_backup_time);
}

int compare_files(const void *a, const void *b) {
    const File *file1 = a;
    const File *file2 = b;

    if (file1->last_backup_time < file2->last_backup_time) {
        return 1;
    } else if (file1->last_backup_time > file2->last_backup_time) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    File files[MAX_FILES];
    int num_files = 0;

    printf("Enter file names to backup (up to %d files):\n", MAX_FILES - 1);

    while (num_files < MAX_FILES && scanf("%s", files[num_files].name)!= EOF) {
        num_files++;
    }

    printf("Files to backup:\n");

    for (int i = 0; i < num_files; i++) {
        printf("%s\n", files[i].name);
    }

    qsort(files, num_files, sizeof(File), compare_files);

    for (int i = 0; i < num_files; i++) {
        printf("Last backup time: %s\n", ctime(&files[i].last_backup_time));
    }

    return 0;
}