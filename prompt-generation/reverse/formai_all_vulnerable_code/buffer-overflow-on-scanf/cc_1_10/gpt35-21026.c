//FormAI DATASET v1.0 Category: File system simulation ; Style: beginner-friendly
#include <stdio.h>
#define MAX_FILES 10 // Maximum number of files in the system
#define MAX_NAME_SIZE 20 // Maximum size for a file name
#define MAX_FILE_SIZE 1024 // Maximum size for a file

// Definition of a file in the file system
typedef struct {
    char name[MAX_NAME_SIZE];
    int size;
    char content[MAX_FILE_SIZE];
} file_t;

// Declaration of functions
void createFile(file_t* files, int* numFiles);
void deleteFile(file_t* files, int* numFiles);
void printFiles(file_t* files, int numFiles);
void readFile(file_t* files, int numFiles);

int main() {
    file_t files[MAX_FILES]; // Array containing all the files in the system
    int numFiles = 0; // Counter for the number of files in the system
    int choice;

    printf("\n==== C FILE SYSTEM SIMULATION ====\n");

    do {
        printf("\nChoose an action:\n");
        printf("1. Create a new file\n");
        printf("2. Delete a file\n");
        printf("3. Print all files\n");
        printf("4. Read a file\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createFile(files, &numFiles);
                break;
            case 2:
                deleteFile(files, &numFiles);
                break;
            case 3:
                printFiles(files, numFiles);
                break;
            case 4:
                readFile(files, numFiles);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function to create a new file in the system
void createFile(file_t* files, int* numFiles) {
    if (*numFiles == MAX_FILES) {
        printf("Error: Maximum number of files reached\n");
        return;
    }

    printf("Enter the name of the file (up to %d characters): ", MAX_NAME_SIZE);
    scanf("%s", files[*numFiles].name);
    
    printf("Enter the content of the file (up to %d characters): ", MAX_FILE_SIZE);
    scanf("%s", files[*numFiles].content);
    files[*numFiles].size = strlen(files[*numFiles].content);

    printf("File created successfully\n");
    (*numFiles)++;
}

// Function to delete a file from the system
void deleteFile(file_t* files, int* numFiles) {
    char name[MAX_NAME_SIZE];

    printf("Enter the name of the file you want to delete: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < *numFiles; i++) {
        if (strcmp(name, files[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: File not found\n");
        return;
    }

    for (int i = index; i < *numFiles - 1; i++) {
        files[i] = files[i + 1];
    }

    printf("File deleted successfully\n");
    (*numFiles)--;
}

// Function to print all the files in the system
void printFiles(file_t* files, int numFiles) {
    if (numFiles == 0) {
        printf("No files in the system\n");
        return;
    }

    printf("List of files:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("- %s (%d bytes)\n", files[i].name, files[i].size);
    }
}

// Function to read the content of a file
void readFile(file_t* files, int numFiles) {
    char name[MAX_NAME_SIZE];

    printf("Enter the name of the file you want to read: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < numFiles; i++) {
        if (strcmp(name, files[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: File not found\n");
        return;
    }

    printf("Content of the file:\n%s\n", files[index].content);
}