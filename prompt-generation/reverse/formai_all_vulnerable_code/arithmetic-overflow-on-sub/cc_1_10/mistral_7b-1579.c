//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 50
#define ENTRY_SIZE 200

typedef struct {
    char title[50];
    char content[ENTRY_SIZE];
    time_t timestamp;
} Entry;

Entry diary[DIARY_SIZE];
int diary_size = 0;

void save_entry() {
    if (diary_size >= DIARY_SIZE) {
        printf("Your digital diary is full. You cannot save another entry.\n");
        return;
    }

    time_t now = time(NULL);
    Entry *new_entry = &diary[diary_size];

    printf("Enter the title of your new entry: ");
    scanf("%s", new_entry->title);

    printf("Enter the content of your new entry: ");
    getchar();
    fgets(new_entry->content, ENTRY_SIZE, stdin);

    new_entry->timestamp = now;
    diary_size++;

    printf("Entry saved successfully.\n");
}

void load_entry(int index) {
    if (index < 0 || index >= diary_size) {
        printf("Invalid entry index.\n");
        return;
    }

    Entry *entry = &diary[index];
    printf("Title: %s\n", entry->title);
    printf("Content:\n%s", entry->content);
    printf("Timestamp: %s\n", ctime(&entry->timestamp));
}

void delete_entry(int index) {
    if (index < 0 || index >= diary_size) {
        printf("Invalid entry index.\n");
        return;
    }

    memmove(&diary[index], &diary[index + 1], (diary_size - index - 1) * sizeof(Entry));
    diary_size--;

    printf("Entry deleted successfully.\n");
}

void list_entries() {
    if (diary_size == 0) {
        printf("Your digital diary is empty.\n");
        return;
    }

    printf("List of entries in your digital diary:\n");
    for (int i = 0; i < diary_size; i++) {
        Entry *entry = &diary[i];
        printf("%d. %s (%s)\n", i + 1, entry->title, ctime(&entry->timestamp));
    }
}

int main() {
    int choice;
    int index;

    while (1) {
        printf("\nWelcome to your C Digital Diary! What would you like to do?\n");
        printf("1. Save a new entry\n2. Load an existing entry\n3. Delete an entry\n4. List all entries\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                save_entry();
                break;
            case 2:
                printf("Enter the index of the entry you'd like to load: ");
                scanf("%d", &index);
                load_entry(index - 1);
                break;
            case 3:
                printf("Enter the index of the entry you'd like to delete: ");
                scanf("%d", &index);
                delete_entry(index - 1);
                break;
            case 4:
                list_entries();
                break;
            case 5:
                printf("Goodbye! Have a nice day.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}