//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

diary_entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    strftime(entries[num_entries].date, 20, "%Y-%m-%d", t);
    printf("Enter your diary entry for %s:\n", entries[num_entries].date);
    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
    num_entries++;
}

void view_entries() {
    printf("Diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

void delete_entry() {
    printf("Enter the date of the entry you want to delete (YYYY-MM-DD):\n");
    char delete_date[20];
    fgets(delete_date, 20, stdin);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(delete_date, entries[i].date) == 0) {
            memmove(&entries[i], &entries[i + 1], sizeof(diary_entry) * (num_entries - i - 1));
            num_entries--;
            break;
        }
    }
}

int main() {
    printf("Welcome to your digital diary!\n");
    while (1) {
        printf("\n");
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Delete an entry\n");
        printf("4. Exit\n");
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
                delete_entry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}