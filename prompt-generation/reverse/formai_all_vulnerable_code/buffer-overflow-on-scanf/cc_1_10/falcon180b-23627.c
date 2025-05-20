//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 200

typedef struct {
    char name[50];
    char phone[15];
} Contact;

void add_contact(Contact *book, int *num_entries) {
    char name[50];
    char phone[15];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    strcpy(book[*num_entries].name, name);
    strcpy(book[*num_entries].phone, phone);

    (*num_entries)++;
}

void search_contact(Contact *book, int num_entries, char *name) {
    int i;

    for(i = 0; i < num_entries; i++) {
        if(strcmp(book[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", book[i].name, book[i].phone);
        }
    }
}

void delete_contact(Contact *book, int *num_entries) {
    char name[50];

    printf("Enter name to delete: ");
    scanf("%s", name);

    int i;
    for(i = 0; i < *num_entries; i++) {
        if(strcmp(book[i].name, name) == 0) {
            memmove(&book[i], &book[i+1], (*num_entries - i - 1) * sizeof(Contact));
            (*num_entries)--;
        }
    }
}

void print_all_contacts(Contact *book, int num_entries) {
    int i;

    for(i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone: %s\n", book[i].name, book[i].phone);
    }
}

int main() {
    Contact book[MAX_ENTRIES];
    int num_entries = 0;

    while(1) {
        printf("1. Add contact\n2. Search contact\n3. Delete contact\n4. Print all contacts\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact(book, &num_entries);
                break;
            case 2:
                printf("Enter name to search: ");
                char name[50];
                scanf("%s", name);
                search_contact(book, num_entries, name);
                break;
            case 3:
                delete_contact(book, &num_entries);
                break;
            case 4:
                print_all_contacts(book, num_entries);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}