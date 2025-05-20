//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
};

struct entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strncpy(diary[num_entries].date, date, 20);
    strncpy(diary[num_entries].entry, entry, MAX_ENTRY_LENGTH);
    num_entries++;
}

void display_entries() {
    int i;
    printf("Digital Diary Entries:\n");
    for (i = 0; i < num_entries; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
    int choice = 0;

    while (choice!= 4) {
        printf("\nDigital Diary Menu:\n");
        printf("1. Add Entry\n2. Display Entries\n3. Search Entries\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter Entry:\n");
                fgets(entry, MAX_ENTRY_LENGTH, stdin);
                entry[strcspn(entry, "\n")] = '\0';
                add_entry(date, entry);
                break;
            case 2:
                display_entries();
                break;
            case 3:
                printf("Enter keyword to search: ");
                scanf("%s", entry);
                int found = 0;
                int i;
                for (i = 0; i < num_entries; i++) {
                    if (strstr(diary[i].entry, entry)) {
                        printf("%s - %s\n", diary[i].date, diary[i].entry);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("No entries found.\n");
                }
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}