//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached.\n");
        return;
    }
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void display_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }
    printf("Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries(char* keyword) {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }
    printf("Search results:\n");
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s: %s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    char date[20];
    time_t now = time(NULL);
    strftime(date, sizeof(date), "%Y-%m-%d", localtime(&now));

    while (1) {
        printf("Enter command (add/display/search/exit): ");
        scanf("%s", date);
        if (strcmp(date, "add") == 0) {
            char entry[MAX_ENTRY_LENGTH];
            printf("Enter entry: ");
            scanf("%[^\n]", entry);
            add_entry(date, entry);
        } else if (strcmp(date, "display") == 0) {
            display_entries();
        } else if (strcmp(date, "search") == 0) {
            char keyword[MAX_ENTRY_LENGTH];
            printf("Enter keyword: ");
            scanf("%[^\n]", keyword);
            search_entries(keyword);
        } else if (strcmp(date, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}