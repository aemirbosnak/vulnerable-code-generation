//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone_number[15];
} contact;

int num_entries = 0;
contact phone_book[MAX_ENTRIES];

void add_contact(contact* new_contact) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(phone_book[num_entries].name, new_contact->name);
    strcpy(phone_book[num_entries].phone_number, new_contact->phone_number);

    num_entries++;
}

void display_contacts() {
    printf("\nPhone Book:\n");
    printf("-----------------\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d. %s - %s\n", i+1, phone_book[i].name, phone_book[i].phone_number);
    }
}

void search_contact(char* search_name) {
    int index = -1;

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i].name, search_name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Contact not found.\n");
    } else {
        printf("\nContact details:\n");
        printf("-----------------\n");
        printf("Name: %s\n", phone_book[index].name);
        printf("Phone number: %s\n", phone_book[index].phone_number);
    }
}

int main() {
    contact new_contact = {"John Doe", "123-456-7890"};
    add_contact(&new_contact);

    contact another_contact = {"Jane Smith", "987-654-3210"};
    add_contact(&another_contact);

    display_contacts();

    char search_name[50];
    printf("\nEnter name to search: ");
    scanf("%s", search_name);
    search_contact(search_name);

    return 0;
}