//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_SIZE];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Sorry, diary is full!\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(entries[num_entries].date, 20, "%Y-%m-%d %H:%M:%S", t);

    printf("What's on your mind today?\n");
    fgets(entries[num_entries].entry, MAX_ENTRY_SIZE, stdin);

    num_entries++;
}

void view_entry(int index) {
    if (index >= 0 && index < num_entries) {
        printf("Entry on %s:\n%s\n", entries[index].date, entries[index].entry);
    } else {
        printf("Invalid entry index!\n");
    }
}

void delete_entry(int index) {
    if (index >= 0 && index < num_entries) {
        memmove(&entries[index], &entries[index+1], sizeof(Entry) * (num_entries - index - 1));
        num_entries--;
        printf("Entry deleted.\n");
    } else {
        printf("Invalid entry index!\n");
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Diary Menu:\n");
        printf("1. Add entry\n");
        printf("2. View entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                printf("Enter entry index (0-%d): ", num_entries - 1);
                int index;
                scanf("%d", &index);
                view_entry(index);
                break;
            case 3:
                printf("Enter entry index (0-%d): ", num_entries - 1);
                int index2;
                scanf("%d", &index2);
                delete_entry(index2);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}