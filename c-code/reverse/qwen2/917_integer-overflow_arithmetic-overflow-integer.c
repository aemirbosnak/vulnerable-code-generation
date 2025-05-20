#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

#define MAX_BACKUPS 5

void create_backup(const char *original_file) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y%m%d%H%M%S", tm_info);

    char backup_name[100];
    snprintf(backup_name, sizeof(backup_name), "backup_%s_%s", original_file, timestamp);

    if (rename(original_file, backup_name) != 0) {
        perror("Failed to rename file");
    }
}

void clean_backups(const char *base_name) {
    DIR *dir;
    struct dirent *entry;
    int count[MAX_BACKUPS] = {0};

    dir = opendir(".");
    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strncmp(entry->d_name, base_name, strlen(base_name)) == 0) {
            count[strlen(entry->d_name) - strlen(base_name)]++;
        }
    }

    closedir(dir);

    for (int i = 0; i < MAX_BACKUPS; i++) {
        if (count[i] > 1) {
            char old_backup[100];
            snprintf(old_backup, sizeof(old_backup), "backup_%s_%ld", base_name, i);
            remove(old_backup);
        }
    }
}

int main() {
    const char *file_to_backup = "example.txt";

    create_backup(file_to_backup);
    clean_backups("backup_example");

    return 0;
}
