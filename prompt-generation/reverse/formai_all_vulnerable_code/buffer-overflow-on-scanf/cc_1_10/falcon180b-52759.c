//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

int num_entries = 0;
struct entry diary[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", diary[num_entries].date);

    printf("Enter time (HH:MM:SS): ");
    scanf("%s", diary[num_entries].time);

    printf("Enter content:\n");
    char content[MAX_ENTRY_LENGTH];
    fgets(content, MAX_ENTRY_LENGTH, stdin);
    strcpy(diary[num_entries].content, content);

    num_entries++;
}

void view_entries() {
    if (num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("Viewing %d entries:\n", num_entries);
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n", diary[i].date, diary[i].time, diary[i].content);
    }
}

void search_entries() {
    if (num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("Enter keyword to search: ");
    char keyword[MAX_ENTRY_LENGTH];
    scanf("%s", keyword);

    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].content, keyword)!= NULL) {
            printf("%s %s\n%s\n", diary[i].date, diary[i].time, diary[i].content);
            found = 1;
        }
    }

    if (!found) {
        printf("No entries found.\n");
    }
}

int main() {
    printf("Welcome to Digital Diary!\n");

    while (1) {
        printf("\n1. Add entry\n2. View entries\n3. Search entries\n4. Exit\n");
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
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}