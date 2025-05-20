//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Contact;

int main() {
    Contact phonebook[MAX_CONTACTS];
    int num_contacts = 0;
    char choice;
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];

    do {
        printf("Phone Book\n");
        printf("---------------------\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Display All Contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
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
                printf("Enter name to search: ");
                scanf("%s", name);
                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(phonebook[i].name, name) == 0) {
                        printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
                    }
                }
                break;
            case '3':
                printf("Enter name to edit: ");
                scanf("%s", name);
                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(phonebook[i].name, name) == 0) {
                        printf("Enter new number: ");
                        scanf("%s", number);
                        strcpy(phonebook[i].number, number);
                        printf("Contact updated successfully.\n");
                        break;
                    }
                }
                break;
            case '4':
                printf("Enter name to delete: ");
                scanf("%s", name);
                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(phonebook[i].name, name) == 0) {
                        memset(phonebook[i].name, '\0', MAX_NAME_LEN);
                        memset(phonebook[i].number, '\0', MAX_NUMBER_LEN);
                        printf("Contact deleted successfully.\n");
                        break;
                    }
                }
                break;
            case '5':
                printf("Phone Book\n");
                printf("---------------------\n");
                for(int i=0; i<num_contacts; i++) {
                    printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
                }
                break;
            case '6':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= '6');

    return 0;
}