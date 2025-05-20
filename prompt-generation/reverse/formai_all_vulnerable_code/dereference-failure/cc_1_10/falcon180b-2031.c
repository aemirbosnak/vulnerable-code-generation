//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <pthread.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_DIRECTORY_LENGTH 1024
#define MAX_THREADS 10

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char directory_name[MAX_DIRECTORY_LENGTH];
    time_t last_modified;
} file_info;

void *backup_thread(void *arg) {
    file_info *file = (file_info *) arg;
    char backup_path[MAX_DIRECTORY_LENGTH];
    strcpy(backup_path, file->directory_name);
    strcat(backup_path, "/backup/");
    mkdir(backup_path, 0755);
    strcat(backup_path, file->file_name);
    FILE *backup_file = fopen(backup_path, "w");
    if (backup_file == NULL) {
        printf("Error creating backup file %s\n", backup_path);
        exit(1);
    }
    FILE *source_file = fopen(file->file_name, "r");
    if (source_file == NULL) {
        printf("Error opening source file %s\n", file->file_name);
        exit(1);
    }
    char buffer[1024];
    while (fgets(buffer, 1024, source_file)!= NULL) {
        fputs(buffer, backup_file);
    }
    fclose(source_file);
    fclose(backup_file);
}

void backup_files(char *directory_name) {
    DIR *dir = opendir(directory_name);
    if (dir == NULL) {
        printf("Error opening directory %s\n", directory_name);
        exit(1);
    }
    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) { // Regular file
            file_info file;
            strcpy(file.file_name, ent->d_name);
            strcpy(file.directory_name, directory_name);
            struct stat st;
            stat(file.file_name, &st);
            file.last_modified = st.st_mtime;
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, backup_thread, &file);
        }
    }
    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s directory_name\n", argv[0]);
        exit(1);
    }
    backup_files(argv[1]);
    return 0;
}