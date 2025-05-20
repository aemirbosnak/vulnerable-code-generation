//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[10];
    char time[8];
    char content[MAX_ENTRY_LENGTH];
};

void add_entry(struct entry entries[], int num_entries, char* date, char* time, char* content) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Diary is full.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].time, time);
    strcpy(entries[num_entries].content, content);

    num_entries++;
}

void display_entries(struct entry entries[], int num_entries) {
    if (num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].content);
    }
}

int main() {
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;

    char date[10], time[8], content[MAX_ENTRY_LENGTH];

    while (1) {
        printf("Enter date (yyyy-mm-dd): ");
        scanf("%s", date);

        printf("Enter time (hh:mm:ss): ");
        scanf("%s", time);

        printf("Enter content:\n");
        gets(content);

        add_entry(diary, num_entries, date, time, content);
    }

    return 0;
}