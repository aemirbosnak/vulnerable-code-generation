//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBERS_PER_CONTACT 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char numbers[MAX_NUMBERS_PER_CONTACT][15];
    int num_of_numbers;
} Contact;

void add_contact(Contact* contacts, int num_of_contacts) {
    printf("Enter name: ");
    scanf("%s", contacts[num_of_contacts].name);
    contacts[num_of_contacts].num_of_numbers = 0;

    printf("Enter phone numbers (up to %d):\n", MAX_NUMBERS_PER_CONTACT);
    char number[15];
    while(scanf("%s", number)!= EOF) {
        strcpy(contacts[num_of_contacts].numbers[contacts[num_of_contacts].num_of_numbers], number);
        contacts[num_of_contacts].num_of_numbers++;
    }
}

void print_contacts(Contact* contacts, int num_of_contacts) {
    for(int i=0; i<num_of_contacts; i++) {
        printf("%s:\n", contacts[i].name);
        for(int j=0; j<contacts[i].num_of_numbers; j++) {
            printf("  %s\n", contacts[i].numbers[j]);
        }
    }
}

int main() {
    Contact contacts[100];
    int num_of_contacts = 0;

    while(1) {
        printf("1. Add contact\n2. Print contacts\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact(contacts, num_of_contacts);
                num_of_contacts++;
                break;
            case 2:
                print_contacts(contacts, num_of_contacts);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}