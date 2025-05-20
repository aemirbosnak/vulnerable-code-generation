//FormAI DATASET v1.0 Category: Digital Diary ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct entry {
    char date[11];
    char time[11];
    char title[50];
    char content[500];
} Entry;

void add_entry(Entry *entries, int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }

    printf("Enter the date in DD/MM/YYYY format: ");
    scanf("%s", entries[*count].date);

    printf("Enter the time in HH:MM format: ");
    scanf("%s", entries[*count].time);

    printf("Enter the title: ");
    scanf("%s", entries[*count].title);

    printf("Enter the content: ");
    scanf(" %[^\n]s", entries[*count].content);

    printf("\nEntry added successfully.\n\n");

    (*count)++;
}

void view_entry(Entry entry) {
    printf("\n%s %s\n", entry.date, entry.time);
    printf("%s\n", entry.title);
    printf("%s\n", entry.content);
}

void view_diary(Entry *entries, int count) {
    if (count == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("\nEntries in diary:\n");

    for (int i = 0; i < count; i++) {
        view_entry(entries[i]);
    }

    printf("\n");
}

void search_diary(Entry *entries, int count) {
    if (count == 0) {
        printf("Diary is empty.\n");
        return;
    }

    char search_term[50];
    printf("Enter search term: ");
    scanf("%s", search_term);

    int found_entries = 0;

    printf("\nSearch results:\n");

    for (int i = 0; i < count; i++) {
        if (strstr(entries[i].title, search_term) != NULL || strstr(entries[i].content, search_term) != NULL) {
            view_entry(entries[i]);
            found_entries++;
        }
    }

    if (found_entries == 0) {
        printf("No entries found.\n");
    }

    printf("\n");
}

int main() {
    Entry diary[MAX_ENTRIES];
    int count = 0;

    printf("Digital Diary\n");

    while (1) {
        printf("1. Add entry\n");
        printf("2. View diary\n");
        printf("3. Search diary\n");
        printf("4. Exit\n\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(diary, &count);
                break;
            case 2:
                view_diary(diary, count);
                break;
            case 3:
                search_diary(diary, count);
                break;
            case 4:
                printf("Exiting diary.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    }

    return 0;
}