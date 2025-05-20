//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);

    num_entries++;
}

void display_entries() {
    printf("Digital Diary Entries:\n");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char input[MAX_ENTRY_LENGTH];

    while (1) {
        printf("\nEnter command (add, display, exit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            char date[11];
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", date);

            char entry[MAX_ENTRY_LENGTH];
            printf("Enter entry: ");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);

            add_entry(date, entry);
        } else if (strcmp(input, "display") == 0) {
            display_entries();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}