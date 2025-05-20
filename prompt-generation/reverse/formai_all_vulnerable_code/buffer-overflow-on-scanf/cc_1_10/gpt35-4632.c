//FormAI DATASET v1.0 Category: Phone Book ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Contact{
    char name[30];
    char phoneNumber[15];
    char email[50];
};

typedef struct Contact Contact;

void addContact(Contact* contactList, int* size);
void displayContacts(Contact* contactList, int size);
void searchContacts(Contact* contactList, int size);
void deleteContact(Contact* contactList, int* size);

int main(){

    int size = 0;
    int choice = 0;

    Contact* contactList = malloc(size * sizeof(Contact));

    printf("********** C PHONE BOOK **********\n");

    do{
        printf("\nWhat would you like to do?\n");
        printf("1. Add a Contact\n");
        printf("2. Display all Contacts\n");
        printf("3. Search for a Contact\n");
        printf("4. Delete a Contact\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: addContact(contactList, &size);
                    break;

            case 2: displayContacts(contactList, size);
                    break;

            case 3: searchContacts(contactList, size);
                    break;

            case 4: deleteContact(contactList, &size);
                    break;

            case 5: printf("\nThank you for using C Phone Book.\n\n");
                    break;

            default: printf("\nInvalid Input. Please try again.\n");
                     break;
        }

      }while(choice != 5);

      free(contactList);

      return 0;
}

void addContact(Contact* contactList, int* size){

    char tempName[30];
    char tempPhoneNumber[15];
    char tempEmail[50];

    printf("\nEnter the name of the contact: ");
    scanf("%s", tempName);

    printf("Enter the phone number of the contact: ");
    scanf("%s", tempPhoneNumber);

    printf("Enter the email address of the contact: ");
    scanf("%s", tempEmail);

    Contact tempContact = {0};
    strcpy(tempContact.name, tempName);
    strcpy(tempContact.phoneNumber, tempPhoneNumber);
    strcpy(tempContact.email, tempEmail);

    contactList = (Contact*) realloc(contactList, (*size + 1) * sizeof(Contact));
    contactList[*size] = tempContact;
    (*size)++;

    printf("\nThe contact has been added successfully.\n");
}

void displayContacts(Contact* contactList, int size){

    printf("\n");

    if(size == 0)
        printf("The phone book is empty.\n");
    else{
        printf("Name\t\tPhone Number\t\tEmail\n");

        for(int i = 0; i < size; i++){
            printf("%s\t\t%s\t\t%s\n", contactList[i].name, contactList[i].phoneNumber, contactList[i].email);
        }
    }
}

void searchContacts(Contact* contactList, int size){

    char searchName[30];
    int found = 0;

    printf("\nEnter the name of the contact you want to search: ");
    scanf("%s", searchName);

    printf("\n");

    for(int i = 0; i < size; i++){
        if(strcmp(contactList[i].name, searchName) == 0){
            found = 1;
            printf("Name\t\tPhone Number\t\tEmail\n");
            printf("%s\t\t%s\t\t%s\n", contactList[i].name, contactList[i].phoneNumber, contactList[i].email);
            break;
        }
    }

    if(!found)
        printf("The contact could not be found.\n");
}

void deleteContact(Contact* contactList, int* size){

    char deleteName[30];
    int found = 0;

    printf("\nEnter the name of the contact you want to delete: ");
    scanf("%s", deleteName);

    for(int i = 0; i < *size; i++){
        if(strcmp(contactList[i].name, deleteName) == 0){
            found = 1;

            for(int j = i; j < (*size - 1); j++){
                contactList[j] = contactList[j+1];
            }

            *size = (*size) - 1;
            printf("\nThe contact has been deleted successfully.\n");
            break;
        }
    }

    if(!found)
        printf("The contact could not be deleted.\n");
}