//FormAI DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 200

// Function to get current date and time
char* getDateTime() {
    time_t rawtime;
    struct tm* timeinfo;
    char* buffer = (char*)malloc(sizeof(char) * 20);
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 20, "%Y-%m-%d %I:%M:%S", timeinfo);
    return buffer;
}

// Function to record a new entry in the diary
void newEntry(FILE* fp) {
    printf("What do you want to record in your diary?\nEntry: ");
    char entry[MAX_ENTRY_LENGTH];
    fgets(entry, MAX_ENTRY_LENGTH, stdin);
    char* dateTime = getDateTime();
    fprintf(fp, "\n\n%s\n%s\n", dateTime, entry);
    printf("\nEntry recorded successfully at %s!\n", dateTime);
    free(dateTime);
}

// Function to view all the existing entries in the diary
void viewEntries(FILE* fp) {
    char buffer[MAX_ENTRY_LENGTH];
    while(fgets(buffer, MAX_ENTRY_LENGTH, fp)) {
        printf("%s", buffer);
    }
}

int main(){
    printf("Welcome to your digital diary!\n\n");
    char* fileName = "digital_diary.txt";
    FILE* fp = fopen(fileName, "a+");
    if(fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    int option = 0;
    while(option != 3) {
        printf("\nWhat would you like to do?\n\n");
        printf("1. Record a new entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n\n");
        printf("Enter an option number: ");
        scanf("%d", &option);
        getchar(); // to clear the newline character from stdin
        switch(option) {
            case 1:
                newEntry(fp);
                break;
            case 2:
                viewEntries(fp);
                break;
            case 3:
                printf("\nThank you for using your digital diary.\n");
                break;
            default:
                printf("\nInvalid option! Please enter a valid option number.\n");
        }
    }
    fclose(fp);
    return 0;
}