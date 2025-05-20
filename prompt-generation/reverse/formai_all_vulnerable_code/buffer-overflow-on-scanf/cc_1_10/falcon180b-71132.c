//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char date[20];
    char entry[5000];
} DiaryEntry;

int numEntries = 0;
DiaryEntry diary[MAX_ENTRIES];

void addEntry() {
    char date[20];
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", date);
    printf("Enter entry:\n");
    fgets(diary[numEntries].entry, 5000, stdin);
    strcpy(diary[numEntries].date, date);
    numEntries++;
    printf("Entry added.\n");
}

void viewEntries() {
    int i;
    for(i=0; i<numEntries; i++) {
        printf("%s\n%s\n", diary[i].date, diary[i].entry);
    }
}

void searchEntry() {
    char searchDate[20];
    printf("Enter date to search (YYYY-MM-DD): ");
    scanf("%s", searchDate);
    int i;
    for(i=0; i<numEntries; i++) {
        if(strcmp(diary[i].date, searchDate) == 0) {
            printf("%s\n%s\n", diary[i].date, diary[i].entry);
        }
    }
}

void deleteEntry() {
    char searchDate[20];
    printf("Enter date to delete (YYYY-MM-DD): ");
    scanf("%s", searchDate);
    int i;
    for(i=0; i<numEntries; i++) {
        if(strcmp(diary[i].date, searchDate) == 0) {
            strcpy(diary[i].date, "");
            strcpy(diary[i].entry, "");
            printf("Entry deleted.\n");
            break;
        }
    }
}

int main() {
    int choice;
    do {
        printf("Digital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Search Entry\n");
        printf("4. Delete Entry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 5);
    return 0;
}