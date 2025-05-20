//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#define MAX_FILES 100
#define MAX_FILENAME 256

typedef struct {
    char name[MAX_FILENAME];
    int status; // 0: available, 1: deleted
} FileEntry;

FileEntry fileSystem[MAX_FILES];
int fileCount = 0;

void initFileSystem() {
    // Simulating a file system with some files
    strcpy(fileSystem[fileCount++].name, "document.txt");
    strcpy(fileSystem[fileCount++].name, "image.png");
    strcpy(fileSystem[fileCount++].name, "video.mp4");
    strcpy(fileSystem[fileCount++].name, "resume.docx");
    
    // Marking some files as deleted
    fileSystem[1].status = 1; // image.png is deleted
    fileSystem[3].status = 1; // resume.docx is deleted
}

void displayFiles() {
    printf("\n=== File System ===\n");
    for (int i = 0; i < fileCount; i++) {
        if (fileSystem[i].status == 0) {
            printf("- %s (Available)\n", fileSystem[i].name);
        } else {
            printf("- %s (Deleted) [Recoverable!]\n", fileSystem[i].name);
        }
    }
    printf("===================\n");
}

void recoverFile(int index) {
    if (index < 0 || index >= fileCount || fileSystem[index].status == 0) {
        printf("Invalid selection or file already available!\n");
        return;
    }

    fileSystem[index].status = 0; // Recover the file
    printf("Hurray! Successfully recovered %s!\n", fileSystem[index].name);
}

void showMenu() {
    int choice;
    while (1) {
        printf("\n=== Data Recovery Tool ===\n");
        printf("1. Display Files\n");
        printf("2. Recover File\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFiles();
                break;
            case 2: {
                int fileIndex;
                printf("Enter the index of the file to recover (starting from 0): ");
                scanf("%d", &fileIndex);
                recoverFile(fileIndex);
                break;
            }
            case 3:
                printf("Exiting the recovery tool. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Exciting Data Recovery Tool!\n");
    initFileSystem();
    showMenu();
    
    return 0;
}