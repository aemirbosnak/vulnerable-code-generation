//FormAI DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct DiaryEntry {
    char date[11];
    char time[6];
    char message[1000];
};

void printMenu();
void addEntry(struct DiaryEntry [], int *);
void viewEntries(struct DiaryEntry [], int);
void searchEntries(struct DiaryEntry [], int);
void editEntry(struct DiaryEntry [], int);
void deleteEntry(struct DiaryEntry [], int *);

int main() {
    struct DiaryEntry entries[MAX_ENTRIES];
    int numEntries = 0, choice;
    
    while (1) {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry(entries, &numEntries);
                break;
            case 2:
                viewEntries(entries, numEntries);
                break;
            case 3:
                searchEntries(entries, numEntries);
                break;
            case 4:
                editEntry(entries, numEntries);
                break;
            case 5:
                deleteEntry(entries, &numEntries);
                break;
            case 6:
                printf("Thanks for using the digital diary!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1-6.\n");
        }
    }
    return 0;
}

void printMenu() {
    printf("\n");
    printf("Digital Diary Menu:\n");
    printf("--------------------\n");
    printf("1. Add entry\n");
    printf("2. View all entries\n");
    printf("3. Search entry by date\n");
    printf("4. Edit entry\n");
    printf("5. Delete entry\n");
    printf("6. Exit\n");
    printf("--------------------\n");
    printf("Enter your choice (1-6): ");
}

void addEntry(struct DiaryEntry entries[], int *numEntries) {
    if (*numEntries == MAX_ENTRIES) {
        printf("Sorry, the diary is full. You cannot add any more entries.\n");
        return;
    }
    
    printf("Enter today's date (in dd/mm/yyyy format): ");
    scanf("%s", entries[*numEntries].date);
    
    printf("Enter the time of day (in hh:mm format): ");
    scanf("%s", entries[*numEntries].time);
    
    printf("Enter your message: ");
    getchar(); // remove newline character left from scanf
    fgets(entries[*numEntries].message, 1000, stdin);
    
    printf("Entry added successfully.\n");
    (*numEntries)++;
}

void viewEntries(struct DiaryEntry entries[], int numEntries) {
    if (numEntries == 0) {
        printf("There are no entries to display.\n");
        return;
    }
    
    printf("Date        Time   Message\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s   %s   %s", entries[i].date, entries[i].time, entries[i].message);
    }
}

void searchEntries(struct DiaryEntry entries[], int numEntries) {
    if (numEntries == 0) {
        printf("There are no entries to search.\n");
        return;
    }
    
    char searchDate[11];
    printf("Enter the date to search for (in dd/mm/yyyy format): ");
    scanf("%s", searchDate);
    
    printf("Date        Time   Message\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(searchDate, entries[i].date) == 0) {
            printf("%s   %s   %s", entries[i].date, entries[i].time, entries[i].message);
        }
    }
}

void editEntry(struct DiaryEntry entries[], int numEntries) {
    if (numEntries == 0) {
        printf("There are no entries to edit.\n");
        return;
    }
    
    char searchDate[11], newMessage[1000];
    int entryIndex = -1;
    printf("Enter the date of the entry to edit (in dd/mm/yyyy format): ");
    scanf("%s", searchDate);
    
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(searchDate, entries[i].date) == 0) {
            entryIndex = i;
            break;
        }
    }
    
    if (entryIndex == -1) {
        printf("Entry not found.\n");
        return;
    }
    
    printf("Enter new message: ");
    getchar(); // remove newline character left from scanf
    fgets(newMessage, 1000, stdin);
    
    strncpy(entries[entryIndex].message, newMessage, strlen(newMessage));
    printf("Entry edited successfully.\n");
}

void deleteEntry(struct DiaryEntry entries[], int *numEntries) {
    if (*numEntries == 0) {
        printf("There are no entries to delete.\n");
        return;
    }
    
    char searchDate[11];
    int entryIndex = -1;
    printf("Enter the date of the entry to delete (in dd/mm/yyyy format): ");
    scanf("%s", searchDate);
    
    for (int i = 0; i < *numEntries; i++) {
        if (strcmp(searchDate, entries[i].date) == 0) {
            entryIndex = i;
            break;
        }
    }
    
    if (entryIndex == -1) {
        printf("Entry not found.\n");
        return;
    }
    
    for (int i = entryIndex; i < *numEntries - 1; i++) {
        entries[i] = entries[i+1];
    }
    (*numEntries)--;
    printf("Entry deleted successfully.\n");
}