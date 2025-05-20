//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 200

struct entry {
    time_t timestamp;
    char text[ENTRY_LENGTH];
};

void add_entry(struct entry* entries, int count, char* text) {
    if (count >= MAX_ENTRIES) {
        printf("Maximum number of entries reached.\n");
        return;
    }

    entries[count].timestamp = time(NULL);
    strncpy(entries[count].text, text, ENTRY_LENGTH);

    printf("Entry added successfully.\n");
}

void view_entries(struct entry* entries, int count) {
    printf("Viewing entries:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", ctime(&entries[i].timestamp));
        printf("%s\n\n", entries[i].text);
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    while (1) {
        printf("1. Add entry\n2. View entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char text[ENTRY_LENGTH];
                printf("Enter your entry:\n");
                scanf("%[^\n]", text);
                add_entry(entries, count, text);
                break;
            }
            case 2: {
                view_entries(entries, count);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}