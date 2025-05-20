//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name (up to %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", entries[num_entries].name);
    printf("Enter value (up to %d characters): ", MAX_VALUE_LEN - 1);
    scanf("%s", entries[num_entries].value);
    num_entries++;
}

void view_entries() {
    printf("Name | Value\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s | %s\n", entries[i].name, entries[i].value);
    }
}

void search_entry() {
    printf("Enter name to search for: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nValue: %s\n", entries[i].name, entries[i].value);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add entry\n2. View entries\n3. Search entry\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}