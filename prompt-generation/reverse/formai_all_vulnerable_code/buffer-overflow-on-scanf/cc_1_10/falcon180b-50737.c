//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 1000

typedef struct {
    char title[MAX_ENTRY_SIZE];
    char content[MAX_ENTRY_SIZE];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* title, char* content) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strncpy(entries[num_entries].title, title, MAX_ENTRY_SIZE);
    strncpy(entries[num_entries].content, content, MAX_ENTRY_SIZE);
    entries[num_entries].timestamp = time(NULL);

    num_entries++;
}

void print_entries() {
    printf("Digital Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d. %s\n%s\n", i+1, entries[i].title, entries[i].content);
    }
}

int main() {
    char title[MAX_ENTRY_SIZE];
    char content[MAX_ENTRY_SIZE];

    while (1) {
        printf("Enter entry title: ");
        scanf("%s", title);

        printf("Enter entry content: ");
        scanf("%s", content);

        add_entry(title, content);
    }

    return 0;
}