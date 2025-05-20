//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct{
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Contact;

void addContact(Contact* contacts, int numContacts, char* name, char* email){
    if(numContacts == 0){
        printf("No contacts found.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter email: ");
    scanf("%s", email);

    strcpy(contacts[numContacts-1].name, name);
    strcpy(contacts[numContacts-1].email, email);
}

void removeContact(Contact* contacts, int numContacts){
    if(numContacts == 0){
        printf("No contacts found.\n");
        return;
    }

    printf("Enter name of contact to remove: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    int i;
    for(i=0; i<numContacts; i++){
        if(strcmp(contacts[i].name, name) == 0){
            printf("Removing %s from the list.\n", name);
            memmove(&contacts[i], &contacts[i+1], sizeof(Contact)*(numContacts-i-1));
            numContacts--;
            break;
        }
    }
}

void displayContacts(Contact* contacts, int numContacts){
    if(numContacts == 0){
        printf("No contacts found.\n");
        return;
    }

    printf("Name\tEmail\n");
    for(int i=0; i<numContacts; i++){
        printf("%s\t%s\n", contacts[i].name, contacts[i].email);
    }
}

int main(){
    Contact contacts[100];
    int numContacts = 0;

    while(1){
        printf("\n1. Add contact\n2. Remove contact\n3. Display contacts\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addContact(contacts, numContacts, "", "");
                break;
            case 2:
                removeContact(contacts, numContacts);
                break;
            case 3:
                displayContacts(contacts, numContacts);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}