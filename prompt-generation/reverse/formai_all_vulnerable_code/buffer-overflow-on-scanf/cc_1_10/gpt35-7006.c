//FormAI DATASET v1.0 Category: Data recovery tool ; Style: retro
#include <stdio.h>
#include <string.h>

typedef struct {
    char filename[20];
    int size;
} FileInfo;

void printMenu() {
    printf("Data Recovery Tool (retro style)\n\n");
    printf("1. Scan for recoverable files\n");
    printf("2. Recover file\n");
    printf("3. Exit\n");
}

void scanForFiles(FileInfo files[], int* count) {
    printf("Scanning...\n\n");
    // code to scan for recoverable files goes here
    // for demo purposes, we hardcode 3 files
    strcpy(files[*count].filename, "file1.txt");
    files[*count].size = 1024;
    (*count)++;
    strcpy(files[*count].filename, "file2.jpg");
    files[*count].size = 2048;
    (*count)++;
    strcpy(files[*count].filename, "file3.doc");
    files[*count].size = 3072;
    (*count)++;
}

void recoverFile(FileInfo files[], int count) {
    char filename[25];
    printf("Enter filename to recover: ");
    scanf("%s", filename);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            printf("Recovering...\n");
            // code to recover file goes here
            printf("File successfully recovered!\n");
            return;
        }
    }
    
    printf("File not found.\n");
}

int main() {
    FileInfo files[10];
    int count = 0;
    int choice;
    
    do {
        printMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                scanForFiles(files, &count);
                printf("Scan complete.\n\n");
                break;
            case 2:
                recoverFile(files, count);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
        
        printf("\n");
    } while (choice != 3);
    
    return 0;
}