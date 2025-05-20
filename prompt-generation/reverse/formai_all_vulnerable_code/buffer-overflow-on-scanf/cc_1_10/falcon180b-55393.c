//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char entry[500];
} entry_t;

void add_entry(entry_t* entries, int num_entries, char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void view_entries(entry_t* entries, int num_entries) {
    printf("Diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n%s\n\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int num_entries = 0;

    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char date[20];
    strftime(date, sizeof(date), "%Y-%m-%d", t);

    printf("Welcome to your digital diary! (c) 2021\n");

    while (1) {
        printf("Enter your entry for %s:\n", date);
        fgets(entries[num_entries].entry, sizeof(entries[num_entries].entry), stdin);

        add_entry(entries, num_entries, date, entries[num_entries].entry);

        printf("Entry saved.\n");

        char choice;
        printf("Press 'v' to view diary or 'q' to quit: ");
        scanf("%c", &choice);

        if (choice == 'v' || choice == 'V') {
            view_entries(entries, num_entries);
        } else if (choice == 'q' || choice == 'Q') {
            break;
        }
    }

    return 0;
}