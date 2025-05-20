//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void print_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void add_entry(char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Too many entries.\n");
        return;
    }
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

int main() {
    int choice;
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    srand(time(NULL));

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Add entry\n2. View entries\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", date);
            printf("Enter entry:\n");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);
            entry[strcspn(entry, "\n")] = '\0';
            add_entry(date, entry);
            break;
        case 2:
            print_entries();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}