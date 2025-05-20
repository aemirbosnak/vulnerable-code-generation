//FormAI DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100 // Maximum number of entries

struct diary_entry {
    char date[20];
    char content[500];
};

int num_entries = 0;
struct diary_entry diary[MAX_ENTRIES];

void add_entry() {
    if(num_entries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    struct diary_entry entry;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(entry.date, "%d-%02d-%02d %02d:%02d:%02d", 
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

    printf("Enter content:\n");
    fgets(entry.content, 500, stdin);

    diary[num_entries] = entry;
    num_entries++;

    printf("Entry added!\n");
}

void view_entries() {
    if(num_entries == 0) {
        printf("No entries to display!\n");
        return;
    }

    for(int i = 0; i < num_entries; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Content:\n%s\n", diary[i].content);
    }
}

int main() {
    int choice;

    while(1) {
        printf("Enter choice:\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}