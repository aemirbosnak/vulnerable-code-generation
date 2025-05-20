//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[16];
    char time[8];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* time, char* entry) {
    num_entries++;
    strcpy(entries[num_entries - 1].date, date);
    strcpy(entries[num_entries - 1].time, time);
    strcpy(entries[num_entries - 1].entry, entry);
}

void view_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s %s: %s\n", entries[i].date, entries[i].time, entries[i].entry);
    }
}

int main() {
    srand(time(NULL));
    int choice;
    char date[16];
    char time[8];
    char entry[MAX_ENTRY_LENGTH];

    do {
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter time (HH:MM:SS): ");
                scanf("%s", time);
                printf("Enter your entry:\n");
                fgets(entry, MAX_ENTRY_LENGTH, stdin);
                entry[strcspn(entry, "\n")] = '\0';
                add_entry(date, time, entry);
                break;
            case 2:
                view_entries();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}