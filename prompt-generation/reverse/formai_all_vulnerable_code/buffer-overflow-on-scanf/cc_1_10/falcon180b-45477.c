//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[11];
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
    char date[11];

    time_t now = time(NULL);
    strftime(date, 11, "%Y-%m-%d", localtime(&now));

    while (1) {
        printf("Enter your entry for %s:\n", date);
        fgets(input, MAX_ENTRY_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // remove newline character

        add_entry(date, input);
        print_entries();

        printf("Do you want to add another entry? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    return 0;
}