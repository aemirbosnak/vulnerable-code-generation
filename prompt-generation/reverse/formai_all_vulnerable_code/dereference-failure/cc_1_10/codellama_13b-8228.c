//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

#define BACKUP_DIR "backup"
#define MAX_FILES 100

typedef struct {
    char name[100];
    char path[100];
    time_t time;
} file_info_t;

void print_backup_files(const char* backup_dir) {
    DIR* dir = opendir(backup_dir);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}

void backup_file(const char* file_path, const char* backup_dir) {
    char cmd[100];
    sprintf(cmd, "cp %s %s", file_path, backup_dir);
    system(cmd);
}

void backup_files(const char* backup_dir) {
    DIR* dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            backup_file(entry->d_name, backup_dir);
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s backup_dir\n", argv[0]);
        exit(1);
    }

    const char* backup_dir = argv[1];
    backup_files(backup_dir);

    return 0;
}