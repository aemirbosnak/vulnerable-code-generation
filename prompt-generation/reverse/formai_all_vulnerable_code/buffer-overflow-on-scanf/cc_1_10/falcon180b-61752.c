//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* time, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].time, time);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void display_entries() {
    printf("Digital Diary\n");
    printf("-----------------------------\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

int main() {
    srand(time(NULL));
    int choice;
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];

    while (1) {
        printf("1. Add Entry\n2. Display Entries\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter Time (HH:MM:SS): ");
                scanf("%s", time);
                printf("Enter Entry:\n");
                fgets(entry, MAX_ENTRY_LENGTH, stdin);
                entry[strcspn(entry, "\n")] = '\0'; // Remove newline character
                add_entry(date, time, entry);
                break;
            case 2:
                display_entries();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}