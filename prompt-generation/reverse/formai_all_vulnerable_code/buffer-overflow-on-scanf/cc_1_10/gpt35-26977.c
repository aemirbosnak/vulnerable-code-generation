//FormAI DATASET v1.0 Category: File system simulation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int head = 0; // head of the file system
int fileCount = 0; // number of files in the file system

// structure of each file and directory in the file system
struct fileStruct{
    char name[20];
    char type[5];
    int parent;
    int size;
    int blocks[MAX];
    int blockCount;
};
struct fileStruct files[MAX];

// function to create a new file/directory
void createFile(){
    char name[20], type[5];
    int parent, size;

    printf("Enter name of the file/directory: ");
    scanf("%s", name);
    printf("Enter type of the file/directory: ");
    scanf("%s", type);
    printf("Enter parent index of the file/directory: ");
    scanf("%d", &parent);
    printf("Enter size of the file/directory: ");
    scanf("%d", &size);

    // add the file/directory to the file system
    strcpy(files[fileCount].name, name);
    strcpy(files[fileCount].type, type);
    files[fileCount].parent = parent;
    files[fileCount].size = size;
    files[fileCount].blockCount = (size / MAX) + 1;
    for(int i=0; i<files[fileCount].blockCount; i++){
        files[fileCount].blocks[i] = head;
        head++;
    }

    fileCount++;
    printf("%s created successfully!\n", name);
}

// function to display the file system
void displayFilesystem(){
    printf("Files in the file system:\n");
    printf("Name\tType\tParent\tSize\tBlock Count\tBlocks\n");
    for(int i=0; i<fileCount; i++){
        printf("%s\t%s\t%d\t%d\t%d\t", files[i].name, files[i].type, files[i].parent, files[i].size, files[i].blockCount);
        for(int j=0; j<files[i].blockCount; j++){
            printf("%d ", files[i].blocks[j]);
        }
        printf("\n");
    }
}

int main(){
    int choice;

    while(1){
        printf("\nFile System Simulation\n");
        printf("1. Create file/directory\t2. Display file system\t3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                createFile();
                break;
            case 2:
                displayFilesystem();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}