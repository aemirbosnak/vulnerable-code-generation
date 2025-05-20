//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void display_entries() {
    printf("Date\tEntry\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries(char* keyword) {
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)!= NULL) {
            printf("%s\t%s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
    char keyword[MAX_ENTRY_LENGTH];

    time_t now = time(NULL);
    strftime(date, sizeof(date), "%Y-%m-%d", localtime(&now));

    while (1) {
        printf("Enter entry (leave blank to exit):\n");
        fgets(entry, MAX_ENTRY_LENGTH, stdin);
        if (feof(stdin)) {
            break;
        }

        if (strlen(entry) > 0) {
            add_entry(date, entry);
        }
    }

    while (1) {
        printf("\nChoose an option:\n1. Display entries\n2. Search entries\n3. Exit\n");
        scanf("%d", &num_entries);

        switch (num_entries) {
            case 1:
                display_entries();
                break;
            case 2:
                printf("Enter keyword:\n");
                scanf("%s", keyword);
                search_entries(keyword);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}