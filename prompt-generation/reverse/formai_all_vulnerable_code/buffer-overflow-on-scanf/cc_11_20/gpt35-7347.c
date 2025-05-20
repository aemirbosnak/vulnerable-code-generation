//FormAI DATASET v1.0 Category: File system simulation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILES 10
#define FILE_NAME_LENGTH 20
#define BLOCK_SIZE 512

typedef struct {
    char file_name[FILE_NAME_LENGTH];
    int file_size;
    int start_block;
    int end_block;
} file;

int main() {
    int block_allocation[MAX_FILES][BLOCK_SIZE];
    file files[MAX_FILES];
    int file_count = 0;

    memset(block_allocation, 0, sizeof(block_allocation));

    while(1) {
        printf("\n\n1. Create a new file\n");
        printf("2. Delete an existing file\n");
        printf("3. Display list of files\n");
        printf("4. Exit");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("\nEnter file name: ");
                char name[FILE_NAME_LENGTH];
                scanf("%s", name);

                int file_size;
                printf("\nEnter file size: ");
                scanf("%d", &file_size);

                int blocks_needed = file_size/BLOCK_SIZE + 1;

                if(file_count == MAX_FILES) {
                    printf("\nCannot create file. Maximum number of files reached.");
                    break;
                }
                else if(blocks_needed > (BLOCK_SIZE - 
                    (files[file_count-1].end_block - files[file_count-1].start_block))) {
                    printf("\nCannot create file. No free blocks available.");
                    break;
                }
                else {
                    strcpy(files[file_count].file_name, name);
                    files[file_count].file_size = file_size;
                    files[file_count].start_block = files[file_count-1].end_block + 1;
                    files[file_count].end_block = files[file_count].start_block + blocks_needed - 1;

                    for(int i=files[file_count].start_block; i<=files[file_count].end_block; i++) {
                        block_allocation[file_count][i] = 1;
                    }

                    file_count++;
                    printf("\nFile created successfully!");
                }
                break;
            }
            case 2: {
                printf("\nEnter file name to delete: ");
                char name[FILE_NAME_LENGTH];
                scanf("%s", name);

                int file_index = -1;

                for(int i=0; i<file_count; i++) {
                    if(strcmp(files[i].file_name, name) == 0) {
                        file_index = i;
                        break;
                    }
                }

                if(file_index == -1) {
                    printf("\nFile not found.");
                }
                else {
                    for(int i=files[file_index].start_block; i<=files[file_index].end_block; i++) {
                        block_allocation[file_index][i] = 0;
                    }

                    for(int i=file_index; i<file_count-1; i++) {
                        files[i] = files[i+1];
                        for(int j=files[i].start_block; j<=files[i].end_block; j++) {
                            block_allocation[i][j] = block_allocation[i+1][j];
                        }
                    }

                    file_count--;
                    printf("\nFile deleted successfully!");
                }
                break;
            }
            case 3: {
                printf("\nFiles:");
                printf("\nName\tSize\tStart Block\tEnd Block");

                for(int i=0; i<file_count; i++) {
                    printf("\n%s\t%d\t%d\t%d", files[i].file_name, files[i].file_size, 
                        files[i].start_block, files[i].end_block);
                }
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("\nInvalid choice. Try again.");
            }
        }
    }

    return 0;
}