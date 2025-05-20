//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_SIZE];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    char dateStr[20];
    time_t now = time(NULL);
    strftime(dateStr, 20, "%Y-%m-%d", localtime(&now));

    printf("Enter your diary entry for %s:\n", dateStr);
    fgets(entries[numEntries].entry, MAX_ENTRY_SIZE, stdin);
    strcpy(entries[numEntries].date, dateStr);
    numEntries++;
}

void viewEntries() {
    int i;
    for(i=0; i<numEntries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void searchEntry() {
    char keyword[MAX_ENTRY_SIZE];
    printf("Enter keyword to search: ");
    fgets(keyword, MAX_ENTRY_SIZE, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    int i;
    for(i=0; i<numEntries; i++) {
        if(strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s: %s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nDigital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 4);

    return 0;
}