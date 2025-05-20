//FormAI DATASET v1.0 Category: Phone Book ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 100

struct contact {
    char name[50];
    char phone_number[20];
};

struct contact phone_book[MAX_CONTACTS];
int num_contacts = 0;

int main() {
    char input[50];
    while (1) {
        printf("Enter 'add' to add a contact, 'search' to search for a contact, or 'quit' to exit: ");
        scanf("%s", input);
        if (!strcmp(input, "add")) {
            if (num_contacts == MAX_CONTACTS) {
                printf("Sorry, the phone book is full.\n");
                continue;
            }
            printf("Enter name: ");
            scanf("%s", phone_book[num_contacts].name);
            printf("Enter phone number: ");
            scanf("%s", phone_book[num_contacts].phone_number);
            num_contacts++;
            printf("Contact added!\n\n");
        } else if (!strcmp(input, "search")) {
            printf("Enter name to search for: ");
            scanf("%s", input);
            int found = 0;
            for (int i = 0; i < num_contacts; i++) {
                if (!strcmp(input, phone_book[i].name)) {
                    printf("Phone number for %s: %s\n\n", phone_book[i].name, phone_book[i].phone_number);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Sorry, contact not found.\n\n");
            }
        } else if (!strcmp(input, "quit")) {
            printf("Goodbye.\n");
            break;
        } else {
            printf("Invalid input.\n\n");
        }
    }
    return 0;
}