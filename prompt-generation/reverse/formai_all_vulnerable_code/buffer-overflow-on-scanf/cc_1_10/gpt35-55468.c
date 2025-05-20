//FormAI DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 30
#define MAX_CONTACTS 100

struct contact {
    char first_name[MAX_LENGTH];
    char last_name[MAX_LENGTH];
    char phone_num[MAX_LENGTH];
};

int num_contacts = 0;
struct contact contacts[MAX_CONTACTS];

void add_contact() {
    printf("What is thy first name? ");
    scanf("%s", contacts[num_contacts].first_name);

    printf("What is thy last name? ");
    scanf("%s", contacts[num_contacts].last_name);

    printf("What is thy phone num, sweet darling? ");
    scanf("%s", contacts[num_contacts].phone_num);

    printf("I have added thy contact!\n");
    num_contacts++;
}

void print_contacts() {
    if (num_contacts == 0) {
        printf("There are no contacts, fair Capulet.\n");
        return;
    }

    printf("Here are thy contacts, sweet Romeo:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s, %s: %s\n", contacts[i].last_name, contacts[i].first_name, contacts[i].phone_num);
    }
}

int main() {
    char choice[MAX_LENGTH];

    printf("Welcome to thy Phone Book, dear Romeo!\n");

    while (1) {
        printf("Wouldst thou like to add a contact, see thy contacts, or depart hence? ");
        scanf("%s", choice);

        if (strcmp(choice, "add") == 0) {
            add_contact();
        } else if (strcmp(choice, "see") == 0) {
            print_contacts();
        } else if (strcmp(choice, "depart") == 0) {
            printf("Goodbye, sweet Romeo!\n");
            break;
        } else {
            printf("I know not what thou sayest, fair Capulet.\n");
        }
    }

    return 0;
}