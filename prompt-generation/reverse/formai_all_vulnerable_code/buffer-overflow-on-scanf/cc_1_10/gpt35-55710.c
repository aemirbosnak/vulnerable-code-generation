//FormAI DATASET v1.0 Category: File handling ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePointer;
    char fileName[20];
    char buffer[200];
    int choice, numBytes;

    printf("Enter the name of the file to be created: ");
    scanf("%s", fileName);

    filePointer = fopen(fileName, "w");

    if (filePointer == NULL) {
        printf("Error: File cannot be created!");
        exit(1);
    }

    printf("Enter the text to be written to the file: ");
    scanf("%s", buffer);

    fputs(buffer, filePointer);
    fclose(filePointer);


    printf("File created and content written successfully!\n");
    printf("Would you like to - \n1. Read the contents of the file \n2. Exit the program?\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            filePointer = fopen(fileName, "r");

            if (filePointer == NULL) {
                printf("Error: File cannot be opened!");
                exit(1);
            }

            fseek(filePointer, 0, SEEK_END);
            numBytes = ftell(filePointer);
            fseek(filePointer, 0, SEEK_SET);

            printf("The contents of the file are: \n");

            while (fgets(buffer, sizeof(buffer), filePointer)) {
                printf("%s", buffer);
            }

            fclose(filePointer);
            break;

        case 2:
            printf("Exiting program...");
            break;

        default:
            printf("Invalid input! Exiting program...");
            break;
    }

    return 0;
}