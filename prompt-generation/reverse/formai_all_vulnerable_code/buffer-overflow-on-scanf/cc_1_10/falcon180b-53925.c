//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000
#define MAX_DATE_LENGTH 20

typedef struct {
    char date[MAX_DATE_LENGTH];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

int entry_count = 0;
diary_entry diary[MAX_ENTRIES];

void add_entry(char* date, char* entry) {
    strcpy(diary[entry_count].date, date);
    strcpy(diary[entry_count].entry, entry);
    entry_count++;
}

void print_entry(int index) {
    printf("Date: %s\n", diary[index].date);
    printf("Entry:\n%s\n", diary[index].entry);
}

void print_entries() {
    printf("Diary Entries:\n");
    for(int i=0; i<entry_count; i++) {
        print_entry(i);
    }
}

int main() {
    char date[MAX_DATE_LENGTH];
    char entry[MAX_ENTRY_LENGTH];

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(date, MAX_DATE_LENGTH, "%Y-%m-%d", t);

    while(1) {
        printf("Enter a diary entry for %s:\n", date);
        fgets(entry, MAX_ENTRY_LENGTH, stdin);

        add_entry(date, entry);

        print_entries();

        printf("Press 'q' to quit or any other key to continue...\n");
        char choice;
        scanf(" %c", &choice);
        if(tolower(choice) == 'q') {
            break;
        }
    }

    return 0;
}