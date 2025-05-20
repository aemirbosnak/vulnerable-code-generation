//FormAI DATASET v1.0 Category: Digital Diary ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Global Variables
char fileName[20];
char entryChoice;
time_t rawTime;
struct tm* currentTime;
char* entryDate;
char entryText[200];

// Function Declarations
void createOrOpenFile(FILE* filePointer);
void viewAllEntries(FILE* filePointer);
void addNewEntry(FILE* filePointer);

int main()
{
    FILE* filePointer = NULL;
    int optionChoice;

    printf("Welcome to your Digital Diary!\n");
    printf("Please enter a name for your diary file (without extension): ");
    scanf("%s", fileName);

    strcat(fileName, ".txt"); // Append .txt extension to fileName
    createOrOpenFile(filePointer);

    do {
        printf("\nSelect an option:\n");
        printf("1. View all entries\n");
        printf("2. Add new entry\n");
        printf("3. Exit\n");

        scanf("%d", &optionChoice);

        switch(optionChoice) {
            case 1:
                viewAllEntries(filePointer);
                break;
            case 2:
                addNewEntry(filePointer);
                break;
            case 3:
                printf("Thank you for using your Digital Diary!\n");
                fclose(filePointer);
                exit(0);
                break;
            default:
                printf("Invalid option choice. Please try again.\n");
        }

    } while (1); // Infinite loop to keep program running

    return 0;
}

// Function Definitions
void createOrOpenFile(FILE* filePointer) {
    filePointer = fopen(fileName, "a+");
    if (filePointer == NULL) {
        printf("Error opening file. Program will now exit.\n");
        exit(1);
    }
    fclose(filePointer);
}

void viewAllEntries(FILE* filePointer) {
    filePointer = fopen(fileName, "r");
    if (filePointer == NULL) {
        printf("Error opening file. Please try again.\n");
        return;
    }

    printf("\nAll Entries:\n");

    char fileLine[250];
    while(fgets(fileLine, 250, filePointer)) {
        printf("%s", fileLine);
    }

    fclose(filePointer);
}

void addNewEntry(FILE* filePointer) {
    printf("Enter entry text:\n");
    scanf("%s", entryText);

    time(&rawTime);
    currentTime = localtime(&rawTime);

    entryDate = asctime(currentTime);
    entryDate[strlen(entryDate)-1] = '\0'; // Remove newline character

    filePointer = fopen(fileName, "a");
    if (filePointer == NULL) {
        printf("Error opening file. Entry not saved.\n");
        return;
    }

    fprintf(filePointer, "Entry Date: %s\n", entryDate);
    fprintf(filePointer, "Entry Text: %s\n\n", entryText);

    fclose(filePointer);

    printf("Entry saved successfully!\n");
}