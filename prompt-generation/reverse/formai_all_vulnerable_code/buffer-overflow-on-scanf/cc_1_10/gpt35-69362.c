//FormAI DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct surreal_contact {
    char name[20];
    char number[20];
} SurrealContact;

SurrealContact contacts[MAX];

int num_contacts = 0;

void add_contact() {
    SurrealContact new_contact;

    printf("Enter contact name (must be a surrealist name): ");
    scanf("%s", new_contact.name);

    printf("Enter contact number (must be a surrealist number): ");
    scanf("%s", new_contact.number);

    if (num_contacts >= MAX) {
        printf("Error: Phone book is full!\n");
        return;
    }

    contacts[num_contacts] = new_contact;
    num_contacts++;

    printf("Contact added to phone book.\n");
}

void print_contacts() {
    int i;

    if (num_contacts == 0) {
        printf("Phone book is empty!\n");
        return;
    }

    printf("Phone book:\n");
    for (i = 0; i < num_contacts; i++) {
        printf("%s\t%s\n", contacts[i].name, contacts[i].number);
    }
}

int main() {
    int option;

    while (1) {
        printf("\nPhone book options:\n");
        printf("1. Add a surrealist contact\n");
        printf("2. Print all contacts\n");
        printf("3. Quit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_contact();
                break;
            case 2:
                print_contacts();
                break;
            case 3:
                printf("Quitting program, surrealistically.\n");
                return 0;
            default:
                printf("Invalid option, surrealistically.\n");
        }
    }

    return 0;
}