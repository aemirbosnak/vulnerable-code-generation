//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[11];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char input[MAX_ENTRY_LENGTH];
    char date_str[11];
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    strftime(date_str, 11, "%Y-%m-%d", tm_now);

    printf("Enter your entry for %s:\n", date_str);
    fgets(input, MAX_ENTRY_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    strncpy(entries[num_entries].date, date_str, 11);
    strncpy(entries[num_entries].entry, input, MAX_ENTRY_LENGTH);

    num_entries++;
}

void view_entries() {
    printf("Viewing entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries() {
    char search_term[MAX_ENTRY_LENGTH];

    printf("Enter search term:\n");
    fgets(search_term, MAX_ENTRY_LENGTH, stdin);
    search_term[strcspn(search_term, "\n")] = '\0';

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, search_term)) {
            printf("%s: %s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));
    int choice;

    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entries();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}