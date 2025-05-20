//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct entry {
    char date[20];
    char text[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* text) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached\n");
        return;
    }

    strcpy(entries[num_entries].date, date);
    strcpy(entries[num_entries].text, text);
    num_entries++;
}

void print_entries() {
    printf("Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].text);
    }
}

int main() {
    char input[MAX_ENTRY_LENGTH];

    while (1) {
        printf("Enter date (DD/MM/YYYY): ");
        scanf("%s", input);

        if (strlen(input)!= 10 ||!isdigit(input[2]) ||!isdigit(input[5]) || input[8]!= '/' || input[11]!= '/') {
            printf("Error: invalid date format\n");
            continue;
        }

        add_entry(input, "");
        printf("Entry added\n");
    }

    return 0;
}