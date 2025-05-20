//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_DATA_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char data[MAX_DATA_LENGTH];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

int compare_entries(const void* a, const void* b) {
    const entry_t* entry1 = (const entry_t*)a;
    const entry_t* entry2 = (const entry_t*)b;

    int result = strcmp(entry1->name, entry2->name);

    if (result == 0) {
        result = strcmp(entry1->data, entry2->data);
    }

    return result;
}

void add_entry() {
    char name[MAX_NAME_LENGTH];
    char data[MAX_DATA_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter data: ");
    scanf("%s", data);

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].data, data);

    num_entries++;
}

void search_entry() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    scanf("%s", name);

    qsort(entries, num_entries, sizeof(entry_t), compare_entries);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Found entry:\n");
            printf("Name: %s\n", entries[i].name);
            printf("Data: %s\n", entries[i].data);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nDatabase Indexing System\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            search_entry();
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}