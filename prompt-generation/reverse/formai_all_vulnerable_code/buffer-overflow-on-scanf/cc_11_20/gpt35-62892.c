//FormAI DATASET v1.0 Category: File system simulation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to hold file metadata
typedef struct {
    int file_id;
    char file_name[20];
    int file_size;
} File;

int main(){
    int option, n=0, total_size=0;
    printf("Welcome to the C File System Simulator\n");

    // Allocate memory for maximum of 100 files
    File* file_storage = (File*)malloc(100*sizeof(File));
    while(1){
        printf("\nOptions:\n1. Add file\n2. Delete file\n3. View file storage status\n4. Exit\nEnter your option: ");
        scanf("%d", &option);

        if(option==1){
            if(n>=100){
                printf("Error: File storage is full\n");
            }
            else{
                // Ask for file name and size and add to file_storage array
                printf("Enter file name: ");
                scanf("%s", file_storage[n].file_name);
                printf("Enter file size: ");
                scanf("%d", &file_storage[n].file_size);
                total_size += file_storage[n].file_size;
                file_storage[n].file_id = n+1;
                printf("File added successfully: %s\n", file_storage[n].file_name);
                n++;
            }
        }
        else if(option==2){
            int file_id, index=-1;
            printf("Enter file ID to delete: ");
            scanf("%d", &file_id);

            // Find file index by checking file_id
            for(int i=0; i<n; i++){
                if(file_storage[i].file_id == file_id){
                    index = i;
                    break;
                }
            }

            if(index==-1){
                printf("Error: File not found\n");
            }
            else{
                // Delete file by shifting all files to the left
                total_size -= file_storage[index].file_size;
                printf("File deleted successfully: %s\n", file_storage[index].file_name);
                for(int i=index+1; i<n; i++){
                    file_storage[i-1] = file_storage[i];
                }
                n--;
            }
        }
        else if(option==3){
            printf("Total files: %d\n", n);
            printf("Total file storage used: %d bytes\n", total_size);
            printf("File ID, File Name, File Size\n");
            printf("-----------------------------\n");
            for(int i=0; i<n; i++){
                printf("%d, %s, %d bytes\n", file_storage[i].file_id, file_storage[i].file_name, file_storage[i].file_size);
            }
            printf("\n");
        }
        else if(option==4){
            printf("Exiting file system simulator...\n");
            break;
        }
        else{
            printf("Error: Invalid option\n");
        }
    }

    free(file_storage);
    return 0;
}