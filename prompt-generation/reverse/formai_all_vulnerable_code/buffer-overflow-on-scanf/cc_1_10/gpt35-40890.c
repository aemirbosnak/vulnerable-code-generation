//FormAI DATASET v1.0 Category: File system simulation ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

#define MAX_FILES 100 // Maximum files that can be created
#define FILE_SIZE 1024 // Maximum size of each file

struct file {
    char name[20];
    int size;
    char data[FILE_SIZE];
};

struct file files[MAX_FILES]; // Array of File Structures
int num_files = 0; // Track number of files created
int cur_file_index = -1; // Track currently opened file

// Function to create a new file
void create_file() {
    if(num_files == MAX_FILES) {
        printf("Cannot create more files. Limit reached.\n");
        return;
    }
    printf("Enter file name: ");
    scanf("%s", files[num_files].name);
    printf("Enter file size: ");
    scanf("%d", &files[num_files].size);
    if(files[num_files].size > FILE_SIZE) {
        printf("File size too large. Limit is %d.\n", FILE_SIZE);
        return;
    }
    printf("Enter file data: ");
    scanf("%s", files[num_files].data);
    num_files++;
}

// Function to display all files
void display_files() {
    printf("Files:\n");
    for(int i=0; i<num_files; i++) {
        printf("%s (%d bytes)\n", files[i].name, files[i].size);
    }
}

// Function to open a file
void open_file() {
    printf("Enter file name: ");
    char name[20];
    scanf("%s", name);
    for(int i=0; i<num_files; i++) {
        if(strcmp(files[i].name, name) == 0) {
            cur_file_index = i;
            printf("File opened for editing: %s\n", name);
            return;
        }
    }
    printf("%s not found.\n", name);
}

// Function to edit current file
void edit_file() {
    if(cur_file_index == -1) {
        printf("No file is currently opened.\n");
        return;
    }
    printf("Enter file data: ");
    scanf("%s", files[cur_file_index].data);
    files[cur_file_index].size = strlen(files[cur_file_index].data);
    printf("File saved.\n");
}

// Function to close current file
void close_file() {
    if(cur_file_index == -1) {
        printf("No file is currently opened.\n");
        return;
    }
    cur_file_index = -1;
    printf("Current file closed.\n");
}

// Main function to display menu and run program
int main() {
    int choice;
    while(1) {
        printf("1. Create file\n");
        printf("2. Display files\n");
        printf("3. Open file\n");
        printf("4. Edit file\n");
        printf("5. Close file\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                create_file();
                break;
            case 2:
                display_files();
                break;
            case 3:
                open_file();
                break;
            case 4:
                edit_file();
                break;
            case 5:
                close_file();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}