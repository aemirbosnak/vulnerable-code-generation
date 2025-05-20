//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_SIZE 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_SIZE];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    if (num_entries >= MAX_ENTRIES) {
        printf("ERROR: Maximum number of entries reached!\n");
        return;
    }
    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].entry, entry);
    num_entries++;
}

void print_entries() {
    printf("Digital Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", entries[i].date, entries[i].entry);
    }
}

int main() {
    srand(time(NULL));
    char buffer[MAX_ENTRY_SIZE];
    char date[20];
    while (1) {
        printf("Enter a date (YYYY-MM-DD): ");
        scanf("%s", date);
        if (strlen(date)!= 10 || date[4]!= '-' || date[7]!= '-') {
            printf("ERROR: Invalid date format!\n");
            continue;
        }
        printf("Enter your diary entry:\n");
        fgets(buffer, MAX_ENTRY_SIZE, stdin);
        int len = strlen(buffer);
        if (len > MAX_ENTRY_SIZE) {
            printf("ERROR: Entry is too long!\n");
            continue;
        }
        add_entry(date, buffer);
        printf("Entry added.\n");
    }
    return 0;
}