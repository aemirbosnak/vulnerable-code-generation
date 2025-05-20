//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 10
#define ENTRY_LEN 256

typedef struct {
    char title[ENTRY_LEN];
    char description[ENTRY_LEN];
    time_t timestamp;
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

void print_menu() {
    printf("\n=== DIGITAL DIARY v1.0 ===\n");
    printf("1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. Delete Entry\n");
    printf("4. View All Entries\n");
    printf("5. Exit\n");
}

int find_empty_slot() {
    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (diary[i].timestamp == 0) {
            return i;
        }
    }
    return -1;
}

void add_entry() {
    int index = find_empty_slot();
    if (index == -1) {
        printf("Error: Diary is full.\n");
        return;
    }

    printf("Enter title: ");
    scanf("%s", diary[index].title);

    printf("Enter description: ");
    scanf("%[^\n]%*c", diary[index].description);

    diary[index].timestamp = time(NULL);
    num_entries++;

    printf("Entry added successfully.\n");
}

void view_entry() {
    int index;
    printf("Enter entry index: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_entries) {
        printf("Error: Invalid entry index.\n");
        return;
    }

    printf("\nTitle: %s\n", diary[index].title);
    printf("Description: %s\n", diary[index].description);
    printf("Timestamp: %s", ctime(&diary[index].timestamp));
}

void delete_entry() {
    int index;
    printf("Enter entry index: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_entries) {
        printf("Error: Invalid entry index.\n");
        return;
    }

    memset(&diary[index], 0, sizeof(Entry));
    num_entries--;

    printf("Entry deleted successfully.\n");
}

void view_all_entries() {
    printf("\n=== ALL ENTRIES ===\n");
    for (int i = 0; i < num_entries; i++) {
        printf("\nTitle: %s\n", diary[i].title);
        printf("Description: %s\n", diary[i].description);
        printf("Timestamp: %s", ctime(&diary[i].timestamp));
    }
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entry();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                view_all_entries();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}