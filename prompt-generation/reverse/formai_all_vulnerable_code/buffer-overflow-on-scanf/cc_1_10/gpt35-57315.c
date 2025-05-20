//FormAI DATASET v1.0 Category: Digital Diary ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 200

void add_entry();
void view_entry();
void search_entry();
void delete_entry();
void print_menu();
void clear_buffer();

struct diary_entry {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
};

struct diary_entry diary[MAX_ENTRIES];
int entry_count = 0;

int main() {
    int choice;
    char c;

    do {
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
                search_entry();
                break;
            case 4:
                delete_entry();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please choose again.\n");
        }

        clear_buffer();
    } while (choice != 5);

    return 0;
}

void print_menu() {
    printf("\n--- Digital Diary ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. Search Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Exit Program\n");
    printf("Choose an option: ");
}

void add_entry() {
    printf("\n--- Add Entry ---\n");

    struct diary_entry new_entry;

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", new_entry.date);

    printf("Enter your entry (max length %d): ", MAX_ENTRY_LENGTH);
    getchar();
    fgets(new_entry.entry, MAX_ENTRY_LENGTH, stdin);

    diary[entry_count++] = new_entry;

    printf("Entry added successfully!\n");
}

void view_entry() {
    int i, j;
    char c;
    printf("\n--- View Entries ---\n");

    if (entry_count == 0) {
        printf("No entries found.\n");
        return;
    }

    for (i = 0; i < entry_count; i++) {
        printf("Date: %s\n", diary[i].date);

        printf("Entry:\n");
        for (j = 0; j < strlen(diary[i].entry); j++) {
            printf("%c", diary[i].entry[j]);
            if ((j+1)%50 == 0) {
                printf("\n");
            }
        }

        printf("\n\n");
    }

    printf("\nPress any key to continue...");
    scanf("%1s", &c); // use %1s to only read 1 character
}

void search_entry() {
    int i, found = 0;
    char date[20];

    printf("\n--- Search Entry ---\n");

    if (entry_count == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", date);

    for (i = 0; i < entry_count; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            printf("Entry found:\n");
            printf("Date: %s\n", diary[i].date);
            printf("Entry:\n%s\n", diary[i].entry);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}

void delete_entry() {
    int i, j, found = 0;
    char date[20];

    printf("\n--- Delete Entry ---\n");

    if (entry_count == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", date);

    for (i = 0; i < entry_count; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            found = 1;

            for (j = i; j < entry_count-1; j++) {
                diary[j] = diary[j+1];
            }

            entry_count--;
            printf("Entry deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}

void clear_buffer() {
    while(getchar() != '\n');
}