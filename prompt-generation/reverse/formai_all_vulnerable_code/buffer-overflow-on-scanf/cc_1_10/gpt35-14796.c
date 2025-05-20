//FormAI DATASET v1.0 Category: File system simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_FILE_COUNT 10

// File structure
typedef struct {
    char name[20];
    int size;
    char data[MAX_FILE_SIZE];
} File;

// File System structure
typedef struct {
    File files[MAX_FILE_COUNT];
    int file_count;
    int total_size;
} FileSystem;

// Function to add a new file
void add_file(FileSystem *fs, char name[], char data[], int size) {
    if(fs->file_count >= MAX_FILE_COUNT) {
        printf("ERROR: File system is full.\n");
    }
    else if(strlen(name) >= 20) {
        printf("ERROR: File name is too long. Maximum length is 20 characters.\n");
    }
    else if(fs->total_size + size > MAX_FILE_SIZE * MAX_FILE_COUNT) {
        printf("ERROR: File system is out of space.\n");
    }
    else {
        File new_file;
        strcpy(new_file.name, name);
        new_file.size = size;
        strcpy(new_file.data, data);

        fs->files[fs->file_count] = new_file;
        fs->file_count++;
        fs->total_size += size;

        printf("File '%s' added to file system.\n", name);
    }
}

// Function to remove a file
void remove_file(FileSystem *fs, char name[]) {
    int i, file_index = -1;
    for(i=0; i<fs->file_count; i++) {
        if(strcmp(fs->files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }

    if(file_index == -1) {
        printf("ERROR: File does not exist.\n");
    }
    else {
        fs->total_size -= fs->files[file_index].size;
        fs->file_count--;
        for(i=file_index; i<fs->file_count; i++) {
            fs->files[i] = fs->files[i+1];
        }
        printf("File '%s' removed from file system.\n", name);
    }
}

// Function to print list of files
void print_files(FileSystem *fs) {
    printf("List of Files:\n");
    if(fs->file_count == 0) {
        printf("No files found.\n");
    }
    else {
        int i;
        for(i=0; i<fs->file_count; i++) {
            printf("%d. %s (%dB)\n", i+1, fs->files[i].name, fs->files[i].size);
        }
    }
}

int main() {
    FileSystem fs = {0};

    printf("Welcome to the File System Simulator!\n");
    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a file\n");
        printf("2. Remove a file\n");
        printf("3. View list of files\n");
        printf("4. Exit program\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        if(choice == 1) {
            printf("\nEnter the file name: ");
            char name[20];
            scanf("%s", name);

            printf("Enter the file data: ");
            char data[MAX_FILE_SIZE];
            scanf(" %[^\n]", data);

            int size = strlen(data);
            add_file(&fs, name, data, size);
        }
        else if(choice == 2) {
            printf("\nEnter the file name to remove: ");
            char name[20];
            scanf("%s", name);

            remove_file(&fs, name);
        }
        else if(choice == 3) {
            print_files(&fs);
        }
        else if(choice == 4) {
            printf("\nExiting program...\n");
            break;
        }
        else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}