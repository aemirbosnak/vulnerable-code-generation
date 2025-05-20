//FormAI DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char date[10];
    int size;
} File;

int main(){
    FILE *fPtr;
    int numFiles;
    int i, j;
    char filename[20];
    printf("Enter the number of files to recover: ");
    scanf("%d", &numFiles);

    File *fileArr = (File*) malloc(numFiles * sizeof(File));

    for(i = 0; i < numFiles; i++){
        printf("Enter the file name: ");
        scanf("%s", &(fileArr[i].name));
        printf("Enter the date the file was lost (MM/DD/YYYY): ");
        scanf("%s", &(fileArr[i].date));
        printf("Enter the estimated size of the file (in bytes): ");
        scanf("%d", &(fileArr[i].size));
    }

    int totalSize = 0;
    for(i = 0; i < numFiles; i++){
        totalSize += fileArr[i].size;
    }
    
    char *data = (char*) malloc(totalSize);

    for(i = 0; i < numFiles; i++){
        sprintf(filename, "%s_%s.dat", fileArr[i].name, fileArr[i].date);
        fPtr = fopen(filename, "r");
        if(fPtr == NULL){
            printf("Error: Could not open file %s\n", filename);
        }
        else{
            printf("Found file: %s\n", filename);
            char *temp = (char*) malloc(fileArr[i].size);
            fread(temp, sizeof(char), fileArr[i].size, fPtr);
            strcat(data, temp);
            fclose(fPtr);
            free(temp);
        }
    }

    printf("\nRecovered data:\n%s\n", data);

    free(fileArr);
    free(data);

    return 0;
}