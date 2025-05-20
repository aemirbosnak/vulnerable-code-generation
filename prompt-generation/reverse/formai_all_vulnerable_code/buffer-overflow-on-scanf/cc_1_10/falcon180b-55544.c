//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char time[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(entries[num_entries].date, 20, "%Y-%m-%d", tm);
    strftime(entries[num_entries].time, 20, "%H:%M:%S", tm);
    printf("Enter your entry (max %d characters):\n", MAX_ENTRY_LENGTH - 1);
    scanf("%s", entries[num_entries].entry);
    num_entries++;
    printf("Entry added!\n");
}

void view_entries() {
    printf("Viewing entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

void search_entries() {
    char search_term[MAX_ENTRY_LENGTH];
    printf("Enter search term:\n");
    scanf("%s", search_term);
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, search_term)) {
            printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].entry);
        }
    }
}

int main() {
    while (1) {
        printf("1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
        int choice;
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
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}