//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    long size;
} File;

typedef struct {
    File files[MAX_FILES];
    int count;
    long totalSize;
} Disk;

void initializeDisk(Disk *disk) {
    disk->count = 0;
    disk->totalSize = 0;
}

void addFile(Disk *disk, const char *name, long size) {
    if (disk->count < MAX_FILES) {
        strcpy(disk->files[disk->count].name, name);
        disk->files[disk->count].size = size;
        disk->totalSize += size;
        disk->count++;
    } else {
        printf("Alas! The disk hath reached its limit and cannot hold more files.\n");
    }
}

void displayFiles(Disk *disk) {
    if (disk->count == 0) {
        printf("The disk is as empty as a goblet after a grand feast.\n");
        return;
    }
    
    printf("Behold! The files within the realm of the disk:\n");
    for (int i = 0; i < disk->count; i++) {
        printf("   %s - %ld bytes\n", disk->files[i].name, disk->files[i].size);
    }
    printf("Total size of all files: %ld bytes\n", disk->totalSize);
}

void freeDisk(Disk *disk) {
    // In this simple example, no dynamic memory was used,
    // thus nothing to free. But we shall uphold the virtue of tidiness!
    disk->count = 0;
    disk->totalSize = 0;
}

void saveDiskInfoToFile(Disk *disk, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("The scribe hath failed to open the parchment for writing!\n");
        return;
    }
    
    fprintf(file, "The chronicles of the disk:\n");
    for (int i = 0; i < disk->count; i++) {
        fprintf(file, "%s - %ld bytes\n", disk->files[i].name, disk->files[i].size);
    }
    fprintf(file, "Total size: %ld bytes\n", disk->totalSize);
    
    fclose(file);
    printf("The chronicles hath been inscribed into the parchment: %s\n", filename);
}

int main() {
    Disk myDisk;
    initializeDisk(&myDisk);

    printf("Hark! Thou art about to enter the noble realm of Disk Space Manager.\n");
    
    char command[10];
    while (1) {
        printf("\nEnter a command (add, display, save, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[MAX_FILENAME_LENGTH];
            long size;
            printf("Enter the name of the file (like a noble scribe): ");
            scanf("%s", name);
            printf("Enter the size of the file in bytes: ");
            scanf("%ld", &size);
            addFile(&myDisk, name, size);
        } else if (strcmp(command, "display") == 0) {
            displayFiles(&myDisk);
        } else if (strcmp(command, "save") == 0) {
            char filename[MAX_FILENAME_LENGTH];
            printf("Enter the name of the parchment to save the records (with .txt): ");
            scanf("%s", filename);
            saveDiskInfoToFile(&myDisk, filename);
        } else if (strcmp(command, "exit") == 0) {
            printf("The noble scribe bids thee farewell!\n");
            break;
        } else {
            printf("Alas! That command is not known in this kingdom!\n");
        }
    }

    freeDisk(&myDisk);
    return 0;
}