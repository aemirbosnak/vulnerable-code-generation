//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void displayGreeting() {
    printf("🎉 Welcome to the Cheerful File Backup System! 🎉\n");
    printf("Let's make sure your important files are safe and sound! 😊\n");
}

void getFileName(char *fileName) {
    printf("Please enter the full path of the file you want to back up: ");
    scanf("%s", fileName);
}

void getBackupLocation(char *backupLocation) {
    printf("Where do you want to save your backup? (Enter the full path): ");
    scanf("%s", backupLocation);
}

void createTimestamp(char *timestamp) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(timestamp, 20, "%Y%m%d_%H%M%S", t);
}

void constructBackupName(char *backupLocation, char *fileName, char *backupName) {
    char timestamp[20];
    createTimestamp(timestamp);
    
    char *baseName = strrchr(fileName, '/');
    if (baseName == NULL) {
        baseName = fileName;
    } else {
        baseName++;
    }

    snprintf(backupName, 256, "%s/%s_%s.bak", backupLocation, baseName, timestamp);
}

int copyFile(const char *source, const char *destination) {
    FILE *srcFile = fopen(source, "rb");
    if (srcFile == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *destFile = fopen(destination, "wb");
    if (destFile == NULL) {
        fclose(srcFile);
        perror("Error opening destination file");
        return 1;
    }

    char buffer[1024];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
    
    return 0; // success
}

int main() {
    displayGreeting();

    char fileName[256];
    char backupLocation[256];
    char backupName[256];

    getFileName(fileName);
    getBackupLocation(backupLocation);
    constructBackupName(backupLocation, fileName, backupName);

    printf("📦 Preparing to back up your file '%s' to '%s'... 🏁\n", fileName, backupName);

    if (copyFile(fileName, backupName) == 0) {
        printf("✅ Backup completed successfully! Your file is now safe! 🎈\n");
    } else {
        printf("❌ Oops! Something went wrong during the backup. Please try again! 🚨\n");
    }

    printf("Thank you for using the Cheerful File Backup System! 😄\n");
    return 0;
}