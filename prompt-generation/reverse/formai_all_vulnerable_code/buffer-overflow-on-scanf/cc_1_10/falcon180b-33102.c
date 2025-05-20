//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct Entry {
    char date[11];
    char time[9];
    char content[MAX_ENTRY_LENGTH];
};

void add_entry(struct Entry* entries, int num_entries) {
    char date[11];
    char time[9];
    char content[MAX_ENTRY_LENGTH];

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", date);
    printf("Enter time (HH:MM:SS): ");
    scanf("%s", time);
    printf("Enter content:\n");
    fgets(content, MAX_ENTRY_LENGTH, stdin);
    content[strcspn(content, "\n")] = '\0';

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].time, time);
    strcpy(entries[num_entries].content, content);

    num_entries++;
}

void display_entries(struct Entry* entries, int num_entries) {
    printf("Digital Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].content);
    }
}

int main() {
    struct Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    printf("Welcome to Sherlock Holmes' Digital Diary!\n\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add entry\n");
        printf("2. Display entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &num_entries);

        switch (num_entries) {
            case 1:
                add_entry(entries, num_entries);
                break;
            case 2:
                display_entries(entries, num_entries);
                break;
            case 3:
                printf("\nExiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}