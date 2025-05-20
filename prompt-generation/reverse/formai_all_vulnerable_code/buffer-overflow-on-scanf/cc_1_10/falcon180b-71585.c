//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 10000

struct entry {
    char date[20];
    char time[10];
    char content[MAX_ENTRY_LENGTH];
};

int num_entries = 0;
struct entry diary[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(diary[num_entries].date, sizeof(diary[num_entries].date), "%Y-%m-%d", t);
    strftime(diary[num_entries].time, sizeof(diary[num_entries].time), "%H:%M:%S", t);

    printf("Diary entry #%d:\n", num_entries+1);
    printf("Date: %s\n", diary[num_entries].date);
    printf("Time: %s\n", diary[num_entries].time);
    printf("Content:\n");

    char content[MAX_ENTRY_LENGTH];
    fgets(content, sizeof(content), stdin);
    strcpy(diary[num_entries].content, content);

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
        printf("Entry #%d:\n", i+1);
        printf("Date: %s\n", diary[i].date);
        printf("Time: %s\n", diary[i].time);
        printf("Content:\n%s\n", diary[i].content);
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to your digital diary!\n");

    int choice;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}