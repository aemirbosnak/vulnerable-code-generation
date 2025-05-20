//FormAI DATASET v1.0 Category: File system simulation ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_SYSTEM_SIZE 1000
#define MAX_FILE_NAME_SIZE 20
#define MAX_FILE_CONTENT_SIZE 100

typedef struct {
    char file_name[MAX_FILE_NAME_SIZE];
    char file_content[MAX_FILE_CONTENT_SIZE];
} file;

file file_system[MAX_FILE_SYSTEM_SIZE];
int file_system_size = 0;

void display_menu() {
    printf("\nWelcome to the Grateful File System Simulation!\n");
    printf("1. Create a file\n");
    printf("2. Read a file\n");
    printf("3. Update a file\n");
    printf("4. Delete a file\n");
    printf("5. Exit the program\n");
}

void create_file() {
    if(file_system_size == MAX_FILE_SYSTEM_SIZE) {
        printf("\nFile system is full. Cannot create more files.");
        return;
    }
    file new_file;
    printf("\nEnter the name of the file: ");
    scanf("%s", new_file.file_name);
    printf("Enter the content of the file: ");
    scanf("%s", new_file.file_content);
    file_system[file_system_size++] = new_file;
    printf("\nFile created successfully!\n");
}

void read_file() {
    char name[MAX_FILE_NAME_SIZE];
    printf("\nEnter the name of the file to read: ");
    scanf("%s", name);
    for(int i = 0; i < file_system_size; i++) {
        if(strcmp(file_system[i].file_name, name) == 0) {
            printf("\nFile content: %s\n", file_system[i].file_content);
            return;
        }
    }
    printf("\nFile not found\n");
}

void update_file() {
    char name[MAX_FILE_NAME_SIZE];
    printf("\nEnter the name of the file to update: ");
    scanf("%s", name);
    for(int i = 0; i < file_system_size; i++) {
        if(strcmp(file_system[i].file_name, name) == 0) {
            printf("Enter the new content of the file: ");
            scanf("%s", file_system[i].file_content);
            printf("\nFile updated successfully!\n");
            return;
        }
    }
    printf("\nFile not found\n");
}

void delete_file() {
    char name[MAX_FILE_NAME_SIZE];
    printf("\nEnter the name of the file to delete: ");
    scanf("%s", name);
    for(int i = 0; i < file_system_size; i++) {
        if(strcmp(file_system[i].file_name, name) == 0) {
            for(int j = i; j < file_system_size-1; j++) {
                file_system[j] = file_system[j+1];
            }
            file_system_size--;
            printf("\nFile deleted successfully!\n");
            return;
        }
    }
    printf("\nFile not found\n");
}

int main() {
    int choice;

    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                create_file();
                break;
            case 2:
                read_file();
                break;
            case 3:
                update_file();
                break;
            case 4:
                delete_file();
                break;
            case 5:
                printf("\nExiting the program...\n\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}