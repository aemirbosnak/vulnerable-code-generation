//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

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

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", diary[num_entries].date);

    printf("Enter time (HH:MM:SS): ");
    scanf("%s", diary[num_entries].time);

    printf("Enter content:\n");
    fgets(diary[num_entries].content, MAX_ENTRY_LENGTH, stdin);

    num_entries++;
    printf("Entry added.\n");
}

void view_entries() {
    if (num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("Diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n", diary[i].date, diary[i].time, diary[i].content);
    }
}

void search_entries() {
    if (num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    char keyword[MAX_ENTRY_LENGTH];
    printf("Enter keyword to search: ");
    scanf("%s", keyword);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].content, keyword)) {
            printf("%s %s\n%s\n", diary[i].date, diary[i].time, diary[i].content);
        }
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to your digital diary!\n\n");

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
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}