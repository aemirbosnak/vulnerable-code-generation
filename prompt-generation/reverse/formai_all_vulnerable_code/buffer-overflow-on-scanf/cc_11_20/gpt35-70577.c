//FormAI DATASET v1.0 Category: File system simulation ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// struct to represent file metadata
typedef struct {
    char filename[20];
    int starting_block;
    int no_of_blocks;
    int end_block;
} file_data;

int main() {
    // initialize file system blocks
    int fs_blocks[256] = {0}; 
    
    // initialize file metadata table
    file_data file_table[256];
    int file_count = 0;
    
    // welcome message
    printf("Welcome to the File System Simulation!\n");
    
    while(1) { // keep running until user exits
        // display menu
        printf("\n---------------\n");
        printf("Menu:\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Display File Table\n");
        printf("4. Exit\n");
        printf("---------------\n");
        printf("Enter your choice (1-4): ");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:{
                // create file
                printf("\nEnter the filename (max 20 characters): ");
                char filename[20];
                scanf("%s", filename);
                
                if(file_count >= 256) { // check if file table is full
                    printf("\nError: File table is full. Cannot create file.\n");
                    break;
                }
                
                int starting_block;
                while(1) { // find first available block for file
                    starting_block = rand() % 256;
                    if(fs_blocks[starting_block] == 1) { // block is already in use
                        continue;
                    }
                    else { // block is available
                        fs_blocks[starting_block] = 1;
                        break;
                    }
                }
                
                int no_of_blocks = (rand() % 5) + 1; // randomly assign file size between 1-5 blocks
                int end_block = starting_block + no_of_blocks - 1;
                
                // update file metadata table
                strcpy(file_table[file_count].filename, filename);
                file_table[file_count].starting_block = starting_block;
                file_table[file_count].no_of_blocks = no_of_blocks;
                file_table[file_count].end_block = end_block;
                file_count++;
                
                printf("\nFile created successfully!\n");
                break;
            }
            
            case 2:{
                // delete file
                if(file_count == 0) {
                    printf("\nError: File table is empty. No files to delete.\n");
                    break;
                }
                
                printf("\nEnter the filename to delete: ");
                char filename[20];
                scanf("%s", filename);
                
                int i, file_found = 0;
                for(i=0; i<file_count; i++) { // search for file in file metadata table
                    if(strcmp(file_table[i].filename, filename) == 0) { // file found
                        file_found = 1;
                        int j;
                        for(j=file_table[i].starting_block; j<=file_table[i].end_block; j++) { // free up file blocks
                            fs_blocks[j] = 0;
                        }
                        
                        // shift file metadata table to remove deleted file
                        int k;
                        for(k=i; k<file_count-1; k++) {
                            file_table[k] = file_table[k+1];
                        }
                        file_count--;
                        
                        printf("\nFile deleted successfully!\n");
                        break;
                    }
                }
                if(file_found == 0) {
                    printf("\nError: File not found.\n");
                }
                break;
            }
            
            case 3:{
                // display file table
                if(file_count == 0) {
                    printf("\nFile table is empty.\n");
                    break;
                }
                
                printf("\n---------------\n");
                printf("File Metadata Table:\n");
                printf("---------------\n");
                int i;
                for(i=0; i<file_count; i++) {
                    printf("Filename: %s\n", file_table[i].filename);
                    printf("Starting block: %d\n", file_table[i].starting_block);
                    printf("No. of blocks: %d\n", file_table[i].no_of_blocks);
                    printf("End block: %d\n", file_table[i].end_block);
                    printf("---------------\n");
                }
                break;
            }
            
            case 4:{
                // exit program
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            }
            
            default:{
                printf("\nError: Invalid choice. Please choose again.\n");
            }
        }
    }
    return 0;
}