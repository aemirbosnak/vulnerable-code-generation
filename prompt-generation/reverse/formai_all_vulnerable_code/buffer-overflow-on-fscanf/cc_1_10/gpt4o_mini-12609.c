//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_FILES 100
#define CONFIG_FILE "monitor.config"
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char fileName[MAX_FILE_NAME_LENGTH];
    off_t lastSize;
    time_t lastModified;
} MonitoredFile;

MonitoredFile monitoredFiles[MAX_FILES];
int monitoredFileCount = 0;

void loadConfig() {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (file == NULL) {
        perror("Error opening config file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", monitoredFiles[monitoredFileCount].fileName) != EOF) {
        struct stat fileStat;
        if (stat(monitoredFiles[monitoredFileCount].fileName, &fileStat) == 0) {
            monitoredFiles[monitoredFileCount].lastSize = fileStat.st_size;
            monitoredFiles[monitoredFileCount].lastModified = fileStat.st_mtime;
            monitoredFileCount++;
        }
    }

    fclose(file);
}

void checkFileChanges() {
    for (int i = 0; i < monitoredFileCount; i++) {
        struct stat fileStat;
        if (stat(monitoredFiles[i].fileName, &fileStat) == 0) {
            if (fileStat.st_size != monitoredFiles[i].lastSize || 
                fileStat.st_mtime != monitoredFiles[i].lastModified) {
                printf("ALERT: Changes detected in file: %s\n", monitoredFiles[i].fileName);
                printf("Old Size: %ld, New Size: %ld\n", 
                       monitoredFiles[i].lastSize, fileStat.st_size);
                printf("Old Modified Time: %ld, New Modified Time: %ld\n", 
                       monitoredFiles[i].lastModified, fileStat.st_mtime);
                
                // Update the last recorded state
                monitoredFiles[i].lastSize = fileStat.st_size;
                monitoredFiles[i].lastModified = fileStat.st_mtime;
            }
        } else {
            printf("ERROR: Unable to stat file: %s\n", monitoredFiles[i].fileName);
        }
    }
}

int main() {
    loadConfig();

    while (1) {
        checkFileChanges();
        sleep(5);  // Sleep for 5 seconds before checking again
    }

    return 0;
}