//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LEN 5000

typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LEN];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* input) {
    time_t now = time(NULL);
    strncpy(entries[num_entries].entry, input, MAX_ENTRY_LEN);
    entries[num_entries].timestamp = now;
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d (%ld): %s\n", i+1, entries[i].timestamp, entries[i].entry);
    }
}

int main() {
    srand(time(NULL));
    int choice;
    char input[MAX_ENTRY_LEN];

    do {
        printf("1. Add an entry\n2. Print all entries\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your entry: ");
                fgets(input, MAX_ENTRY_LEN, stdin);
                add_entry(input);
                break;
            case 2:
                print_entries();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}