//FormAI DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 15
#define MAX_CAPACITY 100

typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

Contact phonebook[MAX_CAPACITY];
int num_entries = 0;

void add_contact() {
    if(num_entries == MAX_CAPACITY) {
        printf("The phonebook is full\n");
        return;
    }
    Contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter phone: ");
    scanf("%s", new_contact.phone);
    phonebook[num_entries++] = new_contact;
    printf("Contact added successfully\n");
}

void search_contact() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    for(int i = 0; i < num_entries; i++) {
        if(strcmp(name, phonebook[i].name) == 0) {
            printf("Name: %s, Phone: %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }
    printf("Contact not found\n");
}

void display_phonebook() {
    if(num_entries == 0) {
        printf("Phonebook is empty\n");
        return;
    }
    printf("Phonebook (%d entries):\n", num_entries);
    for(int i = 0; i < num_entries; i++) {
        printf("Name: %s, Phone: %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

int main() {
    int option = 0;
    printf("Welcome to the brave phonebook program!\n");
    while(option != 4) {
        printf("Please choose an option:\n");
        printf("1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Display phonebook\n");
        printf("4. Quit\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                display_phonebook();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again\n");
        }
    }
    return 0;
}