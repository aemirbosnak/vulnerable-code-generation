//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50
#define MAX_NUMBER_SIZE 15
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_SIZE];
    char number[MAX_NUMBER_SIZE];
} entry_t;

void add_entry(entry_t *entries, int count, char *name, char *number) {
    if (count >= MAX_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }

    strcpy(entries[count].name, name);
    strcpy(entries[count].number, number);

    count++;
}

void display_entries(entry_t *entries, int count) {
    printf("Phone Book:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", entries[i].name, entries[i].number);
    }
}

void search_entry(entry_t *entries, int count, char *name) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Found entry for %s:\n", name);
            printf("%s - %s\n", entries[i].name, entries[i].number);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int count = 0;

    add_entry(entries, count, "Neo", "555-1234");
    add_entry(entries, count, "Trinity", "555-5678");
    add_entry(entries, count, "Morpheus", "555-9012");

    display_entries(entries, count);

    char search_name[MAX_NAME_SIZE];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    search_entry(entries, count, search_name);

    return 0;
}