//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries;

void add_entry(char* name, char* value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].value, value);

    num_entries++;
}

void search_entries(char* search_term) {
    int i;

    printf("Searching for '%s'...\n", search_term);

    for (i = 0; i < num_entries; i++) {
        if (strstr(entries[i].name, search_term)!= NULL || strstr(entries[i].value, search_term)!= NULL) {
            printf("Found entry:\n");
            printf("Name: %s\n", entries[i].name);
            printf("Value: %s\n", entries[i].value);
        }
    }
}

int main() {
    int choice;

    do {
        printf("Choose an option:\n");
        printf("1. Add an entry\n");
        printf("2. Search for an entry\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LEN];
                char value[MAX_VALUE_LEN];

                printf("Enter a name: ");
                scanf("%s", name);

                printf("Enter a value: ");
                scanf("%s", value);

                add_entry(name, value);
                break;
            }
            case 2: {
                char search_term[MAX_NAME_LEN];

                printf("Enter a search term: ");
                scanf("%s", search_term);

                search_entries(search_term);
                break;
            }
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 3);

    return 0;
}