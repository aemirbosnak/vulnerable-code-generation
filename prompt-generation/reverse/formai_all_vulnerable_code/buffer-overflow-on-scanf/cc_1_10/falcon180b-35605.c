//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 3000

typedef struct {
    char date[20];
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

void print_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("%s\n%s\n\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char input[100];

    while (1) {
        printf("Digital Diary\n");
        printf("1. Add entry\n2. Print entries\n3. Exit\n");
        scanf("%s", input);

        switch (input[0]) {
        case '1':
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", input);
            printf("Enter entry: ");
            fgets(input, 100, stdin);
            input[strcspn(input, "\n")] = '\0';
            add_entry(input, input + 2);
            break;
        case '2':
            print_entries();
            break;
        case '3':
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}