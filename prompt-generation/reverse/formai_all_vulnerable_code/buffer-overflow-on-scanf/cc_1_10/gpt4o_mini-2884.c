//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void joyfullyBackupFile(const char *sourceFile, const char *backupDir) {
    char backupFilePath[256];
    snprintf(backupFilePath, sizeof(backupFilePath), "%s/%s_backup", backupDir, sourceFile);

    FILE *source = fopen(sourceFile, "rb");
    if (!source) {
        fprintf(stderr, "Oh no! Could not open the file %s for reading.\n", sourceFile);
        return;
    }

    FILE *backup = fopen(backupFilePath, "wb");
    if (!backup) {
        fprintf(stderr, "Oopsie! Could not create backup file %s.\n", backupFilePath);
        fclose(source);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, backup);
    }

    printf("Yay! Successfully backed up %s to %s\n", sourceFile, backupFilePath);

    fclose(source);
    fclose(backup);
}

int main() {
    char sourceFile[256];
    char backupDir[256];

    printf("🌈 Welcome to the Happy File Backup System! 🌈\n");
    printf("Please enter the name of the file you want to back up: ");
    scanf("%s", sourceFile);

    printf("Where would you like to save the backup? Please enter the directory: ");
    scanf("%s", backupDir);

    struct stat dirStat;
    if (stat(backupDir, &dirStat) != 0 || !S_ISDIR(dirStat.st_mode)) {
        fprintf(stderr, "😢 Oops! The directory %s does not exist. Please create it first!\n", backupDir);
        return 1;
    }

    joyfullyBackupFile(sourceFile, backupDir);

    printf("🎉 Thank you for using the Happy File Backup System! 🎈\n");
    return 0;
}