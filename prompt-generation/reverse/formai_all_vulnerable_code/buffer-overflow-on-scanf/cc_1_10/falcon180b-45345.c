//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILES 100

struct file {
    char name[100];
    int size;
    char path[200];
};

void *backup_thread(void *arg) {
    struct file *file = (struct file *) arg;
    char backup_path[200];
    strcpy(backup_path, file->path);
    strcat(backup_path, ".bak");

    FILE *fp = fopen(backup_path, "wb");
    if (fp == NULL) {
        printf("Error: Unable to create backup file %s\n", backup_path);
        exit(1);
    }

    FILE *fp_orig = fopen(file->path, "rb");
    if (fp_orig == NULL) {
        printf("Error: Unable to open original file %s\n", file->path);
        exit(1);
    }

    char buffer[1024];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, 1024, fp_orig)) > 0) {
        fwrite(buffer, 1, bytes_read, fp);
    }

    fclose(fp);
    fclose(fp_orig);

    printf("Backup of file %s created successfully\n", file->name);

    return NULL;
}

int main() {
    pthread_t threads[MAX_FILES];
    struct file files[MAX_FILES];

    int num_files = 0;

    printf("Enter the number of files to backup (maximum %d): ", MAX_FILES);
    scanf("%d", &num_files);

    for (int i = 0; i < num_files; i++) {
        printf("Enter the name of file %d: ", i+1);
        scanf("%s", files[i].name);
        printf("Enter the size of file %s: ", files[i].name);
        scanf("%d", &files[i].size);
        printf("Enter the path of file %s: ", files[i].name);
        scanf("%s", files[i].path);
    }

    for (int i = 0; i < num_files; i++) {
        pthread_create(&threads[i], NULL, backup_thread, (void *) &files[i]);
    }

    for (int i = 0; i < num_files; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}