//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

void add_entry(struct entry* entries, int num_entries, char* date, char* time, char* content) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].time, time);
    strcpy(entries[num_entries].content, content);
}

void display_entries(struct entry* entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n", entries[i].date, entries[i].time, entries[i].content);
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char date[20], time[20];

    while (1) {
        printf("Enter a date (YYYY-MM-DD): ");
        scanf("%s", date);
        printf("Enter a time (HH:MM:SS): ");
        scanf("%s", time);

        if (strlen(date)!= 10 || strlen(time)!= 8) {
            printf("Invalid date or time format.\n");
            continue;
        }

        if (num_entries >= MAX_ENTRIES) {
            printf("Maximum number of entries reached.\n");
            break;
        }

        char content[MAX_ENTRY_LENGTH];
        printf("Enter your diary entry:\n");
        fgets(content, MAX_ENTRY_LENGTH, stdin);
        content[strcspn(content, "\n")] = '\0'; // Remove newline character

        add_entry(entries, num_entries, date, time, content);
        num_entries++;
    }

    printf("Your diary entries:\n");
    display_entries(entries, num_entries);

    return 0;
}