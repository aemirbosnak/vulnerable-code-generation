//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    char date[20];
    char time[10];
    char content[500];
};

void add_entry(struct entry* entries, int num_entries, char* content) {
    if (num_entries >= MAX_ENTRIES) {
        printf("ERROR: Maximum number of entries reached.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    strftime(entries[num_entries].date, 20, "%Y-%m-%d", tm);
    strftime(entries[num_entries].time, 10, "%H:%M:%S", tm);

    strcpy(entries[num_entries].content, content);
    num_entries++;
}

void view_entries(struct entry* entries, int num_entries) {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("Date: %s\nTime: %s\nContent:\n%s\n\n", entries[i].date, entries[i].time, entries[i].content);
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    char content[500];
    printf("Welcome to your digital diary!\n\n");
    while (1) {
        printf("Enter your thoughts:\n");
        fgets(content, 500, stdin);
        add_entry(entries, num_entries, content);

        printf("View entries? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y') {
            view_entries(entries, num_entries);
        }
    }

    return 0;
}