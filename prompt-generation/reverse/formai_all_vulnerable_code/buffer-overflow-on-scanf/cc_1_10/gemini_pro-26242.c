//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUMBERS 10

typedef struct {
    char name[MAX_NAME_LEN];
    char numbers[MAX_NUMBERS][15];
    int num_numbers;
} contact;

contact* create_contact(char* name) {
    contact* c = malloc(sizeof(contact));
    strcpy(c->name, name);
    c->num_numbers = 0;
    return c;
}

void add_number(contact* c, char* number) {
    if (c->num_numbers < MAX_NUMBERS) {
        strcpy(c->numbers[c->num_numbers], number);
        c->num_numbers++;
    } else {
        printf("Error: Too many numbers for contact %s.\n", c->name);
    }
}

void print_contact(contact* c) {
    printf("Name: %s\n", c->name);
    for (int i = 0; i < c->num_numbers; i++) {
        printf("Number %d: %s\n", i + 1, c->numbers[i]);
    }
}

int main() {
    contact* contacts[100];
    int num_contacts = 0;

    while (1) {
        printf("Enter a command (add, print, quit): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[MAX_NAME_LEN];
            char number[15];
            printf("Enter the contact's name: ");
            scanf("%s", name);

            contact* c = create_contact(name);
            contacts[num_contacts] = c;
            num_contacts++;

            printf("Enter the contact's number: ");
            scanf("%s", number);
            add_number(c, number);
        } else if (strcmp(command, "print") == 0) {
            for (int i = 0; i < num_contacts; i++) {
                print_contact(contacts[i]);
            }
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}