//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILES 100
#define METADATA_LENGTH 256

// Structure to hold file metadata
typedef struct {
    char fileName[METADATA_LENGTH];
    long fileSize;
    char fileType[METADATA_LENGTH];
    char createdDate[METADATA_LENGTH];
} FileMetadata;

// Function prototypes
void addFileMetadata(FileMetadata *metadataArray, int *currentIndex);
void displayFileMetadata(const FileMetadata *metadataArray, int count);
bool isValidFileType(const char *fileType);
void clearInputBuffer();

// Constants for file types
const char *allowedTypes[] = { "jpg", "png", "gif", "txt", "pdf", "docx", "mp4", NULL };

int main() {
    FileMetadata metadataArray[MAX_FILES];
    int fileCount = 0;
    char command[METADATA_LENGTH];

    printf("Welcome to the paranoid Metadata Extractor!\n");

    while (true) {
        printf("\nMenu:\n");
        printf("1. Add file metadata\n");
        printf("2. Display file metadata\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        clearInputBuffer();
        fgets(command, sizeof(command), stdin);

        switch (command[0]) {
            case '1':
                if (fileCount < MAX_FILES) {
                    addFileMetadata(metadataArray, &fileCount);
                } else {
                    printf("Maximum file limit reached! Please remove some entries to add new ones.\n");
                }
                break;
            case '2':
                displayFileMetadata(metadataArray, fileCount);
                break;
            case '3':
                printf("Exiting the program. Stay safe!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void addFileMetadata(FileMetadata *metadataArray, int *currentIndex) {
    FileMetadata newMetadata;

    printf("Enter file name (with extension): ");
    clearInputBuffer();
    fgets(newMetadata.fileName, sizeof(newMetadata.fileName), stdin);
    newMetadata.fileName[strcspn(newMetadata.fileName, "\n")] = '\0'; // Strip newline

    printf("Enter file size (in bytes): ");
    scanf("%ld", &newMetadata.fileSize);
    
    printf("Enter file type (e.g. jpg, png): ");
    clearInputBuffer();
    fgets(newMetadata.fileType, sizeof(newMetadata.fileType), stdin);
    newMetadata.fileType[strcspn(newMetadata.fileType, "\n")] = '\0'; // Strip newline

    if (!isValidFileType(newMetadata.fileType)) {
        printf("Invalid file type detected! Aborting the entry to ensure security!\n");
        return;
    }

    printf("Enter created date (YYYY-MM-DD): ");
    fgets(newMetadata.createdDate, sizeof(newMetadata.createdDate), stdin);
    newMetadata.createdDate[strcspn(newMetadata.createdDate, "\n")] = '\0'; // Strip newline

    metadataArray[*currentIndex] = newMetadata;
    (*currentIndex)++;
    printf("File metadata successfully added!\n");
}

void displayFileMetadata(const FileMetadata *metadataArray, int count) {
    if (count == 0) {
        printf("No file metadata available to display.\n");
        return;
    }

    printf("\n--- File Metadata ---\n");
    for (int i = 0; i < count; i++) {
        printf("File Name: %s\n", metadataArray[i].fileName);
        printf("File Size: %ld bytes\n", metadataArray[i].fileSize);
        printf("File Type: %s\n", metadataArray[i].fileType);
        printf("Created Date: %s\n", metadataArray[i].createdDate);
        printf("-------------------------\n");
    }
}

bool isValidFileType(const char *fileType) {
    for (int i = 0; allowedTypes[i] != NULL; i++) {
        if (strcmp(fileType, allowedTypes[i]) == 0) {
            return true;
        }
    }
    return false;
}

void clearInputBuffer() {
    while (getchar() != '\n');
}