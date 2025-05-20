//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_SIZE 5000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_SIZE];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void add_entry(char* date, char* entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

int main() {
    char input[100];
    char date[20];
    char entry[MAX_ENTRY_SIZE];
    int choice;

    while (1) {
        printf("Welcome to the Digital Diary!\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter your entry:\n");
                fgets(entry, MAX_ENTRY_SIZE, stdin);
                entry[strcspn(entry, "\n")] = '\0'; // remove newline character
                add_entry(date, entry);
                printf("Entry added!\n");
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