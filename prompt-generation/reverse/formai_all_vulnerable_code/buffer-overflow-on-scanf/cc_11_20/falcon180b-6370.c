//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

int main() {
    int choice, num_contacts = 0;
    contact contacts[100];

    printf("Welcome to the mailing list manager!\n");
    while(1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add a contact\n");
        printf("2. Remove a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_contacts >= 100) {
                    printf("Sorry, you cannot add more than 100 contacts.\n");
                    break;
                }
                printf("Enter the name of the contact: ");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter the email of the contact: ");
                scanf("%s", contacts[num_contacts].email);
                num_contacts++;
                printf("\nContact added successfully.\n");
                break;
            case 2:
                if(num_contacts == 0) {
                    printf("No contacts to remove.\n");
                    break;
                }
                printf("Enter the name of the contact to remove: ");
                scanf("%s", contacts[num_contacts-1].name);
                if(strcmp(contacts[num_contacts-1].name, contacts[0].name)!= 0) {
                    printf("Contact not found.\n");
                } else {
                    printf("\nContact removed successfully.\n");
                    num_contacts--;
                }
                break;
            case 3:
                if(num_contacts == 0) {
                    printf("No contacts to display.\n");
                    break;
                }
                printf("\nName\tEmail\n");
                for(int i=0; i<num_contacts; i++) {
                    printf("%s\t%s\n", contacts[i].name, contacts[i].email);
                }
                break;
            case 4:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}