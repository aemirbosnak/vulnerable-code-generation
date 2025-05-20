//FormAI DATASET v1.0 Category: Digital Diary ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 30

struct Entry {
    char date[20];
    char message[200];
} diary[MAX_ENTRIES];

int numEntries = 0;

void addEntry(char *message);
void displayEntries();
void searchEntries(char *keyword);

int main() {
    int choice;
    char message[200], keyword[20];

    printf("Welcome to your digital diary!\n\n");

    while(1) {
        printf("What would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. Display all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                printf("Write something happy: ");
                scanf(" %[^\n]", message);
                addEntry(message);
                printf("Entry added successfully!\n\n");
                break;
            case 2:
                printf("Here are all your entries:\n");
                displayEntries();
                break;
            case 3:
                printf("Enter a keyword to search for: ");
                scanf(" %[^\n]", keyword);
                searchEntries(keyword);
                break;
            case 4:
                printf("Good bye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}

void addEntry(char *message) {
    time_t now;
    struct tm *ltime;

    time(&now);
    ltime = localtime(&now);

    sprintf(diary[numEntries].date, "%02d/%02d/%04d %02d:%02d:%02d",
            ltime->tm_mday, ltime->tm_mon+1, ltime->tm_year+1900,
            ltime->tm_hour, ltime->tm_min, ltime->tm_sec);

    strcpy(diary[numEntries].message, message);
    numEntries++;

    if(numEntries == MAX_ENTRIES) {
        printf("Maximum number of entries reached!\n");
        exit(0);
    }
}

void displayEntries() {
    int i;

    for(i=0; i<numEntries; i++) {
        printf("%s:\n%s\n\n", diary[i].date, diary[i].message);
    }
}

void searchEntries(char *keyword) {
    int i, found = 0;

    for(i=0; i<numEntries; i++) {
        if(strstr(diary[i].message, keyword) != NULL) {
            printf("%s:\n%s\n\n", diary[i].date, diary[i].message);
            found = 1;
        }
    }

    if(found == 0) {
        printf("No matching entries found.\n\n");
    }
}