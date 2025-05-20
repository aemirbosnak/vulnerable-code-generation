//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[ENTRY_LENGTH];
} Entry;

void add_entry(Entry* diary, int num_entries, char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }
    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].entry, entry);
    num_entries++;
}

void display_entries(Entry* diary, int num_entries) {
    printf("Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].entry);
    }
}

void search_entry(Entry* diary, int num_entries, char* keyword) {
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].entry, keyword)!= NULL) {
            printf("%s - %s\n", diary[i].date, diary[i].entry);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found.\n");
    }
}

int main() {
    Entry diary[MAX_ENTRIES];
    int num_entries = 0;
    char date[20];
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);
    strftime(date, 20, "%Y-%m-%d", timeinfo);

    while (1) {
        printf("1. Add entry\n2. Display entries\n3. Search entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char entry[ENTRY_LENGTH];
                printf("Enter your entry:\n");
                scanf("%[^\n]", entry);
                add_entry(diary, num_entries, date, entry);
                break;
            }
            case 2: {
                display_entries(diary, num_entries);
                break;
            }
            case 3: {
                char keyword[ENTRY_LENGTH];
                printf("Enter keyword to search:\n");
                scanf("%[^\n]", keyword);
                search_entry(diary, num_entries, keyword);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}