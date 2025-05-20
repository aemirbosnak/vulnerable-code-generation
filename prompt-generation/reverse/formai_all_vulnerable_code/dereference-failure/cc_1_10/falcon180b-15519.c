//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB
#define BACKUP_DIR "backup"
#define BACKUP_EXT ".bak"

typedef struct {
    char original_file[256];
    char backup_file[256];
    time_t backup_time;
} BackupFile;

void create_backup_dir() {
    char cmd[256] = "mkdir -p ";
    strcat(cmd, BACKUP_DIR);
    system(cmd);
}

void backup_file(char* file_path) {
    FILE* fp_original = fopen(file_path, "rb");
    if (fp_original == NULL) {
        printf("Error opening file: %s\n", file_path);
        return;
    }

    fseek(fp_original, 0, SEEK_END);
    long file_size = ftell(fp_original);
    rewind(fp_original);

    char backup_file_path[256];
    snprintf(backup_file_path, sizeof(backup_file_path), "%s/%s%s", BACKUP_DIR, file_path, BACKUP_EXT);

    FILE* fp_backup = fopen(backup_file_path, "wb");
    if (fp_backup == NULL) {
        printf("Error creating backup file: %s\n", backup_file_path);
        fclose(fp_original);
        return;
    }

    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp_original)) > 0) {
        fwrite(buffer, 1, bytes_read, fp_backup);
    }

    fclose(fp_original);
    fclose(fp_backup);

    BackupFile backup_info;
    strcpy(backup_info.original_file, file_path);
    strcpy(backup_info.backup_file, backup_file_path);
    backup_info.backup_time = time(NULL);

    FILE* fp_info = fopen("backup_info.txt", "a");
    fprintf(fp_info, "%s -> %s (%ld bytes) - %ld\n", backup_info.original_file, backup_info.backup_file, file_size, backup_info.backup_time);
    fclose(fp_info);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    create_backup_dir();

    backup_file(argv[1]);

    return 0;
}