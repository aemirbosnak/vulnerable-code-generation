//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LEN 1024

typedef struct {
    char date[11];
    char time[9];
    char entry[MAX_ENTRY_LEN];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(entries[num_entries].date, sizeof(entries[num_entries].date), "%Y-%m-%d", tm);
    strftime(entries[num_entries].time, sizeof(entries[num_entries].time), "%H:%M:%S", tm);

    printf("Enter your diary entry:\n");
    fgets(entries[num_entries].entry, sizeof(entries[num_entries].entry), stdin);

    num_entries++;
}

void view_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

void search_entries() {
    char search_term[MAX_ENTRY_LEN];
    printf("Enter the search term:\n");
    fgets(search_term, sizeof(search_term), stdin);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, search_term) != NULL) {
            printf("%s %s\n%s\n\n", entries[i].date, entries[i].time, entries[i].entry);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("Digital Diary\n");
        printf("1. Add an entry\n");
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
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}