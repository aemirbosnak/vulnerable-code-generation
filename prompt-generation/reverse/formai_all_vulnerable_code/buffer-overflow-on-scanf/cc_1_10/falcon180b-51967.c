//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    char date[16];
    char time[8];
    char content[256];
};

void add_entry(struct entry* diary, int num_entries, char* content) {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    strftime(diary[num_entries].date, 16, "%Y-%m-%d", tm);
    strftime(diary[num_entries].time, 8, "%H:%M:%S", tm);
    strncpy(diary[num_entries].content, content, 256);
}

void print_entries(struct entry* diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s - %s\n", diary[i].date, diary[i].time, diary[i].content);
    }
}

int main() {
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("1. Add entry\n2. Print entries\n3. Exit\n");
        int choice = scanf("%d", &choice);

        if (choice == 1) {
            char content[256];
            printf("Enter content:\n");
            scanf("%[^\n]", content);
            add_entry(diary, num_entries, content);
            num_entries++;
        } else if (choice == 2) {
            print_entries(diary, num_entries);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}