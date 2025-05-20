//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 32
#define MAX_NUMBERS_PER_CONTACT 3
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char numbers[MAX_NUMBERS_PER_CONTACT][16];
    int num_numbers;
} Contact;

void add_contact(Contact* contacts, int num_contacts, char* name, char* number) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            strcpy(contacts[i].numbers[contacts[i].num_numbers], number);
            contacts[i].num_numbers++;
            return;
        }
    }
    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].numbers[0], number);
    contacts[num_contacts].num_numbers = 1;
    num_contacts++;
}

void print_contacts(Contact* contacts, int num_contacts) {
    int i, j;
    for (i = 0; i < num_contacts; i++) {
        printf("%s:\n", contacts[i].name);
        for (j = 0; j < contacts[i].num_numbers; j++) {
            printf("\t%s\n", contacts[i].numbers[j]);
        }
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;
    char input[100];

    while (1) {
        printf("Enter a name and phone number (or just press enter to view contacts):\n");
        fgets(input, sizeof(input), stdin);

        if (input[0] == '\n') {
            print_contacts(contacts, num_contacts);
        } else {
            char* name = input;
            char* number = strchr(input, ',');
            if (number == NULL) {
                printf("Invalid input.\n");
                continue;
            }
            *number++ = '\0';

            add_contact(contacts, num_contacts, name, number);
            num_contacts++;
        }
    }

    return 0;
}