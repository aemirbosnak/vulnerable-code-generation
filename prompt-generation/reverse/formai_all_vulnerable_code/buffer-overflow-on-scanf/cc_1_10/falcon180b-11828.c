//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", diary[num_entries].date);

    printf("Enter entry: ");
    fgets(diary[num_entries].entry, MAX_ENTRY_LENGTH, stdin);

    num_entries++;
}

void view_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Date: %s\nEntry:\n%s\n\n", diary[i].date, diary[i].entry);
    }
}

void search_entry() {
    char search_date[20];
    printf("Enter date to search (YYYY-MM-DD): ");
    scanf("%s", search_date);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(diary[i].date, search_date) == 0) {
            printf("Date: %s\nEntry:\n%s\n\n", diary[i].date, diary[i].entry);
        }
    }
}

int main() {
    printf("Welcome to the Digital Diary!\n");

    while (1) {
        printf("\n1. Add entry\n2. View entries\n3. Search entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}