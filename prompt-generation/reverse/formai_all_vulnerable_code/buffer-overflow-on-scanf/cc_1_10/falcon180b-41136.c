//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

int main() {
    int choice, i;
    char input[100];
    Contact contacts[100];
    int num_contacts = 0;

    printf("Welcome to the mailing list manager!\n\n");

    while(1) {
        printf("Please choose an option:\n");
        printf("1. Add a contact\n");
        printf("2. Remove a contact\n");
        printf("3. View all contacts\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the contact: ");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter the email of the contact: ");
                scanf("%s", contacts[num_contacts].email);
                num_contacts++;
                printf("\nContact added successfully!\n");
                break;
            case 2:
                printf("Enter the name of the contact to remove: ");
                scanf("%s", input);
                for(i=0; i<num_contacts; i++) {
                    if(strcmp(input, contacts[i].name) == 0) {
                        memmove(&contacts[i], &contacts[i+1], sizeof(Contact) * (num_contacts - i - 1));
                        num_contacts--;
                        printf("\nContact removed successfully!\n");
                        break;
                    }
                }
                break;
            case 3:
                printf("\nAll contacts:\n");
                for(i=0; i<num_contacts; i++) {
                    printf("%s - %s\n", contacts[i].name, contacts[i].email);
                }
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid option!\n");
        }
    }

    return 0;
}