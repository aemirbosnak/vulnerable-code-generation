//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void display_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    char input[100];
    char* token;
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    strftime(input, 100, "%m/%d/%Y", t);

    while (1) {
        printf("Enter your diary entry for %s:\n", input);
        fgets(input, 100, stdin);

        char* entry = strtok_r(input, "\n", &token);
        if (entry == NULL) {
            printf("Error: Empty entry.\n");
            continue;
        }

        add_entry(input, entry);
        printf("Entry added.\n");

        char choice;
        printf("Do you want to view your entries? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            display_entries();
        }
    }

    return 0;
}