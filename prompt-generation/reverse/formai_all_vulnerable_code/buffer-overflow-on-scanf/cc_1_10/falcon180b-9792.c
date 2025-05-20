//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* entry) {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    strftime(entries[num_entries].date, 20, "%Y-%m-%d %H:%M:%S", tm);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void display_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Date: %s\nEntry: %s\n\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char entry[MAX_ENTRY_LENGTH];
    char input[MAX_ENTRY_LENGTH];
    int choice;

    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n2. Display entries\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your entry: ");
                fgets(input, MAX_ENTRY_LENGTH, stdin);
                add_entry(input);
                break;
            case 2:
                display_entries();
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