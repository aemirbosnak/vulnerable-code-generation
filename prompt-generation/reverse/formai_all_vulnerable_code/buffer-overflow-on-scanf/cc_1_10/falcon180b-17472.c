//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[50];
    char phone[15];
};

struct entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", entries[num_entries].phone);
    num_entries++;
}

void search_entry() {
    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].phone);
        }
    }
}

void delete_entry() {
    char search_name[50];
    printf("Enter name to delete: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                strcpy(entries[j].name, entries[j + 1].name);
                strcpy(entries[j].phone, entries[j + 1].phone);
            }
            num_entries--;
        }
    }
}

void display_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].phone);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Display entries\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            search_entry();
            break;
        case 3:
            delete_entry();
            break;
        case 4:
            display_entries();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}