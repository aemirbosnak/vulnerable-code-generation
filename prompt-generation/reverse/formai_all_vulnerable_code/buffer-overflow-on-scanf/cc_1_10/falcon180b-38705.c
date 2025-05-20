//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a file
typedef struct {
    char name[50];
    int size;
    char content[100];
} File;

// Function to create a new file
void createFile(File *file) {
    printf("Enter file name: ");
    scanf("%s", file->name);
    printf("Enter file size: ");
    scanf("%d", &file->size);
    printf("Enter file content: ");
    scanf("%[^\n]s", file->content);
}

// Function to display file information
void displayFile(File file) {
    printf("File name: %s\n", file.name);
    printf("File size: %d bytes\n", file.size);
    printf("File content: %s\n", file.content);
}

// Function to read from a file
void readFile(File *file) {
    printf("File content: %s\n", file->content);
}

// Function to write to a file
void writeFile(File *file) {
    printf("Enter new file content: ");
    scanf("%[^\n]s", file->content);
}

// Function to delete a file
void deleteFile(File *file) {
    printf("File %s deleted.\n", file->name);
}

// Main function
int main() {
    File file;
    int choice;

    do {
        printf("\nFile System Simulation\n");
        printf("1. Create file\n");
        printf("2. Display file information\n");
        printf("3. Read file\n");
        printf("4. Write file\n");
        printf("5. Delete file\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createFile(&file);
                break;
            case 2:
                displayFile(file);
                break;
            case 3:
                readFile(&file);
                break;
            case 4:
                writeFile(&file);
                break;
            case 5:
                deleteFile(&file);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 6);

    return 0;
}