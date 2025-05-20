//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

int num_contacts;
Contact contacts[MAX_CONTACTS];

void add_contact() {
    printf("Enter name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[num_contacts].phone);
    num_contacts++;
}

void display_contacts() {
    printf("\nPhone Book:\n");
    printf("Name\t\tPhone Number\n");
    for(int i=0; i<num_contacts; i++) {
        printf("%s\t\t%s\n", contacts[i].name, contacts[i].phone);
    }
}

void search_contact() {
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    int found = 0;
    for(int i=0; i<num_contacts; i++) {
        if(strcmp(name, contacts[i].name) == 0) {
            printf("\nName: %s\nPhone Number: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("\nContact not found.\n");
    }
}

int main() {
    num_contacts = 0;
    while(1) {
        printf("\n1. Add contact\n2. Display contacts\n3. Search contact\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}