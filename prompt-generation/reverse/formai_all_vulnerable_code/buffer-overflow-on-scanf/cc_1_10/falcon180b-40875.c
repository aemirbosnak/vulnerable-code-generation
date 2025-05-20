//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char phone[15];
} Entry;

Entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].phone);
    num_entries++;
}

void search_entry() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    int i = 0;
    while (i < num_entries) {
        if (strcmp(name, phonebook[i].name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", phonebook[i].name, phonebook[i].phone);
            break;
        }
        i++;
    }
    if (i == num_entries) {
        printf("Entry not found.\n");
    }
}

void delete_entry() {
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s", name);
    int i = 0;
    while (i < num_entries) {
        if (strcmp(name, phonebook[i].name) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                strcpy(phonebook[j].name, phonebook[j+1].name);
                strcpy(phonebook[j].phone, phonebook[j+1].phone);
            }
            num_entries--;
            break;
        }
        i++;
    }
    if (i == num_entries) {
        printf("Entry not found.\n");
    }
}

void print_entries() {
    int i = 0;
    while (i < num_entries) {
        printf("Name: %s\nPhone Number: %s\n", phonebook[i].name, phonebook[i].phone);
        i++;
    }
}

int main() {
    int choice;
    do {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Print entries\n5. Exit\n");
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
                print_entries();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);
    return 0;
}