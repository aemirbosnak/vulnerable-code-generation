//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strncpy(entries[num_entries].date, date, 20);
    strncpy(entries[num_entries].entry, entry, MAX_ENTRY_LENGTH);
    num_entries++;
}

void view_entries() {
    printf("Digital Diary Entries:\n");
    printf("------------------------\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries(char* keyword) {
    printf("Search Results:\n");
    printf("----------------\n");
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)) {
            printf("%s - %s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    char input[100];
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    printf("Welcome to Digital Diary!\n");
    printf("------------------------\n");

    while (1) {
        printf("\nEnter command (add/view/search/exit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", date);
            printf("Enter entry: ");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);
            entry[strcspn(entry, "\n")] = '\0';
            add_entry(date, entry);
            printf("Entry added successfully!\n");
        } else if (strcmp(input, "view") == 0) {
            view_entries();
        } else if (strcmp(input, "search") == 0) {
            printf("Enter search keyword: ");
            scanf("%s", input);
            search_entries(input);
        } else if (strcmp(input, "exit") == 0) {
            printf("Exiting Digital Diary...\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}