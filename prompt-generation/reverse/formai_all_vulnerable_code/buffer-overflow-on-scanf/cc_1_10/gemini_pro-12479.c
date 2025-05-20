//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 1024

typedef struct {
    char date[11];
    char title[256];
    char entry[MAX_ENTRY_SIZE];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries == MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    char date[11];
    char title[256];
    char entry[MAX_ENTRY_SIZE];

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", date);

    printf("Enter title: ");
    scanf(" %[^\n]", title); // Read a line of text

    printf("Enter entry: ");
    scanf(" %[^\n]", entry); // Read a line of text

    strcpy(entries[numEntries].date, date);
    strcpy(entries[numEntries].title, title);
    strcpy(entries[numEntries].entry, entry);

    numEntries++;
}

void listEntries() {
    if (numEntries == 0) {
        printf("Diary is empty!\n");
        return;
    }

    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].title);
    }
}

void readEntry() {
    if (numEntries == 0) {
        printf("Diary is empty!\n");
        return;
    }

    char date[11];

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", date);

    int index = -1;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Entry not found!\n");
        return;
    }

    printf("%s: %s\n%s\n", entries[index].date, entries[index].title, entries[index].entry);
}

void deleteEntry() {
    if (numEntries == 0) {
        printf("Diary is empty!\n");
        return;
    }

    char date[11];

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", date);

    int index = -1;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].date, date) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Entry not found!\n");
        return;
    }

    for (int i = index; i < numEntries - 1; i++) {
        entries[i] = entries[i + 1];
    }

    numEntries--;
}

int main() {
    int choice;

    do {
        printf("\nDigital Diary\n");
        printf("1. Add entry\n");
        printf("2. List entries\n");
        printf("3. Read entry\n");
        printf("4. Delete entry\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                listEntries();
                break;
            case 3:
                readEntry();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}