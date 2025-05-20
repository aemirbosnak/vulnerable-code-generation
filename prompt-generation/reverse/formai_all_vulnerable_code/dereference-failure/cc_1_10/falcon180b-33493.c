//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 1000
#define BACKUP_DIR "backup"
#define BACKUP_EXT ".bak"

char *get_current_time_string() {
    time_t now = time(NULL);
    struct tm tm = *localtime(&now);
    char time_str[30];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d_%H-%M-%S", &tm);
    return strdup(time_str);
}

void backup_file(const char *file_path) {
    char backup_file_path[MAX_FILE_NAME_LEN];
    sprintf(backup_file_path, "%s/%s%s", BACKUP_DIR, get_current_time_string(), BACKUP_EXT);
    FILE *backup_file = fopen(backup_file_path, "w");

    if (backup_file == NULL) {
        printf("Error creating backup file: %s\n", backup_file_path);
        return;
    }

    FILE *src_file = fopen(file_path, "r");

    if (src_file == NULL) {
        printf("Error opening source file: %s\n", file_path);
        fclose(backup_file);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), src_file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(src_file);
    fclose(backup_file);

    printf("Backed up %s to %s\n", file_path, backup_file_path);
}

int main() {
    char file_path[MAX_FILE_NAME_LEN];
    printf("Enter file path to backup: ");
    scanf("%s", file_path);

    backup_file(file_path);

    return 0;
}