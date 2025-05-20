//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_SIZE 100

typedef struct {
    char name[MAX_ENTRY_SIZE];
    char address[MAX_ENTRY_SIZE];
    char phone[MAX_ENTRY_SIZE];
} Entry;

void add_entry(Entry* entries, int count, char* name, char* address, char* phone) {
    if (count >= MAX_ENTRIES) {
        printf("Database is full!\n");
        return;
    }

    strcpy(entries[count].name, name);
    strcpy(entries[count].address, address);
    strcpy(entries[count].phone, phone);

    count++;
}

void view_entry(Entry* entries, int count, int index) {
    if (index < 0 || index >= count) {
        printf("Invalid index!\n");
        return;
    }

    printf("Name: %s\n", entries[index].name);
    printf("Address: %s\n", entries[index].address);
    printf("Phone: %s\n", entries[index].phone);
}

void search_entry(Entry* entries, int count, char* name) {
    int index = -1;

    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Entry not found!\n");
    } else {
        view_entry(entries, count, index);
    }
}

int main() {
    Entry entries[MAX_ENTRIES];
    int count = 0;

    add_entry(entries, count, "John Doe", "123 Main St", "555-1234");
    add_entry(entries, count, "Jane Smith", "456 Elm St", "555-5678");

    printf("View all entries:\n");
    for (int i = 0; i < count; i++) {
        view_entry(entries, count, i);
    }

    printf("\nSearch for an entry by name:\n");
    char name[MAX_ENTRY_SIZE];
    scanf("%s", name);
    search_entry(entries, count, name);

    return 0;
}