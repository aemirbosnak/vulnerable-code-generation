//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    char email[MAX_SIZE];
} contact;

contact mailing_list[MAX_SIZE];
int num_contacts = 0;

void add_contact(char *name, char *email) {
    strcpy(mailing_list[num_contacts].name, name);
    strcpy(mailing_list[num_contacts].email, email);
    num_contacts++;
}

void remove_contact(char *email) {
    int i;
    for(i=0; i<num_contacts; i++) {
        if(strcmp(mailing_list[i].email, email) == 0) {
            num_contacts--;
            break;
        }
    }
}

void print_contacts() {
    int i;
    printf("Contact List:\n");
    for(i=0; i<num_contacts; i++) {
        printf("Name: %s, Email: %s\n", mailing_list[i].name, mailing_list[i].email);
    }
}

int main() {
    int choice;
    while(1) {
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Print Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", mailing_list[num_contacts].name);
                printf("Enter email: ");
                scanf("%s", mailing_list[num_contacts].email);
                num_contacts++;
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", mailing_list[num_contacts-1].email);
                remove_contact(mailing_list[num_contacts-1].email);
                break;
            case 3:
                print_contacts();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}