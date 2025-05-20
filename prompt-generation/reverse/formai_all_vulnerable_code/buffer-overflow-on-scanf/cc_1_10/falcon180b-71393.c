//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11];
    char time[9];
    char entry[1001];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void print_entry(int index) {
    printf("%s %s:\n%s\n", entries[index].date, entries[index].time, entries[index].entry);
}

bool add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return false;
    }

    printf("Date (YYYY-MM-DD): ");
    scanf("%s", entries[num_entries].date);

    printf("Time (HH:MM:SS): ");
    scanf("%s %s", entries[num_entries].time, entries[num_entries].entry);

    num_entries++;
    printf("Entry added.\n");
    return true;
}

bool search_entry(char *keyword) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword)) {
            print_entry(i);
            return true;
        }
    }
    printf("No entries found.\n");
    return false;
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("1. Add entry\n2. Search entries\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2: {
            char keyword[1001];
            printf("Keyword: ");
            scanf("%s", keyword);
            search_entry(keyword);
            break;
        }
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}