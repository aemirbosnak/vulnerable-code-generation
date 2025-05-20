//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[ENTRY_LENGTH];
} Entry;

void add_entry(Entry* diary, int num_entries, char* date, char* entry) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            printf("Entry for %s already exists.\n", date);
            return;
        }
    }
    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].entry, entry);
    num_entries++;
}

void view_entries(Entry* diary, int num_entries) {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s:\n%s\n\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    Entry diary[MAX_ENTRIES];
    int num_entries = 0;
    char date[20];
    char entry[ENTRY_LENGTH];

    while (1) {
        printf("Digital Diary\n");
        printf("1. Add entry\n2. View entries\n3. Exit\n");
        scanf("%d", &num_entries);

        switch (num_entries) {
        case 1:
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", date);
            printf("Enter entry:\n");
            fgets(entry, ENTRY_LENGTH, stdin);
            entry[strcspn(entry, "\n")] = '\0'; // Remove newline character
            add_entry(diary, num_entries, date, entry);
            break;
        case 2:
            view_entries(diary, num_entries);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}