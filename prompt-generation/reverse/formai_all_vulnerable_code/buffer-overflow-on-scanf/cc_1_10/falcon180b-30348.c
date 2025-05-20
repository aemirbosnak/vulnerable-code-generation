//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 512

typedef struct {
    char date[16];
    char time[8];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

int num_entries = 0;
diary_entry diary[MAX_ENTRIES];

void add_entry() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(diary[num_entries].date, sizeof(diary[num_entries].date), "%Y-%m-%d", t);
    strftime(diary[num_entries].time, sizeof(diary[num_entries].time), "%H:%M:%S", t);

    printf("Enter your entry:\n");
    fgets(diary[num_entries].entry, sizeof(diary[num_entries].entry), stdin);
    diary[num_entries].entry[strcspn(diary[num_entries].entry, "\n")] = '\0';

    num_entries++;
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("Viewing entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s: %s\n", diary[i].date, diary[i].time, diary[i].entry);
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            view_entries();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}