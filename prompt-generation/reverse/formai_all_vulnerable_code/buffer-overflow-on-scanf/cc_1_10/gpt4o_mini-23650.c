//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_NAME_LENGTH 20

// File structure representing a funky file with personality
typedef struct {
    char name[MAX_NAME_LENGTH];
    int size; // in bytes
    char personality[MAX_NAME_LENGTH]; // Funky personality trait
} FunkyFile;

FunkyFile fileSystem[MAX_FILES];
int fileCount = 0;

// Function to create a funky file
void createFile() {
    if (fileCount >= MAX_FILES) {
        printf("Uh Oh! The FunkyFile system is full of funky files! Can't create more.\n");
        return;
    }

    FunkyFile newFile;
    printf("Enter a name for the funky file (Max %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", newFile.name);

    printf("How big is this funky file? (In bytes): ");
    scanf("%d", &newFile.size);

    printf("Give your funky file a personality trait (e.g. ‘Funny’, ‘Grumpy’, ‘Sassy’): ");
    scanf("%s", newFile.personality);

    fileSystem[fileCount++] = newFile;
    printf("Funky file '%s' created with a size of %d bytes and a personality of '%s'!\n",
           newFile.name, newFile.size, newFile.personality);
}

// Function to list funky files
void listFiles() {
    if (fileCount == 0) {
        printf("No funky files available. It's a sad day in FunkyFile land.\n");
        return;
    }

    printf("Listing all funky files:\n");
    for (int i = 0; i < fileCount; i++) {
        printf("%d. %s | Size: %d bytes | Personality: %s\n",
               i + 1, fileSystem[i].name, fileSystem[i].size, fileSystem[i].personality);
    }
}

// Function to delete a funky file
void deleteFile() {
    if (fileCount == 0) {
        printf("Nothing to delete! FunkyFile land is crying.\n");
        return;
    }

    listFiles();
    int fileIndex;
    printf("Enter the number of the funky file you want to delete: ");
    scanf("%d", &fileIndex);

    if (fileIndex < 1 || fileIndex > fileCount) {
        printf("Invalid file number! Are you trying to prank me?!\n");
        return;
    }

    printf("Deleting funky file '%s'... Goodbye! You were fabulous!\n", fileSystem[fileIndex - 1].name);
    for (int i = fileIndex - 1; i < fileCount - 1; i++) {
        fileSystem[i] = fileSystem[i + 1]; // Shift files left
    }
    fileCount--;
}

// Function to search for a funky file
void searchFile() {
    if (fileCount == 0) {
        printf("Search unsuccessful, FunkyFile land is empty! You'd think we were minimalist.\n");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter the name of the funky file to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < fileCount; i++) {
        if (strcmp(fileSystem[i].name, searchName) == 0) {
            printf("Found the funky file! '%s' | Size: %d bytes | Personality: %s\n",
                   fileSystem[i].name, fileSystem[i].size, fileSystem[i].personality);
            return;
        }
    }

    printf("FunkyFile '%s' not found. Did it run off to join the circus?\n", searchName);
}

// Menu to select operations
void displayMenu() {
    printf("\nWelcome to FunkyFile System!\n");
    printf("1. Create a funky file\n");
    printf("2. List all funky files\n");
    printf("3. Delete a funky file\n");
    printf("4. Search for a funky file\n");
    printf("5. Exit the funky file system\n");
    printf("What funky operation do you want to perform? ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                listFiles();
                break;
            case 3:
                deleteFile();
                break;
            case 4:
                searchFile();
                break;
            case 5:
                printf("Exiting the funky file system. Stay funky!\n");
                exit(0);
            default:
                printf("That's not a funky choice! Try again!\n");
        }
    }

    return 0;
}