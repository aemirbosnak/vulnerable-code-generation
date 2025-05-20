//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

int main() {
    char choice;
    int num_contacts = 0;
    Contact contacts[MAX_CONTACTS];

    do {
        system("clear");
        printf("Phone Book\n");
        printf("A - Add contact\n");
        printf("S - Search contact\n");
        printf("D - Delete contact\n");
        printf("Q - Quit\n");
        scanf("%c", &choice);

        switch(choice) {
            case 'A':
                if(num_contacts == MAX_CONTACTS) {
                    printf("Contact list is full.\n");
                } else {
                    printf("Enter name: ");
                    scanf("%s", contacts[num_contacts].name);
                    printf("Enter number: ");
                    scanf("%s", contacts[num_contacts].number);
                    num_contacts++;
                    printf("Contact added.\n");
                }
                break;

            case 'S':
                printf("Enter name to search: ");
                char search_name[MAX_NAME_LENGTH];
                scanf("%s", search_name);

                int found = 0;
                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(contacts[i].name, search_name) == 0) {
                        printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
                        found = 1;
                    }
                }

                if(!found) {
                    printf("Contact not found.\n");
                }
                break;

            case 'D':
                printf("Enter name to delete: ");
                char delete_name[MAX_NAME_LENGTH];
                scanf("%s", delete_name);

                int index = -1;
                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(contacts[i].name, delete_name) == 0) {
                        index = i;
                        break;
                    }
                }

                if(index!= -1) {
                    for(int i=index; i<num_contacts-1; i++) {
                        strcpy(contacts[i].name, contacts[i+1].name);
                        strcpy(contacts[i].number, contacts[i+1].number);
                    }
                    num_contacts--;
                    printf("Contact deleted.\n");
                } else {
                    printf("Contact not found.\n");
                }
                break;

            case 'Q':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 'Q');

    return 0;
}