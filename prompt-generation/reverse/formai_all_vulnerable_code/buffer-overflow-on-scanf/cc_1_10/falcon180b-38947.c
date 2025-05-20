//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    char date[20];
    char time[10];
    char content[500];
};

void add_entry(struct entry entries[], int num_entries) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(entries[num_entries].date, 20, "%Y-%m-%d", t);
    strftime(entries[num_entries].time, 10, "%H:%M:%S", t);

    printf("Enter your diary entry for %s %s:\n", entries[num_entries].date, entries[num_entries].time);
    fgets(entries[num_entries].content, 500, stdin);

    num_entries++;
}

void view_entries(struct entry entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s:\n%s\n\n", entries[i].date, entries[i].time, entries[i].content);
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    add_entry(entries, num_entries);

    while (1) {
        printf("1. Add entry\n2. View entries\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(entries, num_entries);
                break;
            case 2:
                view_entries(entries, num_entries);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}