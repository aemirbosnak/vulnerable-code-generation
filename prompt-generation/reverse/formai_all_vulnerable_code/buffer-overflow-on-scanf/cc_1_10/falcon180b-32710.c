//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_SIZE];
} Entry;

void print_entries(Entry entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void add_entry(Entry entries[], int num_entries) {
    char date[20];
    time_t now = time(NULL);
    strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", localtime(&now));

    printf("Enter your entry (max %d characters): ", MAX_ENTRY_SIZE - 1);
    char entry[MAX_ENTRY_SIZE];
    scanf("%[^\n]", entry);

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

int main() {
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (num_entries < MAX_ENTRIES) {
        printf("Press 1 to add an entry\n");
        printf("Press 2 to view entries\n");
        printf("Press 3 to exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(entries, num_entries);
                break;
            case 2:
                print_entries(entries, num_entries);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}