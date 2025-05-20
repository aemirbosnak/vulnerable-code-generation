//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1024

typedef struct {
    char date[32];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char input[MAX_ENTRY_LENGTH];
    char date[32];

    time_t now = time(NULL);
    strftime(date, 32, "%Y-%m-%d", localtime(&now));

    while (1) {
        printf("Digital Diary - %s\n", date);
        printf("---------------------------------\n");
        printf("1. Add entry\n");
        printf("2. Print entries\n");
        printf("3. Exit\n");
        printf("---------------------------------\n");
        scanf("%d", &num_entries);

        switch (num_entries) {
            case 1:
                printf("Enter your entry:\n");
                scanf("%s", input);
                add_entry(date, input);
                break;
            case 2:
                print_entries();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}