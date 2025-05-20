//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void display_entries() {
    printf("Date\t\tEntry\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t\t%s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    int choice;
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    while (1) {
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Date (dd/mm/yyyy): ");
            scanf("%s", date);
            printf("Enter Entry: ");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);
            entry[strcspn(entry, "\n")] = '\0';
            add_entry(date, entry);
            break;
        case 2:
            display_entries();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}