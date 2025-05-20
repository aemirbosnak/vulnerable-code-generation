//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 500
#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *date, char *entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void view_entries() {
    printf("Digital Diary\n");
    printf("--------------------\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
    printf("\n");
}

void search_entry(char *keyword) {
    printf("Search results for '%s':\n", keyword);
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s - %s\n", entries[i].date, entries[i].entry);
        }
    }
    printf("\n");
}

int main() {
    char input[100];
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
    int choice;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", date);
            printf("Enter your entry:\n");
            scanf("%[^\n]", entry);
            strcat(entry, "\n");
            add_entry(date, entry);
            break;
        case 2:
            view_entries();
            break;
        case 3:
            printf("Enter keyword to search: ");
            scanf("%s", input);
            search_entry(input);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}