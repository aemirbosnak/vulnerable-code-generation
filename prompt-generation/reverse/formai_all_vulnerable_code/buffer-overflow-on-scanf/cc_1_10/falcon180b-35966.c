//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter number: ");
    scanf("%s", contacts[num_contacts].number);
    num_contacts++;
}

void edit_contact() {
    int index;
    printf("Enter contact index to edit: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_contacts) {
        printf("Enter new name: ");
        scanf("%s", contacts[index].name);
        printf("Enter new number: ");
        scanf("%s", contacts[index].number);
    } else {
        printf("Invalid contact index.\n");
    }
}

void delete_contact() {
    int index;
    printf("Enter contact index to delete: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_contacts) {
        for (int i = index; i < num_contacts - 1; i++) {
            memcpy(&contacts[i], &contacts[i + 1], sizeof(Contact));
        }
        num_contacts--;
    } else {
        printf("Invalid contact index.\n");
    }
}

void print_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].number);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add contact\n2. Edit contact\n3. Delete contact\n4. Print contacts\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                edit_contact();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                print_contacts();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);
    return 0;
}