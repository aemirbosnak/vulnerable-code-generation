//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[20];
    char time[10];
    char text[MAX_ENTRY_LENGTH];
};

int num_entries = 0;
struct entry entries[MAX_ENTRIES];

void add_entry(char* date, char* time, char* text) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].time, time);
    strcpy(entries[num_entries].text, text);

    num_entries++;
}

void display_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n%s\n", entries[i].date, entries[i].time, entries[i].text);
    }
}

void search_entries(char* keyword) {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Search results:\n");
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].text, keyword)) {
            printf("%s %s\n%s\n", entries[i].date, entries[i].time, entries[i].text);
        }
    }
}

int main() {
    char date[20];
    char time[10];
    char text[MAX_ENTRY_LENGTH];

    printf("Welcome to the Digital Diary!\n");

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);

        printf("Enter time (HH:MM): ");
        scanf("%s", time);

        printf("Enter your entry:\n");
        fgets(text, MAX_ENTRY_LENGTH, stdin);

        add_entry(date, time, text);
    }

    return 0;
}