//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 1000
#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

int main() {
    int choice, i;
    contact mailing_list[MAX_LIST_SIZE];
    int num_contacts = 0;

    printf("Welcome to the Curious Mailing List Manager!\n\n");

    while(1) {
        printf("\nPlease select an option:\n");
        printf("1. Add a contact\n");
        printf("2. Remove a contact\n");
        printf("3. View all contacts\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_contacts >= MAX_LIST_SIZE) {
                    printf("Sorry, the mailing list is full.\n");
                } else {
                    printf("Enter the name of the contact:\n");
                    scanf("%s", mailing_list[num_contacts].name);

                    printf("Enter the email of the contact:\n");
                    scanf("%s", mailing_list[num_contacts].email);

                    num_contacts++;
                    printf("Contact added successfully!\n");
                }
                break;

            case 2:
                if(num_contacts == 0) {
                    printf("Sorry, the mailing list is empty.\n");
                } else {
                    printf("Enter the name of the contact to remove:\n");
                    scanf("%s", mailing_list[0].name);

                    for(i=0; i<num_contacts; i++) {
                        if(strcmp(mailing_list[i].name, mailing_list[0].name) == 0) {
                            num_contacts--;
                            break;
                        }
                    }

                    if(i == num_contacts) {
                        printf("Contact not found.\n");
                    } else {
                        printf("Contact removed successfully!\n");
                    }
                }
                break;

            case 3:
                if(num_contacts == 0) {
                    printf("Sorry, the mailing list is empty.\n");
                } else {
                    printf("Mailing List:\n");
                    for(i=0; i<num_contacts; i++) {
                        printf("%s - %s\n", mailing_list[i].name, mailing_list[i].email);
                    }
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option selected.\n");
        }
    }

    return 0;
}