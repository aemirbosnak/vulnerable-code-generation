//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB
#define BACKUP_DIR "backup"
#define BACKUP_EXT ".bak"

void backup_file(const char *file_path) {
    char backup_path[strlen(file_path) + strlen(BACKUP_DIR) + strlen(BACKUP_EXT) + 1];
    sprintf(backup_path, "%s/%s%s", BACKUP_DIR, file_path, BACKUP_EXT);

    struct stat file_stat;
    if (stat(file_path, &file_stat) == -1) {
        printf("Error: File not found - %s\n", file_path);
        return;
    }

    if (file_stat.st_size > MAX_FILE_SIZE) {
        printf("Error: File too large - %s\n", file_path);
        return;
    }

    FILE *backup_file = fopen(backup_path, "wb");
    if (backup_file == NULL) {
        printf("Error: Could not create backup file - %s\n", backup_path);
        return;
    }

    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("Error: Could not open file - %s\n", file_path);
        fclose(backup_file);
        remove(backup_path);
        return;
    }

    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(file);
    fclose(backup_file);

    printf("Backup created - %s\n", backup_path);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    backup_file(argv[1]);

    return 0;
}