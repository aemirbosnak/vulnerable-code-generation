//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

int num_contacts = 0;
Contact contacts[MAX_CONTACTS];

void add_contact() {
    printf("Enter the name of the contact: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter the phone number of the contact: ");
    scanf("%s", contacts[num_contacts].number);
    num_contacts++;
}

void search_contact() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter the name of the contact to search: ");
    scanf("%s", search_name);
    int i;
    for(i = 0; i < num_contacts; i++) {
        if(strcmp(contacts[i].name, search_name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Number: %s\n", contacts[i].number);
        }
    }
}

void delete_contact() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", search_name);
    int i;
    for(i = 0; i < num_contacts; i++) {
        if(strcmp(contacts[i].name, search_name) == 0) {
            num_contacts--;
            memmove(&contacts[i], &contacts[i+1], sizeof(Contact) * (num_contacts - i - 1));
            break;
        }
    }
}

void print_contacts() {
    int i;
    for(i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Number: %s\n", contacts[i].number);
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Delete contact\n");
        printf("4. Print contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                print_contacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(1);
    return 0;
}