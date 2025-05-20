//FormAI DATASET v1.0 Category: File system simulation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_FILE_COUNT 50
#define MAX_FILE_NAME_LENGTH 20

/* File structure to hold file information*/
struct File{
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
};

/* Function to add a new file to the file system*/
int add_file(struct File *file_arr, int *file_count, char *file_name, int file_size){
    if(*file_count >= MAX_FILE_COUNT){
        printf("File system is full. Cannot add more files.\n");
        return -1;
    }
    strcpy(file_arr[*file_count].file_name, file_name);
    file_arr[*file_count].file_size = file_size;
    (*file_count)++;
    return *file_count-1;
}

/* Function to delete a file from file system*/
int delete_file(struct File *file_arr, int *file_count, char *file_name){
    int i;
    for(i=0; i<*file_count; i++){
        if(strcmp(file_arr[i].file_name, file_name)==0){
            file_arr[i] = file_arr[--(*file_count)];
            printf("File '%s' deleted successfully.\n", file_name);
            return i;
        }
    }
    printf("File '%s' not found in file system.\n", file_name);
    return -1;
}

/* Function to list all the files in the file system*/
void list_files(struct File *file_arr, int file_count){
    int i;
    printf("List of files in the file system:\n");
    for(i=0; i<file_count; i++){
        printf("%d. %s\t%d bytes\n", i+1, file_arr[i].file_name, file_arr[i].file_size);
    }
}

/* Main function to simulate a file system*/
int main(){
    printf("Welcome to File System Simulation Program!\n");
    struct File file_arr[MAX_FILE_COUNT];
    int file_count = 0;
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size, choice, file_index;
    while(1){
        printf("\nEnter your choice:\n");
        printf("1. Add a File\n2. Delete a File\n3. List all Files\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter file name (max length 20 characters): ");
                scanf("%s", file_name);
                printf("Enter file size (in bytes): ");
                scanf("%d", &file_size);
                file_index = add_file(file_arr, &file_count, file_name, file_size);
                if(file_index!=-1){
                    printf("File '%s' added successfully. Index assigned: %d\n", file_name, file_index);
                }
                break;
            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", file_name);
                file_index = delete_file(file_arr, &file_count, file_name);
                break;
            case 3:
                list_files(file_arr, file_count);
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }
    return 0;
}