//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
} diary_entry;

int num_entries = 0;
diary_entry entries[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(entries[num_entries].date, sizeof(entries[num_entries].date), "%Y-%m-%d", t);
    strftime(entries[num_entries].time, sizeof(entries[num_entries].time), "%H:%M:%S", t);

    printf("Enter your entry:\n");
    fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, stdin);

    num_entries++;
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n", entries[i].date, entries[i].time, entries[i].content);
    }
}

void search_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    char keyword[MAX_ENTRY_LENGTH];
    printf("Enter a keyword to search for:\n");
    fgets(keyword, MAX_ENTRY_LENGTH, stdin);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].content, keyword)) {
            printf("%s %s\n%s\n", entries[i].date, entries[i].time, entries[i].content);
        }
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Digital Diary - %d\n", 2100 + rand() % 100);
        printf("1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
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
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}