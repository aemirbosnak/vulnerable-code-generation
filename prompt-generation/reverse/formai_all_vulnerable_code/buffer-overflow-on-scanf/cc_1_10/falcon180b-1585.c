//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LEN 1000

typedef struct {
    char date[10];
    char entry[MAX_ENTRY_LEN];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void view_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries(char* keyword) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s - %s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    int choice;
    char date[10];
    char entry[MAX_ENTRY_LEN];

    while (1) {
        printf("Digital Diary\n");
        printf("1. Add Entry\n2. View Entries\n3. Search Entries\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter Entry: ");
                scanf("%s", entry);
                add_entry(date, entry);
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("Enter Keyword: ");
                scanf("%s", entry);
                search_entries(entry);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}