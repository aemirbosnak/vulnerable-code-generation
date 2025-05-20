//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LEN 1000

typedef struct {
    char text[MAX_ENTRY_LEN];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Sorry, the diary is full! Try deleting some entries.\n");
        return;
    }

    printf("What's on your mind today?\n");
    fgets(entries[num_entries].text, MAX_ENTRY_LEN, stdin);
    entries[num_entries].timestamp = time(NULL);
    num_entries++;

    printf("Entry added successfully!\n");
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries yet. Add one using 'add_entry'.\n");
        return;
    }

    printf("Diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("[%s] %s\n", ctime(&entries[i].timestamp), entries[i].text);
    }
}

void delete_entry() {
    if (num_entries == 0) {
        printf("No entries yet. Add one using 'add_entry'.\n");
        return;
    }

    int index;
    printf("Which entry would you like to delete?\n");
    scanf("%d", &index);

    if (index < 0 || index >= num_entries) {
        printf("Invalid index.\n");
        return;
    }

    num_entries--;
    for (int i = index; i < num_entries; i++) {
        entries[i] = entries[i + 1];
    }

    printf("Entry deleted successfully!\n");
}

int main() {
    srand(time(NULL));
    printf("Welcome to your digital diary!\n");

    int choice;
    do {
        printf("What would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Delete an entry\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}