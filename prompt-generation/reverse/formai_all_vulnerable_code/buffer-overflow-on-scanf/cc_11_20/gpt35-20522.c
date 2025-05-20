//FormAI DATASET v1.0 Category: File system simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file {
    char name[20];
    int size;
};

int main() {
    int option, num_files = 0;
    char file_name[20];
    struct file files[10];

    while(1) {
        printf("\nWelcome to the File System Simulation!\n");
        printf("\nSelect an option:\n");
        printf("1. Add a file\n");
        printf("2. Delete a file\n");
        printf("3. Display files\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1: 
                if(num_files == 10) {
                    printf("Error: Can't add more than 10 files.\n");
                    break;
                }
                printf("Enter file name: ");
                scanf("%s", file_name);
                strcpy(files[num_files].name, file_name);
                printf("Enter file size: ");
                scanf("%d", &files[num_files].size);
                num_files++;
                printf("File added successfully!\n");
                break;
            case 2:
                if(num_files == 0) {
                    printf("Error: No files found to delete.\n");
                    break;
                }
                printf("Enter file name to delete: ");
                scanf("%s", file_name);
                int found = 0;
                for(int i=0; i<num_files; i++) {
                    if(strcmp(files[i].name, file_name) == 0) {
                        found = 1;
                        for(int j=i; j<num_files-1; j++) {
                            strcpy(files[j].name, files[j+1].name);
                            files[j].size = files[j+1].size;
                        }
                        num_files--;
                        printf("File deleted successfully!\n");
                        break;
                    }
                }
                if(!found) {
                    printf("Error: %s file not found.\n", file_name);
                }
                break;
            case 3:
                if(num_files == 0) {
                    printf("No files found!\n");
                    break;
                }
                printf("\nFiles:\n");
                for(int i=0; i<num_files; i++) {
                    printf("%d. %s - %d KB\n", i+1, files[i].name, files[i].size);
                }
                break;
            case 4:
                printf("\nThank you for using the File System Simulation!\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}