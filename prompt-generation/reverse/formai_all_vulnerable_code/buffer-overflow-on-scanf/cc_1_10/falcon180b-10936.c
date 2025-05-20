//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRY_SIZE 1000
#define MAX_ENTRIES 100

struct entry {
    char date[20];
    char time[10];
    char content[MAX_ENTRY_SIZE];
};

int num_entries = 0;
struct entry diary[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    struct entry *entry = &diary[num_entries];

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", entry->date);

    printf("Enter time (HH:MM:SS): ");
    scanf("%s", entry->time);

    printf("Enter content: ");
    fgets(entry->content, MAX_ENTRY_SIZE, stdin);
    entry->content[strcspn(entry->content, "\n")] = '\0';

    num_entries++;
    printf("Entry added.\n");
}

void view_entries() {
    printf("Diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n", diary[i].date, diary[i].time, diary[i].content);
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_SIZE];

    printf("Enter keyword to search: ");
    scanf("%s", keyword);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].content, keyword)) {
            printf("%s %s\n%s\n", diary[i].date, diary[i].time, diary[i].content);
        }
    }
}

int main() {
    setbuf(stdout, NULL);

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