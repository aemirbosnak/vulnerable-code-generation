//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 100
#define MAX_PHONE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *name, char *phone) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: maximum number of entries reached\n");
        return;
    }

    strncpy(entries[num_entries].name, name, MAX_NAME_LEN);
    strncpy(entries[num_entries].phone, phone, MAX_PHONE_LEN);
    num_entries++;
}

void search_entry(char *name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Found entry: %s, %s\n", entries[i].name, entries[i].phone);
            return;
        }
    }
    printf("Entry not found\n");
}

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];

    while (1) {
        printf("\nPhonebook Menu\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter phone number: ");
            scanf("%s", phone);
            add_entry(name, phone);
            break;

        case 2:
            printf("Enter name to search: ");
            scanf("%s", name);
            search_entry(name);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}