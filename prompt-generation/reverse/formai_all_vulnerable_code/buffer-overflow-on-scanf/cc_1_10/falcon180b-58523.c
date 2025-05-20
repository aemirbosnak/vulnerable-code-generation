//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry diary[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char* date, char* entry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }

    strcpy(diary[numEntries].date, date);
    strcpy(diary[numEntries].entry, entry);

    numEntries++;
}

void displayEntries() {
    int i;
    for (i = 0; i < numEntries; i++) {
        printf("%s\n%s\n", diary[i].date, diary[i].entry);
    }
}

void searchEntry(char* keyword) {
    int i;
    for (i = 0; i < numEntries; i++) {
        if (strstr(diary[i].entry, keyword)) {
            printf("%s\n%s\n", diary[i].date, diary[i].entry);
        }
    }
}

int main() {
    char choice;
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n2. Display entries\n3. Search entry\n4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter date (dd/mm/yyyy): ");
                scanf("%s", date);
                printf("Enter entry:\n");
                fgets(entry, MAX_ENTRY_LENGTH, stdin);
                addEntry(date, entry);
                break;
            case '2':
                displayEntries();
                break;
            case '3':
                printf("Enter keyword to search: ");
                scanf("%s", entry);
                searchEntry(entry);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '4');

    return 0;
}