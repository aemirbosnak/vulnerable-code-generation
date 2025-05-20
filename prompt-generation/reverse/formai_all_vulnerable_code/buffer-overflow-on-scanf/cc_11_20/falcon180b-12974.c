//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct contact_t {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} contact_t;

int main() {
    contact_t phonebook[MAX_CONTACTS];
    int num_contacts = 0;
    char choice;
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    do {
        printf("Phone Book\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Number: ");
                scanf("%s", number);

                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(phonebook[i].name, name) == 0) {
                        printf("Contact already exists.\n");
                        break;
                    }
                }

                if(num_contacts >= MAX_CONTACTS) {
                    printf("Phone book is full.\n");
                } else {
                    strcpy(phonebook[num_contacts].name, name);
                    strcpy(phonebook[num_contacts].number, number);
                    num_contacts++;
                    printf("Contact added successfully.\n");
                }
                break;

            case '2':
                printf("Enter Name to Search: ");
                scanf("%s", name);

                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(phonebook[i].name, name) == 0) {
                        printf("Name: %s\n", phonebook[i].name);
                        printf("Number: %s\n", phonebook[i].number);
                    }
                }
                break;

            case '3':
                printf("Enter Name to Delete: ");
                scanf("%s", name);

                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(phonebook[i].name, name) == 0) {
                        for(int j=i; j<num_contacts-1; j++) {
                            strcpy(phonebook[j].name, phonebook[j+1].name);
                            strcpy(phonebook[j].number, phonebook[j+1].number);
                        }
                        num_contacts--;
                        printf("Contact deleted successfully.\n");
                        break;
                    }
                }
                break;

            case '4':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '4');

    return 0;
}