//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].entry, entry);
    num_entries++;
}

void display_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    srand(time(NULL));
    int choice;
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    while (1) {
        printf("1. Add entry\n2. Display entries\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", date);
            printf("Enter entry:\n");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);
            add_entry(date, entry);
            break;
        case 2:
            display_entries();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}