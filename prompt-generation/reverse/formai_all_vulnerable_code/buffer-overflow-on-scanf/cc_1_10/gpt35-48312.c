//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

#define MAX_FILES 50

struct fileInfo {
    char name[50];
    int size;
};

void scanFiles(struct fileInfo files[]) {
    int i;
    printf("Scanning files...\n");
    for(i=0;i<MAX_FILES;i++) {
        if(files[i].size > 0) {
            printf("Detecting virus in file %s...\n", files[i].name);
            printf("Virus removed from file %s.\n", files[i].name);
        }
    }
    printf("Scan complete.\n");
}

void addFile(struct fileInfo files[], char name[], int size) {
    int i;
    for(i=0;i<MAX_FILES;i++) {
        if(files[i].size == 0) {
            strcpy(files[i].name, name);
            files[i].size = size;
            printf("File added: %s\n", name);
            break;
        }
    }
}

int main () {

    struct fileInfo files[MAX_FILES];
    char fileName[50];
    int fileSize, option;

    do {
        printf("\n1. Add File\n2. Scan Files\n3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("Enter file name and size: ");
                scanf("%s %d", fileName, &fileSize);
                addFile(files, fileName, fileSize);
                break;
            case 2:
                scanFiles(files);
                break;
            case 3:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while(option != 3);

    return 0;
}