//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* new_entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        exit(1);
    }

    char date[20];
    time_t now = time(NULL);
    strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", localtime(&now));

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, new_entry);

    num_entries++;
}

void view_entries() {
    printf("Digital Diary\n");
    printf("-----------------\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries(char* keyword) {
    printf("Search results for '%s':\n", keyword);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s: %s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to your Digital Diary!\n");
    printf("-----------------\n");

    char input[MAX_ENTRY_LENGTH];
    while (1) {
        printf("\nWhat would you like to do? (A)dd an entry, (V)iew entries, (S)earch entries, or (Q)uit? ");
        scanf("%s", input);

        switch (input[0]) {
            case 'A':
                printf("Enter your new entry: ");
                scanf("%s", input);
                add_entry(input);
                break;
            case 'V':
                view_entries();
                break;
            case 'S':
                printf("Enter a keyword to search for: ");
                scanf("%s", input);
                search_entries(input);
                break;
            case 'Q':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}