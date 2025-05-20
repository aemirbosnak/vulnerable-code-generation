//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct DiaryEntry {
    char title[50];
    char content[200];
    time_t timestamp;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int currentEntry = 0;

void printMenu() {
    printf("\n----- Digital Diary -----\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Edit Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
}

void addEntry(const char *title, const char *content) {
    if (currentEntry >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }
    strcpy(diary[currentEntry].title, title);
    strcpy(diary[currentEntry].content, content);
    diary[currentEntry].timestamp = time(NULL);
    currentEntry++;
}

void viewEntries() {
    if (currentEntry == 0) {
        printf("No entries.\n");
        return;
    }

    for (int i = 0; i < currentEntry; i++) {
        printf("\nTitle: %s\n", diary[i].title);
        printf("Content: %s\n", diary[i].content);
        printf("Timestamp: %s", ctime(&diary[i].timestamp));
    }
}

int main() {
    char title[50], content[200];
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter content: ");
                scanf("%[^\n]s", content);
                addEntry(title, content);
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                // TODO: Edit Entry
                break;
            case 4:
                // TODO: Delete Entry
                break;
            case 5:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}