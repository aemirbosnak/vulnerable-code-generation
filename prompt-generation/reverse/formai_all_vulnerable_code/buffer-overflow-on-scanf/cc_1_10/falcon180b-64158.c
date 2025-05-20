//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct Entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

int num_entries = 0;
struct Entry diary[MAX_ENTRIES];

void add_entry(char* date, char* time, char* content) {
    strncpy(diary[num_entries].date, date, 20);
    strncpy(diary[num_entries].time, time, 20);
    strncpy(diary[num_entries].content, content, MAX_ENTRY_LENGTH);
    num_entries++;
}

void print_entries() {
    printf("Digital Diary\n");
    for (int i = 0; i < num_entries; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Time: %s\n", diary[i].time);
        printf("Content: %s\n\n", diary[i].content);
    }
}

int main() {
    char date[20], time[20], content[MAX_ENTRY_LENGTH];
    int choice;

    while (1) {
        printf("Digital Diary\n");
        printf("1. Add Entry\n");
        printf("2. Print Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Date (dd/mm/yyyy): ");
                scanf("%s", date);
                printf("Enter Time (hh:mm:ss): ");
                scanf("%s", time);
                printf("Enter Content: ");
                scanf("%s", content);
                add_entry(date, time, content);
                break;
            case 2:
                print_entries();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}