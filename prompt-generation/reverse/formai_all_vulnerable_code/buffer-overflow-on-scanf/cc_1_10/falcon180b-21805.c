//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_ENTRIES 1000

struct entry {
    char name[MAX_NAME_LEN];
    char number[MAX_NAME_LEN];
};

void add_entry(struct entry entries[], int num_entries) {
    char name[MAX_NAME_LEN], number[MAX_NAME_LEN];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter number: ");
    scanf("%s", number);

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].number, number);

    num_entries++;
}

void search_entry(struct entry entries[], int num_entries) {
    char search_name[MAX_NAME_LEN], search_number[MAX_NAME_LEN];

    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
            break;
        }
    }
}

void delete_entry(struct entry entries[], int num_entries) {
    char search_name[MAX_NAME_LEN];

    printf("Enter name to delete: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                strcpy(entries[j].name, entries[j + 1].name);
                strcpy(entries[j].number, entries[j + 1].number);
            }
            num_entries--;
            break;
        }
    }
}

void display_entries(struct entry entries[], int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    struct entry entries[MAX_NUM_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Display entries\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(entries, num_entries);
                break;
            case 2:
                printf("Enter name to search: ");
                char search_name[MAX_NAME_LEN];
                scanf("%s", search_name);
                search_entry(entries, num_entries);
                break;
            case 3:
                printf("Enter name to delete: ");
                char delete_name[MAX_NAME_LEN];
                scanf("%s", delete_name);
                delete_entry(entries, num_entries);
                break;
            case 4:
                display_entries(entries, num_entries);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}