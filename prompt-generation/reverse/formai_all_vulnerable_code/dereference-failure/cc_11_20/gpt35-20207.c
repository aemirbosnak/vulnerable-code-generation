//FormAI DATASET v1.0 Category: Data recovery tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 50
#define MAX_DATA_SIZE 500

typedef struct File {
    char filename[MAX_FILENAME_SIZE];
    char data[MAX_DATA_SIZE];
} File;

int main() {
    char buffer[100];
    int option, i, num_files = 0;
    File *files = NULL;
    
    printf("Welcome to the C Data Recovery Tool!\n");
    
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Create a new file\n");
        printf("2. Recover data from existing files\n");
        printf("3. Exit\n");
        
        fgets(buffer, 100, stdin);
        option = atoi(buffer);
        
        switch(option) {
            
            case 1:
                if(num_files == 0) {
                    files = (File*)malloc(sizeof(File));
                }
                else {
                    files = (File*)realloc(files, (num_files+1) * sizeof(File));
                }
                if(files == NULL) {
                    printf("Error: Memory allocation failed.\n");
                    exit(1);
                }
                printf("Enter a filename (less than 50 characters): ");
                fgets(files[num_files].filename, MAX_FILENAME_SIZE, stdin);
                printf("Enter some data (less than 500 characters): ");
                fgets(files[num_files].data, MAX_DATA_SIZE, stdin);
                num_files++;
                printf("File created!\n");
                break;
                
            case 2:
                if(num_files == 0) {
                    printf("Error: No files to recover data from.\n");
                    continue;
                }
                printf("Files available for data recovery:\n");
                for(i = 0; i < num_files; i++) {
                    printf("%d. %s\n", i+1, files[i].filename);
                }
                printf("Enter file number to recover data: ");
                fgets(buffer, 100, stdin);
                i = atoi(buffer) - 1;
                if(i < 0 || i >= num_files) {
                    printf("Error: Invalid file number.\n");
                    continue;
                }
                printf("Data from %s:\n", files[i].filename);
                printf("%s\n", files[i].data);
                break;
                
            case 3:
                printf("Exiting C Data Recovery Tool...\n");
                break;
                
            default:
                printf("Error: Invalid option.\n");            
        }
        
    } while (option != 3);
    
    free(files);
    return 0;
}