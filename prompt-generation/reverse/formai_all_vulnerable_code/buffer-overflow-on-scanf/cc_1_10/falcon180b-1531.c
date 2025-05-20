//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define ENTRY_LENGTH 500

typedef struct {
    int id;
    char date[20];
    char content[ENTRY_LENGTH];
} Entry;

Entry diary[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    printf("Enter entry ID (1-%d): ", MAX_ENTRIES-1);
    scanf("%d", &diary[numEntries].id);

    time_t now = time(NULL);
    strftime(diary[numEntries].date, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    printf("Enter content (up to %d characters): ", ENTRY_LENGTH-1);
    scanf("%s", diary[numEntries].content);

    numEntries++;
    printf("Entry added.\n");
}

void viewEntry(int id) {
    for (int i = 0; i < numEntries; i++) {
        if (diary[i].id == id) {
            printf("ID: %d\nDate: %s\nContent:\n%s\n", diary[i].id, diary[i].date, diary[i].content);
            return;
        }
    }

    printf("Entry not found.\n");
}

void deleteEntry(int id) {
    for (int i = 0; i < numEntries; i++) {
        if (diary[i].id == id) {
            for (int j = i; j < numEntries-1; j++) {
                diary[j] = diary[j+1];
            }
            numEntries--;
            printf("Entry deleted.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    printf("Digital Diary\n");

    int choice;
    while (1) {
        printf("1. Add entry\n2. View entry\n3. Delete entry\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEntry();
            break;
        case 2:
            printf("Enter entry ID: ");
            scanf("%d", &choice);
            viewEntry(choice);
            break;
        case 3:
            printf("Enter entry ID: ");
            scanf("%d", &choice);
            deleteEntry(choice);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}