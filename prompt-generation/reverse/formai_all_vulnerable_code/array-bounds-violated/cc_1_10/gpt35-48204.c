//FormAI DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 255

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char content[1024];
} File;

typedef struct {
    File* files;
    int num_files;
} Directory;

void save_file(const char* filename, const char* content) {
    FILE* fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Cannot open file %s.\n", filename);
        return;
    }
    fprintf(fp, "%s", content);
    printf("File %s saved successfully.\n", filename);
    fclose(fp);
}

void backup_directory(const char* directory_name) {
    Directory dir;
    FILE* fplist;
    char backup_filename[MAX_FILENAME_LENGTH];
    sprintf(backup_filename, "%s.bak", directory_name);

    // Open the original directory
    fplist = fopen(directory_name, "r");
    if (fplist == NULL) {
        printf("Error: Cannot open directory %s.\n", directory_name);
        return;
    }

    // Read the filenames and contents from the directory
    dir.num_files = 0;
    dir.files = (File*)malloc(sizeof(File));
    char filename[MAX_FILENAME_LENGTH];
    while (fgets(filename, MAX_FILENAME_LENGTH, fplist) != NULL) {
        filename[strlen(filename) - 1] = '\0';
        FILE* fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Error: Cannot open file %s.\n", filename);
            return;
        }
        fseek(fp, 0L, SEEK_END);
        long int content_size = ftell(fp);
        fseek(fp, 0L, SEEK_SET);
        char* content = (char*)malloc(content_size + 1);
        fread(content, sizeof(char), content_size, fp);
        content[content_size] = '\0';
        fclose(fp);

        // Add the filename and content to the directory struct
        dir.files = (File*)realloc(dir.files, (dir.num_files + 1) * sizeof(File));
        strcpy(dir.files[dir.num_files].filename, filename);
        strcpy(dir.files[dir.num_files].content, content);
        free(content);
        dir.num_files++;
    }

    fclose(fplist);

    // Save the directory backup
    FILE* fp = fopen(backup_filename, "wb");
    if (fp == NULL) {
        printf("Error: Cannot create backup file %s.\n", backup_filename);
        return;
    }
    fwrite(&dir, sizeof(Directory), 1, fp);
    fclose(fp);

    printf("Directory backup %s created successfully.\n", backup_filename);
}

void restore_directory(const char* backup_filename) {
    Directory dir;
    FILE* fp = fopen(backup_filename, "rb");
    if (fp == NULL) {
        printf("Error: Cannot open backup file %s.\n", backup_filename);
        return;
    }
    fread(&dir, sizeof(Directory), 1, fp);
    fclose(fp);

    // Restore the directory
    for (int i = 0; i < dir.num_files; i++) {
        save_file(dir.files[i].filename, dir.files[i].content);
    }

    printf("Directory %s restored successfully.\n", backup_filename);
}

int main() {
    backup_directory("test_dir");
    restore_directory("test_dir.bak");
    return 0;
}