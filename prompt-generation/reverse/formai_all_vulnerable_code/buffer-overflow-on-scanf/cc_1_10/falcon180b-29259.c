//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

struct entry {
    char date[20];
    char time[10];
    char content[MAX_ENTRY_LENGTH];
};

int num_entries = 0;
struct entry diary[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(diary[num_entries].date, sizeof(diary[num_entries].date), "%Y-%m-%d", tm);
    strftime(diary[num_entries].time, sizeof(diary[num_entries].time), "%H:%M:%S", tm);

    printf("Enter your diary entry:\n");
    fgets(diary[num_entries].content, MAX_ENTRY_LENGTH, stdin);

    num_entries++;
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n", diary[i].date, diary[i].time, diary[i].content);
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_LENGTH];

    printf("Enter keyword to search:\n");
    fgets(keyword, MAX_ENTRY_LENGTH, stdin);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].content, keyword)) {
            printf("%s %s\n%s\n", diary[i].date, diary[i].time, diary[i].content);
        }
    }
}

int main() {
    printf("Welcome to Digital Diary!\n");

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
                printf("Invalid choice.\n");
        }
    }

    return 0;
}