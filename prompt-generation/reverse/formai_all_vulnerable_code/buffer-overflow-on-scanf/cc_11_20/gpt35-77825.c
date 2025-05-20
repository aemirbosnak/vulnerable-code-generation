//FormAI DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's create a struct for our email contact list
typedef struct{
    char name[50];
    char email[50];
} EmailContact;

// Let's define the size of our email list
#define LIST_SIZE 100

int main(void)
{
    // Let's create an array to store our email contacts
    EmailContact emailList[LIST_SIZE];

    // Let's create a variable to hold the number of email contacts currently in our list
    int numContacts = 0;

    // Let's create a menu to interact with our email contact list
    int option = 0;
    while (option != 4){
        printf("\n**************************************************");
        printf("\n       WELCOME TO THE MAILING LIST MANAGER         ");
        printf("\n**************************************************");
        printf("\n 1 - Add a new contact");
        printf("\n 2 - Display all contacts");
        printf("\n 3 - Search for a contact");
        printf("\n 4 - Quit");
        printf("\n\nPlease enter your option: ");

        scanf("%d", &option);

        // Let's validate the user's input
        if (option < 1 || option > 4){
            printf("\nInvalid option, please try again!");
            continue;
        }

        // Let's handle the user's input accordingly
        switch(option){
            case 1:{
                printf("\nEnter the name of the contact: ");
                scanf("%s", emailList[numContacts].name);

                printf("\nEnter the email of the contact: ");
                scanf("%s", emailList[numContacts].email);

                numContacts++;

                printf("\nContact added successfully!");
                break;
            }
            case 2:{
                if (numContacts == 0){
                    printf("\nNo contacts found!");
                } else {
                    printf("\n**************************************\n");
                    printf("           EMAIL CONTACT LIST          \n");
                    printf("**************************************\n");

                    for (int i=0; i<numContacts; i++){
                        printf("\nContact #%d:\n", (i+1));
                        printf("\tName: %s\n", emailList[i].name);
                        printf("\tEmail: %s\n", emailList[i].email);
                    }
                }
                break;
            }
            case 3:{
                char searchName[50];
                printf("\nEnter the name of the contact you want to search: ");
                scanf("%s", searchName);

                int found = 0;
                for (int i=0; i<numContacts; i++){
                    if (strcmp(emailList[i].name, searchName) == 0){
                        printf("\nContact found:\n");
                        printf("\tName: %s\n", emailList[i].name);
                        printf("\tEmail: %s\n", emailList[i].email);
                        found = 1;
                        break;
                    }
                }
                if (found == 0){
                    printf("\nContact not found!");
                }
                break;
            }
            case 4:{
                printf("\nThank you for using the mailing list manager! Have a nice day!");
                break;
            }
        }
    }

    return 0;
}