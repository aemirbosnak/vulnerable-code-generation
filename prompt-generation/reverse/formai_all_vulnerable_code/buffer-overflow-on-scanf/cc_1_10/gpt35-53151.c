//FormAI DATASET v1.0 Category: File system simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 20
#define MAX_FILE_COUNT 10
#define BLOCK_SIZE 1024

typedef struct{
    char filename[MAX_FILENAME_LEN];
    int start_block;
    int end_block;
} File;

int allocate_blocks(int num_blocks, int *bitmap){
    int start_block = 0;
    int count = 0;
    
    for(int i=0; i<BLOCK_SIZE; i++){
        if(bitmap[i] == 0){
            count++;
        }
        else{
            count = 0;
        }
        
        if(count == num_blocks){
            start_block = i - num_blocks + 1;
            break;
        }
    }
    
    if(start_block == 0){
        return -1;
    }
    
    for(int i=start_block; i<start_block + num_blocks; i++){
        bitmap[i] = 1;
    }
    
    return start_block;
}

void free_blocks(int start_block, int num_blocks, int *bitmap){
    for(int i=start_block; i<start_block + num_blocks; i++){
        bitmap[i] = 0;
    }
}

int main(){
    int bitmap[BLOCK_SIZE] = {0};
    File files[MAX_FILE_COUNT];
    int file_count = 0;
    
    while(1){
        printf("File System Simulation\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Show Files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice){
            case 1:{
                if(file_count == MAX_FILE_COUNT){
                    printf("File limit exceeded!\n");
                    break;
                }
                
                printf("Enter file name: ");
                char filename[MAX_FILENAME_LEN];
                scanf("%s", filename);
                
                int num_blocks;
                printf("Enter number of blocks: ");
                scanf("%d", &num_blocks);
                
                int start_block = allocate_blocks(num_blocks, bitmap);
                if(start_block == -1){
                    printf("Not enough free space!\n");
                    break;
                }
                
                File file;
                strcpy(file.filename, filename);
                file.start_block = start_block;
                file.end_block = start_block + num_blocks - 1;
                files[file_count++] = file;
                printf("File %s created successfully!\n", filename);
                break;
            }
            
            case 2:{
                if(file_count == 0){
                    printf("No files to delete!\n");
                    break;
                }
                
                printf("Enter file name: ");
                char filename[MAX_FILENAME_LEN];
                scanf("%s", filename);
                
                int found = 0;
                for(int i=0; i<file_count; i++){
                    if(strcmp(files[i].filename, filename) == 0){
                        found = 1;
                        free_blocks(files[i].start_block, files[i].end_block - files[i].start_block + 1, bitmap);
                        for(int j=i; j<file_count-1; j++){
                            files[j] = files[j+1];
                        }
                        file_count--;
                        printf("File %s deleted successfully!\n", filename);
                        break;
                    }
                }
                
                if(!found){
                    printf("File not found!\n");
                }
                break;
            }
            
            case 3:{
                if(file_count == 0){
                    printf("No files to show!\n");
                    break;
                }
                
                printf("Files:\n");
                printf("Filename\tStart Block\tEnd Block\n");
                for(int i=0; i<file_count; i++){
                    printf("%s\t\t%d\t\t%d\n", files[i].filename, files[i].start_block, files[i].end_block);
                }
                break;
            }
            
            case 4:{
                printf("Exiting...\n");
                exit(0);
            }
            
            default:{
                printf("Invalid choice!\n");
                break;
            }
        }
    }
    
    return 0;
}