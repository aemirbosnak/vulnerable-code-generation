//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 30
#define MAX_PHONE_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} Contact;

int main() {
    Contact phonebook[MAX_CONTACTS];
    int num_contacts = 0;
    char choice;

    do {
        printf("\nPhone Book\n");
        printf("-------------\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. View all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_contacts >= MAX_CONTACTS) {
                    printf("Phone book is full. Cannot add more contacts.\n");
                } else {
                    printf("Enter name: ");
                    scanf("%s", phonebook[num_contacts].name);
                    printf("Enter phone number: ");
                    scanf("%s", phonebook[num_contacts].phone_number);
                    num_contacts++;
                    printf("Contact added successfully.\n");
                }
                break;

            case '2':
                printf("Enter name to search: ");
                char search_name[MAX_NAME_LENGTH];
                scanf("%s", search_name);
                for(int i=0; i<num_contacts; i++) {
                    if(strcmp(phonebook[i].name, search_name) == 0) {
                        printf("Name: %s\n", phonebook[i].name);
                        printf("Phone number: %s\n", phonebook[i].phone_number);
                    }
                }
                break;

            case '3':
                printf("Phone Book\n");
                printf("-------------\n");
                for(int i=0; i<num_contacts; i++) {
                    printf("Name: %s\n", phonebook[i].name);
                    printf("Phone number: %s\n", phonebook[i].phone_number);
                }
                break;

            case '4':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= '4');

    return 0;
}