//FormAI DATASET v1.0 Category: Data recovery tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    printf("Welcome to the Data Recovery Tool!\n");
    printf("Please enter the name of the file you would like to recover: \n");
    
    char fileName[50];
    scanf("%s", fileName);

    printf("Initializing recovery process...\n");

    int fileSize = 0;
    FILE *file = fopen(fileName, "rb");
    if (!file) {
        printf("Error: File not found.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    rewind(file);

    srand((unsigned) time(NULL));

    char *recoveredData = (char*) malloc(fileSize * sizeof(char));
    memset(recoveredData, 0, fileSize);

    int i = 0;
    while(i < fileSize) {
        int randNum = rand() % fileSize;

        if(recoveredData[randNum] != 0) {
            continue;
        }

        fseek(file, randNum, SEEK_SET);
        fread(&recoveredData[randNum], sizeof(char), 1, file);
        i++;
    }

    printf("Data recovery successful!\n");
    printf("Recovered data: %s\n", recoveredData);

    fclose(file);
    free(recoveredData);

    return 0;
}