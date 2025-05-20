//FormAI DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone_number[20];
};

struct PhoneBook {
    struct Contact contacts[MAX_CONTACTS];
    int num_contacts;
};

void add_contact(struct PhoneBook* phone_book, const char* name, const char* phone_number) {
    if (phone_book->num_contacts == MAX_CONTACTS) {
        printf("Error: phone book is full\n");
        return;
    }
    struct Contact new_contact;
    strncpy(new_contact.name, name, sizeof(new_contact.name));
    strncpy(new_contact.phone_number, phone_number, sizeof(new_contact.phone_number));
    phone_book->contacts[phone_book->num_contacts++] = new_contact;
    printf("Added contact for %s (%s)\n", name, phone_number);
}

void remove_contact(struct PhoneBook* phone_book, const char* name) {
    int found_index = -1;
    for (int i = 0; i < phone_book->num_contacts; ++i) {
        if (strcmp(phone_book->contacts[i].name, name) == 0) {
            found_index = i;
            break;
        }
    }
    if (found_index == -1) {
        printf("Error: contact not found\n");
        return;
    }
    printf("Removed contact for %s (%s)\n", phone_book->contacts[found_index].name, phone_book->contacts[found_index].phone_number);
    for (int i = found_index; i < phone_book->num_contacts - 1; ++i) {
        phone_book->contacts[i] = phone_book->contacts[i+1];
    }
    --phone_book->num_contacts;
}

void print_phone_book(const struct PhoneBook* phone_book) {
    printf("Phone Book:\n");
    for (int i = 0; i < phone_book->num_contacts; ++i) {
        printf("%-30s %s\n", phone_book->contacts[i].name, phone_book->contacts[i].phone_number);
    }
}

int main() {
    struct PhoneBook phone_book;
    phone_book.num_contacts = 0;
    
    printf("Welcome to the Mind-Bending Phone Book\n");
    printf("======================================\n");
    
    char command[10], arg1[50], arg2[20];
    while (1) {
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            scanf("%s %s", arg1, arg2);
            add_contact(&phone_book, arg1, arg2);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%s", arg1);
            remove_contact(&phone_book, arg1);
        } else if (strcmp(command, "print") == 0) {
            print_phone_book(&phone_book);
        } else if (strcmp(command, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Error: invalid command\n");
        }
    }
    
    return 0;
}