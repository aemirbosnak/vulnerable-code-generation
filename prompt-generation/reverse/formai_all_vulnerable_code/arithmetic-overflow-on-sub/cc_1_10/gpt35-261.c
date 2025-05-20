//FormAI DATASET v1.0 Category: File Backup System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 1000
#define FILENAME_LENGTH 100

typedef struct File {
    char* name;
    time_t last_modified;
} File;

File files[MAX_FILES];
int num_files = 0;

void add_file(char* name, time_t last_modified) {
    if (num_files >= MAX_FILES) {
        printf("Error: maximum number of files reached.\n");
        return;
    }
    files[num_files].name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(files[num_files].name, name);
    files[num_files].last_modified = last_modified;
    num_files++;
}

void backup_files() {
    FILE* backup_file = fopen("backup.txt", "w");
    if (backup_file == NULL) {
        printf("Error: could not open backup file.\n");
        return;
    }
    for (int i = 0; i < num_files; i++) {
        fprintf(backup_file, "%s,%ld\n", files[i].name, files[i].last_modified);
    }
    fclose(backup_file);
}

void restore_files() {
    FILE* backup_file = fopen("backup.txt", "r");
    if (backup_file == NULL) {
        printf("Error: could not open backup file.\n");
        return;
    }
    char buffer[FILENAME_LENGTH + 20];
    while (fgets(buffer, FILENAME_LENGTH + 20, backup_file) != NULL) {
        char* name = strtok(buffer, ",");
        time_t last_modified = atol(strtok(NULL, ","));
        add_file(name, last_modified);
    }
    fclose(backup_file);
}

int main() {
    add_file("file1.txt", time(NULL) - 1000);
    add_file("file2.txt", time(NULL) - 2000);
    add_file("file3.txt", time(NULL) - 3000);
    backup_files();
    num_files = 0;
    restore_files();
    for (int i = 0; i < num_files; i++) {
        printf("%s %ld\n", files[i].name, files[i].last_modified);
    }
    return 0;
}