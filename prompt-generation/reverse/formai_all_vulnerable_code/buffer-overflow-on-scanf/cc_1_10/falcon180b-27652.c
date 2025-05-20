//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char text[MAX_ENTRY_LENGTH];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* new_entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Digital diary is full.\n");
        return;
    }

    time_t now = time(NULL);
    strncpy(entries[num_entries].text, new_entry, MAX_ENTRY_LENGTH);
    entries[num_entries].timestamp = now;

    printf("Entry added at %s:\n%s\n", ctime(&now), new_entry);

    num_entries++;
}

void list_entries() {
    if (num_entries == 0) {
        printf("Digital diary is empty.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d:\n%s\n", i+1, entries[i].text);
        printf("Timestamp: %s\n\n", ctime(&entries[i].timestamp));
    }
}

int main() {
    srand(time(NULL));

    int choice;
    char new_entry[MAX_ENTRY_LENGTH];

    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n2. List entries\n3. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your entry (max 5000 characters):\n");
                fgets(new_entry, MAX_ENTRY_LENGTH, stdin);
                add_entry(new_entry);
                break;
            case 2:
                list_entries();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}