//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BLOCK_SIZE 512
#define MAX_FILES 100

typedef struct {
    char name[255];
    long startBlock;
    long size;
} File;

File files[MAX_FILES];
int fileCount = 0;

void loadFiles();
void recoverFile(int index);
void displayRecoveredFiles();
void handleError(const char* msg);

int main() {
    printf("🎉 Welcome to the *SHOCKING* C Data Recovery Tool! 🎉\n");
    printf("🔍 Scanning for lost files... 🕵️‍♂️\n");

    loadFiles();

    if (fileCount == 0) {
        printf("🚫 No recoverable files found. Please check your storage! 🚫\n");
        return 1;
    }

    printf("✅ Found %d recoverable file(s):\n", fileCount);
    displayRecoveredFiles();

    for (int i = 0; i < fileCount; i++) {
        printf("Would you like to recover '%s'? (y/n): ", files[i].name);
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y') {
            recoverFile(i);
        }
    }

    printf("🎊 Recovery process completed! Check your files! 🎊\n");
    return 0;
}

void loadFiles() {
    // Simulate loading files from a hypothetical corrupted storage
    strcpy(files[0].name, "important_document.txt");
    files[0].startBlock = 1024;
    files[0].size = BLOCK_SIZE * 10;
    fileCount++;

    strcpy(files[1].name, "holiday_photos.zip");
    files[1].startBlock = 2048;
    files[1].size = BLOCK_SIZE * 50;
    fileCount++;

    strcpy(files[2].name, "project_backup.tar");
    files[2].startBlock = 4096;
    files[2].size = BLOCK_SIZE * 30;
    fileCount++;
    
    // This is just simulated. In reality, you'd scan the disk for lost files.
}

void recoverFile(int index) {
    printf("🚀 Recovering '%s'... ⏳\n", files[index].name);
    
    char buffer[BLOCK_SIZE];
    int inFile = open("/dev/sda", O_RDONLY);
    if (inFile < 0) {
        handleError("Couldn't open device, make sure you have permission!");
        return;
    }

    char recoveryPath[300];
    sprintf(recoveryPath, "./RECORED_%s", files[index].name);
    int outFile = open(recoveryPath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outFile < 0) {
        handleError("Failed to create recovery file!");
        close(inFile);
        return;
    }

    long blocksToRead = files[index].size / BLOCK_SIZE;
    for (long i = 0; i < blocksToRead; i++) {
        lseek(inFile, files[index].startBlock + (i * BLOCK_SIZE), SEEK_SET);
        read(inFile, buffer, BLOCK_SIZE);
        write(outFile, buffer, BLOCK_SIZE);
    }

    printf("✅ File '%s' recovered successfully at '%s'! 🎊\n", files[index].name, recoveryPath);
    
    close(inFile);
    close(outFile);
}

void displayRecoveredFiles() {
    for (int i = 0; i < fileCount; i++) {
        printf("%d. %s (Size: %ld bytes)\n", i + 1, files[i].name, files[i].size);
    }
}

void handleError(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}