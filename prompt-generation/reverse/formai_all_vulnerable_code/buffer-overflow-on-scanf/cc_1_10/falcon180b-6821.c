//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[100];
    char phone[20];
} Entry;

Entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char name[100];
    char phone[20];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].phone, phone);

    num_entries++;
}

void search_entry() {
    char name[100];

    printf("Enter name to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
        }
    }
}

int main() {
    int choice;

    do {
        printf("Phone Book\n");
        printf("1. Add entry\n2. Search entry\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}