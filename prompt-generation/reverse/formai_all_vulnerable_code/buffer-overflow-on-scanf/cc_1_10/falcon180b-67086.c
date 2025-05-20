//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct diary_entry {
    char date[10];
    char time[10];
    char content[500];
};

void add_entry(struct diary_entry* entries, int num_entries) {
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", entries[num_entries].date);

    printf("Enter time (HH:MM:SS): ");
    scanf("%s", entries[num_entries].time);

    printf("Enter content:\n");
    fgets(entries[num_entries].content, sizeof(entries[num_entries].content), stdin);
    entries[num_entries].content[strcspn(entries[num_entries].content, "\n")] = '\0';

    num_entries++;
}

void view_entries(struct diary_entry* entries, int num_entries) {
    printf("Diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].content);
    }
}

int main() {
    struct diary_entry entries[MAX_ENTRIES];
    int num_entries = 0;

    srand(time(NULL));
    for (int i = 0; i < num_entries; i++) {
        entries[i].date[8] = '0' + rand() % 10;
        entries[i].date[5] = '0' + rand() % 10;
        entries[i].date[2] = '0' + rand() % 10;
        entries[i].date[0] = '2' + rand() % 2;

        entries[i].time[5] = '0' + rand() % 10;
        entries[i].time[3] = '0' + rand() % 10;
        entries[i].time[0] = '0' + rand() % 24;

        add_entry(entries, num_entries);
    }

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
            printf("Invalid choice\n");
        }
    }

    return 0;
}