//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILES 10
#define MAX_FILE_NAME 50
#define MAX_CONTENT 100
#define STORAGE_CAPACITY 500

typedef struct {
    char name[MAX_FILE_NAME];
    char content[MAX_CONTENT];
} File;

typedef struct {
    File files[MAX_FILES];
    int file_count;
    int storage_used;
} FileSystem;

// Function prototypes
void initialize(FileSystem* fs);
void createFile(FileSystem* fs);
void readFile(FileSystem* fs);
void deleteFile(FileSystem* fs);
void displayFiles(FileSystem* fs);
void simulateAnnoyingDiskFullError();

int main() {
    FileSystem fs;
    initialize(&fs);
    
    int choice;
    while (1) {
        printf("\nWelcome to the Silly File System Simulator!\n");
        printf("1. Create a File\n");
        printf("2. Read a File\n");
        printf("3. Delete a File\n");
        printf("4. Display All Files\n");
        printf("5. Exit\n");
        printf("Please enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Oops! That's not a valid number! Let's stick with digits, shall we?\n");
            while (getchar() != '\n'); // clear invalid input
            continue;
        }

        switch (choice) {
            case 1:
                createFile(&fs);
                break;
            case 2:
                readFile(&fs);
                break;
            case 3:
                deleteFile(&fs);
                break;
            case 4:
                displayFiles(&fs);
                break;
            case 5:
                printf("Exiting the Silly File System. Have a file-tastic day!\n");
                exit(0);
            default:
                printf("Oh dear! That choice doesn't exist. Try again!\n");
        }
    }
    return 0;
}

void initialize(FileSystem* fs) {
    fs->file_count = 0;
    fs->storage_used = 0;
    printf("Initializing the Silly File System... Shhh, it's a secret! 🤫\n");
}

void createFile(FileSystem* fs) {
    if (fs->file_count >= MAX_FILES) {
        printf("Whoa! We've hit the file limit. Can't create more files! 📁💥\n");
        simulateAnnoyingDiskFullError();
        return;
    }

    char filename[MAX_FILE_NAME];
    char content[MAX_CONTENT];

    printf("Enter the name of the file (max %d characters): ", MAX_FILE_NAME - 1);
    scanf(" %[^\n]", filename);
    printf("Enter the content of the file (max %d characters): ", MAX_CONTENT - 1);
    scanf(" %[^\n]", content);

    int content_length = strlen(content);

    if (content_length + fs->storage_used > STORAGE_CAPACITY) {
        printf("Oh no! Not enough space! Your content is heavier than a sumo wrestler! 🥋💔\n");
        return;
    }

    strcpy(fs->files[fs->file_count].name, filename);
    strcpy(fs->files[fs->file_count].content, content);
    fs->storage_used += content_length;
    fs->file_count++;

    printf("File '%s' created successfully! 🎉\n", filename);
}

void readFile(FileSystem* fs) {
    if (fs->file_count == 0) {
        printf("No files to read! It's as empty as a vacuum! 🌀\n");
        return;
    }

    char filename[MAX_FILE_NAME];
    printf("Enter the name of the file you want to read: ");
    scanf(" %[^\n]", filename);

    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            printf("Reading file '%s': \n%s\n", fs->files[i].name, fs->files[i].content);
            return;
        }
    }

    printf("File '%s' not found! It might be on vacation! 🌴🏖️\n", filename);
}

void deleteFile(FileSystem* fs) {
    if (fs->file_count == 0) {
        printf("No files to delete! You're not a book burner, are you? 📖🔥\n");
        return;
    }

    char filename[MAX_FILE_NAME];
    printf("Enter the name of the file you want to delete: ");
    scanf(" %[^\n]", filename);

    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            // Shift files left
            for (int j = i; j < fs->file_count - 1; j++) {
                fs->files[j] = fs->files[j + 1];
            }
            fs->file_count--;
            fs->storage_used -= strlen(fs->files[i].content);
            printf("File '%s' deleted successfully! Adios, amigo! 👋💻\n", filename);
            return;
        }
    }

    printf("File '%s' not found! It must be hiding! 🤭\n", filename);
}

void displayFiles(FileSystem* fs) {
    if (fs->file_count == 0) {
        printf("There are no files! Not even a single cookie! 🍪🚫\n");
        return;
    }

    printf("Current files in the Silly File System:\n");
    for (int i = 0; i < fs->file_count; i++) {
        printf("%d. %s\n", i + 1, fs->files[i].name);
    }
}

void simulateAnnoyingDiskFullError() {
    printf("BEEP BEEP! Disk space is full! \n");
    printf("Suggestion: Clean up some space or do a joyful dance and hope it works! 💃🕺\n");
}