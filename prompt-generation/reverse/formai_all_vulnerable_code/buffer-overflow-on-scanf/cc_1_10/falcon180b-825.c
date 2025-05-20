//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[50];
    char time[50];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int num_entries = 0;
Entry diary[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", diary[num_entries].date);

    printf("Enter time (HH:MM:SS): ");
    scanf("%s", diary[num_entries].time);

    printf("Enter entry:\n");
    scanf("%[^\n]", diary[num_entries].entry);

    num_entries++;
}

void view_entries() {
    if (num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d:\n", i+1);
        printf("Date: %s\n", diary[i].date);
        printf("Time: %s\n", diary[i].time);
        printf("Entry:\n%s\n", diary[i].entry);
        printf("\n");
    }
}

void delete_entry() {
    if (num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("Enter entry number to delete: ");
    int entry_num;
    scanf("%d", &entry_num);

    if (entry_num < 1 || entry_num > num_entries) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = entry_num-1; i < num_entries-1; i++) {
        strcpy(diary[i].date, diary[i+1].date);
        strcpy(diary[i].time, diary[i+1].time);
        strcpy(diary[i].entry, diary[i+1].entry);
    }

    num_entries--;
}

void search_entry() {
    if (num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("Enter keyword to search: ");
    char keyword[MAX_ENTRY_LENGTH];
    scanf("%s", keyword);

    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].entry, keyword)) {
            printf("Entry %d:\n", i+1);
            printf("Date: %s\n", diary[i].date);
            printf("Time: %s\n", diary[i].time);
            printf("Entry:\n%s\n", diary[i].entry);
            printf("\n");
        }
    }
}

int main() {
    printf("Welcome to Digital Diary!\n");

    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Delete entry\n");
        printf("4. Search entry\n");
        printf("5. Exit\n");
        printf("\n");

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
                delete_entry();
                break;
            case 4:
                search_entry();
                break;
            case 5:
                printf("Thank you for using Digital Diary!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}