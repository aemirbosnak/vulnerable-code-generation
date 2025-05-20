//FormAI DATASET v1.0 Category: Digital Diary ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// defining maximum length for the diary entries
#define MAX_ENTRY_LENGTH 500

// function to get the current date and time
char* getCurrentDateTime() {
    time_t timer;
    char* dateTimeString = malloc(sizeof(char)*30); // allocating memory for dateTimeString
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(dateTimeString, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    return dateTimeString;
}

// function to add diary entry to the file
void addEntryToFile(char* fileName) {
    char entry[MAX_ENTRY_LENGTH];
    printf("Enter your entry:\n");
    fgets(entry, MAX_ENTRY_LENGTH, stdin); // getting entry from the user

    FILE* diaryFile = fopen(fileName, "a"); // opening the file in append mode
    if (diaryFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(diaryFile, "%s %s", getCurrentDateTime(), entry); // writing the entry to the file
    fclose(diaryFile);
    printf("Entry added successfully!\n");
}

// function to read and print all the entries from the file
void readEntriesFromFile(char* fileName) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE* diaryFile = fopen(fileName, "r"); // opening the file in read mode
    if (diaryFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("\n---------------YOUR DIARY ENTRIES---------------\n");
    while ((read = getline(&line, &len, diaryFile)) != -1) { // reading the entries line by line
        printf("%s", line);
    }
    printf("------------------------------------------------\n\n");
    free(line);
    fclose(diaryFile);
}

int main() {
    char fileName[50] = "diary.txt";
    int choice;
    do {
        printf("\n\n---------------DIGITAL DIARY---------------\n");
        printf("1. Add diary entry\n");
        printf("2. View all diary entries\n");
        printf("3. Exit\n");
        printf("---------------------------------------------\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // to clear the input buffer

        switch(choice) {
            case 1:
                addEntryToFile(fileName);
                break;
            case 2:
                readEntriesFromFile(fileName);
                break;
            case 3:
                printf("Exiting program. Bye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}