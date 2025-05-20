//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1000000
#define BACKUP_DIR "backup"
#define BACKUP_EXT ".bak"
#define TIME_FORMAT "%d-%m-%Y_%H-%M-%S"

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    size_t size;
    time_t timestamp;
} FileInfo;

void createDir(const char* path) {
    char cmd[100];
    sprintf(cmd, "mkdir -p %s", path);
    system(cmd);
}

int backupFile(const char* srcPath, const char* destPath) {
    FILE* srcFile = fopen(srcPath, "rb");
    if (srcFile == NULL) {
        printf("Error: could not open source file '%s'.\n", srcPath);
        return -1;
    }

    FILE* destFile = fopen(destPath, "wb");
    if (destFile == NULL) {
        printf("Error: could not create destination file '%s'.\n", destPath);
        fclose(srcFile);
        return -1;
    }

    char buffer[MAX_FILE_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, MAX_FILE_SIZE, srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(srcFile);
    fclose(destFile);

    if (ferror(destFile)) {
        printf("Error: could not write to destination file '%s'.\n", destPath);
        remove(destPath);
        return -1;
    }

    return 0;
}

int main() {
    char srcPath[MAX_FILE_NAME_LENGTH];
    printf("Enter the path of the file you want to backup: ");
    scanf("%s", srcPath);

    char destPath[MAX_FILE_NAME_LENGTH + strlen(BACKUP_DIR) + strlen(BACKUP_EXT)];
    sprintf(destPath, "%s/%s%s", BACKUP_DIR, srcPath, BACKUP_EXT);

    time_t timestamp = time(NULL);
    struct tm* tm = localtime(&timestamp);
    strftime(destPath + strlen(destPath) - strlen(BACKUP_EXT), strlen(BACKUP_EXT), TIME_FORMAT, tm);

    createDir(BACKUP_DIR);

    int result = backupFile(srcPath, destPath);
    if (result == 0) {
        printf("File '%s' backed up successfully to '%s'.\n", srcPath, destPath);
    }

    return 0;
}