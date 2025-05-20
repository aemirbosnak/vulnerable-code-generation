//FormAI DATASET v1.0 Category: File system simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100    // maximum number of files in the file system
#define MAX_FILE_SIZE 1024   // maximum size of each file

// structure to hold file information
typedef struct {
    char name[20];
    int size;
    char data[MAX_FILE_SIZE];
} file_t;

// function to create a new file
file_t create_file(char name[], char data[]){

    file_t new_file;

    strcpy(new_file.name, name);
    strcpy(new_file.data, data);

    new_file.size = strlen(data);

    return new_file;
}

int main(){

    file_t file_system[MAX_FILES];    // array to hold all the files in the file system
    int num_files = 0;    // initial number of files in the file system
    int choice;

    printf("File System Simulation\n\n");

    do {
        printf("Currently %d files in the file system\n", num_files);
        printf("1. Create a new file\n");
        printf("2. List all files\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (num_files >= MAX_FILES){
                    printf("Sorry, file system full.\n");
                    break;
                }

                char name[20];
                char data[MAX_FILE_SIZE];

                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file data: ");
                scanf("%s", data);

                file_t new_file = create_file(name, data);

                file_system[num_files++] = new_file;

                printf("File created successfully.\n");
                break;
            }
            case 2: {
                if (!num_files){
                    printf("No files in the file system.\n");
                    break;
                }

                printf("Listing all files: \n");

                for(int i=0; i<num_files; i++){
                    printf("Name: %s, Size: %d\n", file_system[i].name, file_system[i].size);
                }
                break;
            }
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");

    } while (choice != 3);

    printf("Goodbye!\n");

    return 0;

}