//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char phone[15];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].phone);
    num_entries++;
}

void delete_entry() {
    int i;
    printf("Enter name to delete: ");
    scanf("%s", phonebook[0].name);
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, phonebook[0].name) == 0) {
            strcpy(phonebook[i].name, phonebook[num_entries - 1].name);
            strcpy(phonebook[i].phone, phonebook[num_entries - 1].phone);
            num_entries--;
            break;
        }
    }
}

void search_entry() {
    int i;
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
        }
    }
}

void print_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

int main() {
    int choice, i;
    printf("Phone Book\n");
    while (1) {
        printf("\n1. Add entry\n2. Delete entry\n3. Search entry\n4. Print entries\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                delete_entry();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                print_entries();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}