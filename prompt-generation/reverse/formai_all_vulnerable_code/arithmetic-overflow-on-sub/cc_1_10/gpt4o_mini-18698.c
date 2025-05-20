//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256

typedef struct {
    char title[50];
    char content[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    printf("Enter the title of the entry: ");
    getchar(); // clear buffer
    fgets(diary[entry_count].title, 50, stdin);
    diary[entry_count].title[strcspn(diary[entry_count].title, "\n")] = 0; // remove newline

    printf("Enter the content of the entry: ");
    fgets(diary[entry_count].content, ENTRY_LENGTH, stdin);
    diary[entry_count].content[strcspn(diary[entry_count].content, "\n")] = 0; // remove newline

    entry_count++;
    printf("Entry added successfully!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No diary entries to display.\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        printf("Entry %d: %s\n", i + 1, diary[i].title);
        printf("Content: %s\n\n", diary[i].content);
    }
}

void update_entry() {
    int index;
    printf("Enter the entry number to update: ");
    scanf("%d", &index);
    index--; // adjust for 0-based index

    if (index < 0 || index >= entry_count) {
        printf("Invalid entry number!\n");
        return;
    }

    printf("Updating entry: %s\n", diary[index].title);
    printf("Enter new title: ");
    getchar(); // clear buffer
    fgets(diary[index].title, 50, stdin);
    diary[index].title[strcspn(diary[index].title, "\n")] = 0; // remove newline

    printf("Enter new content: ");
    fgets(diary[index].content, ENTRY_LENGTH, stdin);
    diary[index].content[strcspn(diary[index].content, "\n")] = 0; // remove newline

    printf("Entry updated successfully!\n");
}

void delete_entry() {
    int index;
    printf("Enter the entry number to delete: ");
    scanf("%d", &index);
    index--; // adjust for 0-based index

    if (index < 0 || index >= entry_count) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = index; i < entry_count - 1; i++) {
        diary[i] = diary[i + 1];
    }

    entry_count--;
    printf("Entry deleted successfully!\n");
}

void display_menu() {
    printf("\nDigital Diary Menu:\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Update Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                update_entry();
                break;
            case 4:
                delete_entry();
                break;
            case 5:
                printf("Exiting the diary program. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}