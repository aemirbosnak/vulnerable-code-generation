//FormAI DATASET v1.0 Category: File system simulation ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define BLOCK_SIZE 1024

//creating a structure for file
struct FILE{
    char filename[20];
    int size;
    int start_block;
    int end_block;
};

//creating a structure for block
struct BLOCK{
    int block_size;
    int is_free;
    char *data;
};

int main(){
    int total_blocks, free_blocks, file_count = 0;
    struct BLOCK *blocks;
    struct FILE *files;
    
    //reading total number of blocks in file system
    printf("Enter total number of blocks in file system: ");
    scanf("%d", &total_blocks);
    
    //memory allocation for blocks
    blocks = (struct BLOCK *)malloc(total_blocks * sizeof(struct BLOCK));
    
    //initializing blocks
    int i;
    for(i = 0; i<total_blocks; i++){
        blocks[i].block_size = BLOCK_SIZE;
        blocks[i].is_free = 1;
        blocks[i].data = (char *)malloc(BLOCK_SIZE * sizeof(char));
    }
    
    //reading number of free blocks in file system
    printf("Enter the number of free blocks in file system: ");
    scanf("%d", &free_blocks);
    
    //marking free blocks
    int block_index;
    printf("Enter block indices that are free: \n");
    for(i = 0; i<free_blocks; i++){
        scanf("%d", &block_index);
        blocks[block_index].is_free = 1;
    }
    
    //memory allocation for files
    files = (struct FILE *)malloc(total_blocks * sizeof(struct FILE));
    
    //reading number of files
    printf("Enter the number of files in file system: ");
    int num_files;
    scanf("%d", &num_files);
    
    //reading file data
    for(i = 0; i<num_files; i++){
        printf("Enter name of file %d: ", i+1);
        scanf("%s", files[i].filename);
        printf("Enter size of file %d: ", i+1);
        scanf("%d", &files[i].size);
        
        int j, flag = 0;
        for(j = 0; j<total_blocks; j++){
            if(blocks[j].is_free == 1){
                flag = 1;
                int k;
                for(k = 0; k<blocks[j].block_size; k++){
                    blocks[j].data[k] = '0';
                }
                files[i].start_block = j;
                int remaining = files[i].size - BLOCK_SIZE;
                int p = j;
                while(remaining > 0){
                    blocks[p].is_free = 0;
                    remaining -= BLOCK_SIZE;
                    p++;
                    files[i].end_block = p;
                }
                blocks[p].is_free = 0;
            }
            
            if(flag == 1){
                file_count++;
                break;
            }
        }
        if(flag == 0){
            printf("\nNo free block available in file system to store file %d", i+1);
        }
    }
    
    //displaying file system information
    printf("\n---------------------File System Information------------------------\n");
    printf("Total number of blocks: %d\n", total_blocks);
    printf("Number of free blocks: %d\n", free_blocks);
    printf("Number of files in file system: %d\n", file_count);
    printf("---------------------------------------------------------------------\n");
    printf("Filename\t\tSize\t\tStart block\t\tEnd block\n");
    for(i = 0; i<file_count; i++){
        printf("%s\t\t%d\t\t%d\t\t%d\n", files[i].filename, files[i].size, files[i].start_block, files[i].end_block);
    }
    printf("---------------------------------------------------------------------\n");
    
    //deleting file and freeing up blocks
    printf("\nEnter name of file to delete: ");
    char filename[20];
    scanf("%s", filename);
    for(i = 0; i<file_count; i++){
        if(strcmp(filename, files[i].filename) == 0){
            int j;
            for(j = files[i].start_block; j<=files[i].end_block; j++){
                blocks[j].is_free = 1;
            }
            printf("\nFile %s is deleted successfully", filename);
            break;
        }
    }
    
    return 0;
}