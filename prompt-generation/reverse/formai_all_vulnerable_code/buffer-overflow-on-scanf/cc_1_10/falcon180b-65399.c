//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[41];
    char phone[21];
} entry;

int num_entries = 0;
entry phonebook[MAX_ENTRIES];

void add_entry() {
    char name[41], phone[21];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", phone);
    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].phone, phone);
    num_entries++;
}

void view_entries() {
    int i;
    printf("Phonebook:\n");
    for (i = 0; i < num_entries; i++) {
        printf("%s: %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

void delete_entry() {
    char name[41];
    printf("Enter name to delete: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], sizeof(entry) * (num_entries - i - 1));
            num_entries--;
            break;
        }
    }
}

void search_entry() {
    char name[41];
    printf("Enter name to search: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("%s: %s\n", phonebook[i].name, phonebook[i].phone);
            break;
        }
    }
}

int main() {
    int choice;
    do {
        printf("1. Add entry\n2. View entries\n3. Delete entry\n4. Search entry\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                search_entry();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);
    return 0;
}