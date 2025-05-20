//FormAI DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 20
#define MAX_CONTENT_LENGTH 100
#define MAX_SEARCH_RESULTS 20

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    char date[11];
    char time[6];
} Entry;

Entry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    char date[11];
    char time[6];

    printf("Enter Title (max 20 characters): ");
    fgets(title, MAX_TITLE_LENGTH, stdin);
    strtok(title, "\n");

    printf("Enter Content (max 100 characters): ");
    fgets(content, MAX_CONTENT_LENGTH, stdin);
    strtok(content, "\n");

    printf("Enter Date (dd-mm-yyyy): ");
    fgets(date, 11, stdin);
    strtok(date, "\n");

    printf("Enter Time (hh:mm): ");
    fgets(time, 6, stdin);
    strtok(time, "\n");

    Entry newEntry;
    strcpy(newEntry.title, title);
    strcpy(newEntry.content, content);
    strcpy(newEntry.date, date);
    strcpy(newEntry.time, time);

    diary[entryCount++] = newEntry;
}

void displayAllEntries() {
    for(int i=0; i<entryCount; i++) {
        printf("\nTitle: %s", diary[i].title);
        printf("Content: %s", diary[i].content);
        printf("Date: %s", diary[i].date);
        printf("Time: %s\n", diary[i].time);
    }
}

void searchEntries() {
    char keyword[MAX_CONTENT_LENGTH];
    printf("Enter keyword to search: ");
    fgets(keyword, MAX_CONTENT_LENGTH, stdin);
    strtok(keyword, "\n");

    bool found = false;
    int searchResults[MAX_SEARCH_RESULTS];
    int resultCount = 0;
    for(int i=0; i<entryCount; i++) {
        if(strstr(diary[i].title, keyword) != NULL || strstr(diary[i].content, keyword) != NULL) {
            found = true;
            searchResults[resultCount++] = i;
        }
    }

    if(found) {
        printf("Search results:\n");
        for(int i=0; i<resultCount; i++) {
            printf("Result %d\n", i+1);
            printf("Title: %s", diary[searchResults[i]].title);
            printf("Content: %s", diary[searchResults[i]].content);
            printf("Date: %s", diary[searchResults[i]].date);
            printf("Time: %s\n", diary[searchResults[i]].time);
        }
    } else {
        printf("No entries found with given keyword.\n");
    }
}

int main() {
    while(true) {
        printf("\nWelcome!\n");
        printf("1. Add Entry\n");
        printf("2. Display All Entries\n");
        printf("3. Search Entries\n");
        printf("4. Exit\n");

        int choice;
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                displayAllEntries();
                break;
            case 3:
                searchEntries();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}