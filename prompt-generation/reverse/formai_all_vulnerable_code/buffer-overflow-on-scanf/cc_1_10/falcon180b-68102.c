//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(diary[num_entries].date, 20, "%Y-%m-%d %H:%M:%S", tm);
    printf("Enter your diary entry for %s:\n", diary[num_entries].date);
    fgets(diary[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
    num_entries++;
}

void view_entries() {
    printf("Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    srand(time(NULL));
    int choice;

    do {
        printf("Digital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
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
                printf("Thanks for using Digital Diary!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}