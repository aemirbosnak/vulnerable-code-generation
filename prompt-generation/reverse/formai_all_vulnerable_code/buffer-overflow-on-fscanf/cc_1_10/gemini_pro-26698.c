//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024

typedef struct {
    char name[256];
    char contents[MAX_FILE_SIZE];
    size_t size;
    time_t modified;
} File;

File files[MAX_FILES];
int num_files = 0;

void add_file(char *name, char *contents, size_t size, time_t modified) {
    if (num_files >= MAX_FILES) {
        printf("Error: Too many files.\n");
        return;
    }

    strcpy(files[num_files].name, name);
    strcpy(files[num_files].contents, contents);
    files[num_files].size = size;
    files[num_files].modified = modified;

    num_files++;
}

void print_files() {
    for (int i = 0; i < num_files; i++) {
        printf("%s (%lu bytes, modified %s)\n", files[i].name, files[i].size, ctime(&files[i].modified));
    }
}

void backup_files() {
    FILE *fp = fopen("backup.txt", "w");
    if (fp == NULL) {
        printf("Error: Could not open backup file.\n");
        return;
    }

    for (int i = 0; i < num_files; i++) {
        fprintf(fp, "%s\n", files[i].name);
        fprintf(fp, "%lu\n", files[i].size);
        fprintf(fp, "%s\n", files[i].contents);
        fprintf(fp, "%ld\n", files[i].modified);
    }

    fclose(fp);
}

void restore_files() {
    FILE *fp = fopen("backup.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open backup file.\n");
        return;
    }

    char name[256];
    size_t size;
    char contents[MAX_FILE_SIZE];
    time_t modified;

    while (fscanf(fp, "%s\n%lu\n%s\n%ld\n", name, &size, contents, &modified) != EOF) {
        add_file(name, contents, size, modified);
    }

    fclose(fp);
}

int main() {
    add_file("file1.txt", "Hello, world!", 13, time(NULL));
    add_file("file2.txt", "This is a test.", 15, time(NULL));

    print_files();

    backup_files();

    restore_files();

    print_files();

    return 0;
}