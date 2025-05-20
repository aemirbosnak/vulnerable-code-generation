//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CONTACTS 500
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 16

typedef struct contact{
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
}Contact;

void addContact(Contact *contacts, int *numContacts){
    printf("Enter name: ");
    scanf("%s", contacts[*numContacts].name);
    printf("Enter number: ");
    scanf("%s", contacts[*numContacts].number);
    (*numContacts)++;
}

void displayContacts(Contact *contacts, int numContacts){
    printf("Name\t\tNumber\n");
    for(int i=0; i<numContacts; i++){
        printf("%s\t\t%s\n", contacts[i].name, contacts[i].number);
    }
}

int main(){
    Contact contacts[MAX_CONTACTS];
    int numContacts=0;
    int choice;
    do{
        printf("\nPhone Book\n1. Add contact\n2. Display contacts\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=3);
    return 0;
}