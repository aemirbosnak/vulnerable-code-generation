//FormAI DATASET v1.0 Category: Data recovery tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// retro style opening message
void openingMessage(){
    printf("==============================================\n");
    printf("|   WELCOME TO THE DATA RECOVERY TOOL 2.0   |\n");
    printf("==============================================\n");
}

// data recovery function
void dataRecovery(){
    printf("\nEnter the name of the file to recover: ");

    char fileName[50];
    scanf("%s", fileName);

    printf("\nEnter the data block size (in bytes): ");

    int blockSize;
    scanf("%d", &blockSize);

    FILE *file = fopen(fileName, "r");
    if (file == NULL){
        printf("\nERROR: File not found or could not be opened.\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    rewind(file);

    char *recoveredData = (char*)malloc(fileSize * sizeof(char));

    int readBlockSize;
    while ((readBlockSize = fread(recoveredData, 1, blockSize, file)) > 0){
        printf("\n--- Data block recovered with size %d bytes ---\n", readBlockSize);
    }

    printf("\n\nRecovered data:\n%s\n", recoveredData);

    free(recoveredData);
    fclose(file);
}

int main(){
    // retro style opening message
    openingMessage();

    // main menu
    printf("\n[1] Recover data\n[2] Exit\n\nEnter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice){
        case 1:
            printf("\n---DATA RECOVERY---\n\n");
            dataRecovery();
            break;
        case 2:
            printf("\nThanks for using the data recovery tool!\n");
            exit(0);
            break;
        default:
            printf("\nInvalid choice.\n");
            exit(1);
    }

    return 0;
}